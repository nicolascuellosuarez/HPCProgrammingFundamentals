cmake_minimum_required(VERSION 4.1)
project(TP1_HPC C)

set(CMAKE_C_STANDARD 11)

find_package(OpenMP REQUIRED)

file(GLOB PROGRAMS "*.c")

foreach(program ${PROGRAMS})
    get_filename_component(program_name ${program} NAME_WE)
    add_executable(${program_name} ${program})
    target_link_libraries(${program_name} PRIVATE OpenMP::OpenMP_C m)
endforeach()
