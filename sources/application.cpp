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

void Application::run() {
    while (m_keep_running) {
        on_process();
        on_draw();

        ImGui_ImplSDL2_NewFrame();
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui::NewFrame();

        on_gui();

        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
        renderer.Present();

        poll_events();
    }
}

void Application::poll_events() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                m_keep_running = false;
                return;
            case SDL_MOUSEMOTION:
            case SDL_MOUSEWHEEL:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                if (!ImGui::GetIO().WantCaptureMouse) {
                    on_event(&event);
                }
                break;
            case SDL_TEXTINPUT:
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                if (!ImGui::GetIO().WantCaptureKeyboard) {
                    on_event(&event);
                }
                break;
            default:
                on_event(&event);
                break;
        }
    }
}
