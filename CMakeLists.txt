set(SOURCES src/main.cpp src/nodeptr-shape.cpp src/arrow-shape.cpp)
add_library(Nodes ${SOURCES})

target_include_directories(Nodes PRIVATE include)

target_link_libraries(Nodes PUBLIC sfml-graphics sfml-window sfml-system
                                  sfml-audio)
