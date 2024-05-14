set(SOURCES ../src/nodeptr-shape.cpp ../src/arrow-shape.cpp)
add_executable(Test test.cpp ${SOURCES})
target_include_directories(Test PUBLIC ../include)
target_link_libraries(Test PUBLIC sfml-graphics sfml-window
                                            sfml-system)
