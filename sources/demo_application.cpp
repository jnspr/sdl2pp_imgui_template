#include "demo_application.hpp"

DemoApplication::DemoApplication():
    m_clear_bg(true),
    m_bg_color{1.0, 0.0, 0.0}
{
}

void DemoApplication::on_draw() {
    if (m_clear_bg) {
        renderer.SetDrawColor(m_bg_color[0] * 255.0,
                              m_bg_color[1] * 255.0,
                              m_bg_color[2] * 255.0);
        renderer.Clear();
    }
}

void DemoApplication::on_gui() {
    ImGui::Checkbox("Clear background", &m_clear_bg);
    if (m_clear_bg) {
        ImGui::ColorPicker3("Background color", m_bg_color);
    }
}
