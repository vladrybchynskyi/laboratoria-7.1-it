cmake_minimum_required(VERSION 3.30.5)

set(This labor7_1test)

set(Sources
   labor7_1test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    laborw7_1
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
