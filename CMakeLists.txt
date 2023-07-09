cmake_minimum_required(VERSION 3.16)
project(sdl2_imgui_cpp LANGUAGES CXX)

set(SDL2PP_STATIC TRUE)
set(SDL2PP_WITH_IMAGE TRUE)
set(SDL2PP_WITH_MIXER FALSE)
set(SDL2PP_WITH_TTF FALSE)
add_subdirectory(external/libSDL2pp)

add_executable(${PROJECT_NAME})
add_subdirectory(sources)
target_link_libraries(${PROJECT_NAME} SDL2pp::SDL2pp)
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE ON)
