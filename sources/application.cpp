#include "application.hpp"

#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer2.h>

Application::Application():
    m_sdl(SDL_INIT_VIDEO),
    window("sdl2_imgui_cpp",
             SDL_WINDOWPOS_CENTERED,
             SDL_WINDOWPOS_CENTERED,
             1280, 720,
             SDL_WINDOW_RESIZABLE),
    renderer(window, -1, SDL_RENDERER_ACCELERATED),
    m_keep_running(true)
{
    m_imgui_context = ImGui::CreateContext();
    ImGui::SetCurrentContext(m_imgui_context);

    ImGui_ImplSDL2_InitForSDLRenderer(window.Get(), renderer.Get());
    ImGui_ImplSDLRenderer2_Init(renderer.Get());
}

Application::~Application() {
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext(m_imgui_context);
}
