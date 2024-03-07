cmake_minimum_required(VERSION 3.10)
project(Review_Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(CREATE_LINK
    "${PROJECT_BINARY_DIR}/compile_commands.json"
    "${PROJECT_SOURCE_DIR}/compile_commands.json"
    SYMBOLIC
)

add_executable(Main main.cpp)
add_library(arrow-shape arrow-shape.cpp)
add_library(nodeptr-shape nodeptr-shape.cpp)
add_library(node-shape node-shape.cpp)
add_library(data data.cpp)

target_include_directories(Main PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(Main PUBLIC
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    arrow-shape
    nodeptr-shape
    node-shape
    data
)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
