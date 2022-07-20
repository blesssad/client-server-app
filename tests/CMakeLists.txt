cmake_minimum_required(VERSION 3.22.1)

configure_file(../monday.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

set(This tests)
set(Sources test.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    client-server
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
