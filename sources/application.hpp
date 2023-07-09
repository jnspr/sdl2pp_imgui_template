#pragma once

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Renderer.hh>

#include <imgui.h>

class Application {
public:
    Application();
    ~Application();

    void run();

private:
    SDL2pp::SDL   m_sdl;
    bool          m_keep_running;
    ImGuiContext *m_imgui_context;

    void poll_events();

protected:
    SDL2pp::Window   window;
    SDL2pp::Renderer renderer;

    virtual void on_event(const SDL_Event *event) = 0;
    virtual void on_process() = 0;
    virtual void on_draw() = 0;
    virtual void on_gui() = 0;
};
