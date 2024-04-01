cmake_minimum_required(VERSION 3.10)
project(Linked_List_Visualizer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(CREATE_LINK "${PROJECT_BINARY_DIR}/compile_commands.json"
     "${PROJECT_SOURCE_DIR}/compile_commands.json" SYMBOLIC)

set(SOURCES src/main.cpp src/nodeptr-shape.cpp src/arrow-shape.cpp)
add_executable(Main ${SOURCES})

# Getting SFML packages
find_package(
  SFML 2.5
  COMPONENTS graphics audio
  REQUIRED)

target_include_directories(Main PRIVATE include)

target_link_libraries(Main PUBLIC sfml-graphics sfml-window sfml-system
                                  sfml-audio)
