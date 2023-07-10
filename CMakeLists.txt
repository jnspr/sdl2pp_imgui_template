cmake_minimum_required(VERSION 3.16)
project(sdl2pp_imgui_template LANGUAGES CXX)

set(SDL2PP_STATIC TRUE)
set(SDL2PP_WITH_IMAGE TRUE)
set(SDL2PP_WITH_MIXER FALSE)
set(SDL2PP_WITH_TTF FALSE)
add_subdirectory(external/libSDL2pp)

add_executable(${PROJECT_NAME})
add_subdirectory(sources)
target_link_libraries(${PROJECT_NAME} SDL2pp::SDL2pp)
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE ON)

target_sources(${PROJECT_NAME} PRIVATE
    external/imgui/backends/imgui_impl_sdl2.cpp
    external/imgui/backends/imgui_impl_sdlrenderer2.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE external/imgui)
