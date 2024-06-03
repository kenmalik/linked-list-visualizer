add_executable(LinkedListTest test.cpp application.cpp)

include(FetchContent)

FetchContent_Declare(
  GuiComponents
  GIT_REPOSITORY git@github.com:kenmalik/gui-library.git
  GIT_TAG 2d64cbe9af4c7a4c3d41d160e4b49a156283ed42)

FetchContent_MakeAvailable(GuiComponents)

target_include_directories(
  LinkedListTest PUBLIC include ${GuiComponents_SOURCE_DIR}/include
                        ${LinkedListVisualizer_SOURCE_DIR}/include)

target_link_libraries(
  LinkedListTest PUBLIC sfml-graphics sfml-window sfml-system gui-library
                        linked-list-shape)
