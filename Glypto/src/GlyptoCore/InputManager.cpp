#include "GlyptoCore/InputManager.h"

namespace Glypto
{
    Input InputManager::s_Input;

    void InputManager::ProcessInput()
    {
        SDL_Event sdl_event;
        while(SDL_PollEvent(&sdl_event))
        {
            switch(sdl_event.type)
            {
                case SDL_QUIT:
                {
                    Event event;
                    event.type = EVENT_APPLICATION_QUIT;
                    NotifyAll(event);
                    break;
                }

                case SDL_KEYDOWN:
                {
                    ProcessInputKeys(sdl_event.key.keysym.sym, SDL_TRUE);
                    break;
                }

                case SDL_KEYUP:
                {
                    ProcessInputKeys(sdl_event.key.keysym.sym, SDL_FALSE);
                    break;
                }

                default:
                    break;
            }
        }
    }

    void InputManager::ProcessInputKeys(SDL_Keycode keycode, uint8_t is_keydown)
    {
        if(s_Input.current_keystate[keycode] != is_keydown)
        {
            s_Input.current_keystate[keycode] = is_keydown;

            Event event;
            event.type = is_keydown ? EVENT_INPUT_KEYDOWN : EVENT_INPUT_KEYUP;
            event.keycode = keycode;
            NotifyAll(event);
        }
    }

    void InputManager::ProcessInputMouseButtons()
    {

    }

    void InputManager::ProcessInputMousePosition()
    {

    }

    void InputManager::UpdatePrevState()
    {
        std::memcpy(s_Input.prev_keystate, s_Input.current_keystate, sizeof(s_Input.current_keystate));
    }

    void InputManager::NotifyAll(Event event)
    {
        for(EventObserver* observer : m_Observers)
        {
            observer->OnNotify(event);
        }
    }
}