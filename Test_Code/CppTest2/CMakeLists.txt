
set(CMAKE_CXX_STANDARD 17)

# Create the Calculator library
add_library(Calculator Calculator.cpp)

# Create the main executable
add_executable(main main.cpp)

# Link Calculator to main
target_link_libraries(main Calculator)
