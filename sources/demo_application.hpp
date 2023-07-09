#include "application.hpp"

class DemoApplication: public Application {
public:
    DemoApplication();

private:
    bool  m_clear_bg;
    float m_bg_color[3];

    void on_draw();
    void on_gui();

};
