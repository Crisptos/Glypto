#include "GlyptoCore/EntryPoint.h"

class Testbed : public Glypto::Application
{

public:
    using Application::Application;
    ~Testbed() {}

    // Overrides
    void Application::OnNotify(Glypto::Event& event) override;
};

void Testbed::OnNotify(Glypto::Event &event)
    {
        switch (event.type)
        {
        case Glypto::EventType::EVENT_APPLICATION_QUIT:
        {
            Glypto::Logger::GLYPTO_INFO("Quitting application...");
            Testbed::Application::Shutdown();
            event.handled = SDL_TRUE;
            break;
        }

        case Glypto::EventType::EVENT_INPUT_KEYDOWN:
        {
            Glypto::Logger::GLYPTO_INFO("Key %c was pressed...", event.keycode);

            // TODO - Test Input
            switch(event.keycode)
            {
                case 100:
                    glm::vec3 pos = Testbed::Application::test_cam.GetPosition();
                    pos.x += 4.0f;
                    test_cam.SetPosition(pos);
                break;
            }

            event.handled = SDL_TRUE;
            break;
        }

        case Glypto::EventType::EVENT_INPUT_KEYUP:
        {
            Glypto::Logger::GLYPTO_INFO("Key %c was released...", event.keycode);
            event.handled = SDL_TRUE;
            break;
        }

        case Glypto::EventType::EVENT_INPUT_MOUSE_BTNDOWN:
        {
            Glypto::Logger::GLYPTO_INFO("Mouse Btn %d was pressed...", event.mouse_btn);
            event.handled = SDL_TRUE;
            break;
        }

        case Glypto::EventType::EVENT_INPUT_MOUSE_BTNUP:
        {
            Glypto::Logger::GLYPTO_INFO("Mouse Btn %d was released...", event.mouse_btn);
            event.handled = SDL_TRUE;
            break;
        }

        case Glypto::EventType::EVENT_INPUT_MOUSE_MOTION:
        {
            Glypto::Logger::GLYPTO_INFO("Mouse Pos is (X: %d, Y: %d)...", event.mouse_pos[0], event.mouse_pos[1]);
            event.handled = SDL_TRUE;
            break;
        }
        }
    }

Glypto::Application *CreateApplication()
{
    return new Testbed("Glypto App", 800, 600);
}