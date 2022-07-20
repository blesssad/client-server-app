cmake_minimum_required(VERSION 3.22.1)

project(client-server)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/monday.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(tests)

add_library(client-server STATIC src/server.cpp src/server_functions.hpp src/error.hpp)


add_executable(server src/server.cpp src/server_functions.hpp src/error.hpp )
add_executable(client src/client.cpp src/error.hpp)


