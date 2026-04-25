cmake_minimum_required(VERSION 3.16)
project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(lab1_library
    src/rect.cpp
    src/my_string.cpp
    src/barrel.cpp
    src/matrix.cpp
    src/text_wrapper.cpp
)
target_include_directories(lab1_library PUBLIC src)

add_executable(lab1 src/lab1.cpp)
target_link_libraries(lab1 PRIVATE lab1_library)

enable_testing()
add_subdirectory(tests)