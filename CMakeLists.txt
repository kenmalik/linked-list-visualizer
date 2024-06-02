cmake_minimum_required(VERSION 3.10)
project(LinkedListVisualizer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(CREATE_LINK "${PROJECT_BINARY_DIR}/compile_commands.json"
     "${PROJECT_SOURCE_DIR}/compile_commands.json" SYMBOLIC)

set(SOURCES src/nodeptr-shape.cpp src/arrow-shape.cpp)
add_library(linked-list-shape ${SOURCES})

add_subdirectory(test)

target_include_directories(linked-list-shape PRIVATE include)

target_link_libraries(linked-list-shape PUBLIC sfml-graphics sfml-window
                                            sfml-system)
