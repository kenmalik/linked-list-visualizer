cmake_minimum_required(VERSION 3.10)
project(Linked_List_Visualizer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(CREATE_LINK
    "${PROJECT_BINARY_DIR}/compile_commands.json"
    "${PROJECT_SOURCE_DIR}/compile_commands.json"
    SYMBOLIC
)

set(SOURCES src/main.cpp src/arrow-shape.cpp src/nodeptr-shape.cpp src/node-shape.cpp src/data.cpp)
add_executable(Main ${SOURCES})

# Getting re-implemented linked list from repository
include(FetchContent)
FetchContent_Declare(
    linkedlist
    GIT_REPOSITORY https://github.com/kenmalik/linked-list.git
    GIT_TAG 0bfceb8
)
FetchContent_MakeAvailable(linkedlist)

# Getting SFML packages
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_include_directories(Main PRIVATE
    include
    ${linkedlist_SOURCE_DIR}/include
)

target_link_libraries(Main PUBLIC
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

