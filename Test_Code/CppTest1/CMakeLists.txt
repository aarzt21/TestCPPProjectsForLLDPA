cmake_minimum_required(VERSION 3.25)
project(Test3)

set(CMAKE_CXX_STANDARD 17)

add_library(Foo Foo.cpp)

add_executable(out mock.cpp)

target_link_libraries(out Foo)
