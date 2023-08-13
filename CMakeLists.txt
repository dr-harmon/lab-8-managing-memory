cmake_minimum_required(VERSION 3.20)

set(TARGET_NAME lab8)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)

project("${TARGET_NAME}" VERSION 1.0 LANGUAGES CXX)

foreach(TARGET stack reference raw_ptr unique_ptr shared_ptr)
    add_library("${TARGET}" src/${TARGET}.cpp)
    include_directories(src src/${TARGET})
    add_executable(${TARGET}_main src/main.cpp)
    target_link_libraries(${TARGET}_main PRIVATE ${TARGET})
endforeach()
