cmake_minimum_required(VERSION 3.0.2)
project(test_pkg)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(
    include
    qf
)

file(GLOB MY_LIB
include/*.hpp
include/*.h
include/*.cpp
qf/*.cpp
)

add_executable(main
main.cpp ${MY_LIB}
)

target_link_libraries(main PRIVATE Threads::Threads)