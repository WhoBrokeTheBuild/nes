#include <portaudio.h>
#include <err.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "apu.h"

byte read_apu_register(apu_memory* apu_mem, byte register_num) {

}

byte pulse_duty[4][8] = {
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 1, 1}
};

void write_pulse_register(pulse_oscillator* pulse, int register_num, byte value, int pulsenum) {
    switch (register_num) {
        case 0: {
            pulse->duty_value = (byte)((value & 0b11000000) >> 6);
            break;
        }
        case 1:
            break;
        case 2: {
            pulse->timer_register &= 0b11100000000;
            pulse->timer_register |= value;
            printf("PULSE %d: Timer Low written: Pulse timer is now %d\n", pulsenum, pulse->timer_register);
            break;
        }

        case 3: {
            pulse->timer_register &= 0b00011111111;
            pulse->timer_register |= (value & 0b00000111) << 8;
            printf("PULSE %d: Timer High written: Pulse timer is now %d\n", pulsenum, pulse->timer_register);
            break;
        }
    }
}

void write_apu_register(apu_memory* apu_mem, int register_num, byte value) {
    if (register_num < 0x4) {
        // Pulse 1
        write_pulse_register(&apu_mem->pulse1, register_num % 4, value, 1);
    } else if (register_num < 0x8) {
        // Pulse 2
        write_pulse_register(&apu_mem->pulse2, register_num % 4, value, 2);
    }
    else if (register_num < 0xC) {
        // Triangle
    }
    else if (register_num < 0x10) {
        // Noise
    }
    else if (register_num < 0x14) {
        // DMC
    }
    else if (register_num == 0x15) {
        // Channel enable and length counter status
        //apu_mem->dmc.enable = (value >> 4) == 1;
        //apu_mem->noise.enable = (value >> 3) == 1;
        //apu_mem->triangle.enable = (value >> 2) == 1;
        apu_mem->pulse2.enable = ((value >> 1) & 1) == 1;
        apu_mem->pulse1.enable = (value & 1) == 1;
    }
    else if (register_num == 0x17) {
        // Frame counter
    }
    else {
        printf("WARNING: Unhandled APU register write to 0x%04X\n", (register_num + 0x4000));
    }
}

apu_memory get_apu_mem() {
    apu_memory apu_mem;
    apu_mem.cycle = 0;
    apu_mem.buffer_read_index = 0;
    apu_mem.buffer_write_index = 0;

    apu_mem.pulse1.timer_register = 0;
    apu_mem.pulse2.timer_register = 0;

    apu_mem.pulse1.enable = 0;
    apu_mem.pulse2.enable = 0;

    return apu_mem;
}

float get_pulse_sample(pulse_oscillator* pulse) {
    if (pulse->timer_register < 8 || pulse->enable == false) {
        return 0.0f;
    }
    if (pulse_duty[pulse->duty_value][pulse->duty_step] == 1) {
        return 1.0f;
    }
    else {
        return -1.0f;
    }
}

void step_pulse_timer(pulse_oscillator* pulse) {
    if (pulse->timer_step == 0) {
        pulse->timer_step = pulse->timer_register;
        pulse->duty_step = (byte)((pulse->duty_step + 1) % 8);
    }
    else {
        pulse->timer_step--;
    }
}

void apu_step(apu_memory* apu_mem) {
    double last_cycle = apu_mem->cycle++;
    double this_cycle = apu_mem->cycle;

    if (apu_mem->buffer_write_index - apu_mem->buffer_read_index < 1) {
        printf("Audio buffer underrun detected!\n");
    }

    if (apu_mem->cycle % 2 == 0) { // APU clock is half as fast as CPU
        step_pulse_timer(&apu_mem->pulse1);
        step_pulse_timer(&apu_mem->pulse2);
    }

    if ((int)(last_cycle / APU_STEPS_PER_SAMPLE) != (int)(this_cycle / APU_STEPS_PER_SAMPLE)) {
        // TODO other oscs, and mix them
        float pulse1_sample = get_pulse_sample(&apu_mem->pulse1);
        float pulse2_sample = get_pulse_sample(&apu_mem->pulse2);

        float sample = (0.5f * pulse1_sample) + (0.5f * pulse2_sample);
        sample *= 0.10f;
        apu_mem->buffer[(apu_mem->buffer_write_index++) % APU_RING_BUFFER_SIZE] = sample;
    }

}

// TODO: Put PortAudio stuff into its own file
static int paCallback(const void *inputBuffer, void *outputBuffer,
                      unsigned long framesPerBuffer,
                      const PaStreamCallbackTimeInfo *timeInfo,
                      PaStreamCallbackFlags statusFlags,
                      void *userData) {
    apu_memory* apu_mem = (apu_memory*)userData;
    float* out = (float*)outputBuffer;
    (void) inputBuffer; // Prevent unused variable warning.

    for(uint32_t i = 0; i < framesPerBuffer; i++) {
        // Read sample from ring buffer. While the ring buffer is empty, push zeroes.
        if (apu_mem->buffer_read_index >= apu_mem->buffer_write_index) {
            *out++ = 0.0f;
        }
        else {
            *out++ = apu_mem->buffer[(apu_mem->buffer_read_index++) % APU_RING_BUFFER_SIZE];
        }
    }
    return 0;
}

PaStream* stream;

void apu_init(apu_memory* apu_mem) {
    // TODO: Put PortAudio stuff into its own file
    // Initialize PortAudio
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        errx(EXIT_FAILURE, "Unable to initialize PortAudio: %s", Pa_GetErrorText(err));
    }

    err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, AUDIO_SAMPLE_RATE, 256, paCallback, apu_mem);


    if (err != paNoError) {
        errx(EXIT_FAILURE, "Unable to open PortAudio stream: %s", Pa_GetErrorText(err));
    }

    err = Pa_StartStream(stream);

    if (err != paNoError) {
        errx(EXIT_FAILURE, "Unable to start PortAudio stream: %s", Pa_GetErrorText(err));
    }

}