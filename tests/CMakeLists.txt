add_subdirectory(unity)

add_executable(test_nes_cpu test_cpu.c)
add_executable(test_nes_mem test_mem.c)
add_executable(test_nestest test_nestest.c)

target_link_libraries(test_nes_cpu unity core nooprender)
target_link_libraries(test_nes_mem unity core nooprender)
target_link_libraries(test_nestest unity core nooprender)

add_test(test_nes_cpu test_nes_cpu)
add_test(test_nes_mem test_nes_mem)
add_test(test_nestest test_nestest)

target_include_directories(test_nes_cpu PUBLIC .. src)
target_include_directories(test_nes_mem PUBLIC .. src)
target_include_directories(test_nestest PUBLIC .. src)

configure_file(nestest/nestest.nes nestest.nes COPYONLY)
configure_file(nestest/nestest.log nestest.log COPYONLY)
