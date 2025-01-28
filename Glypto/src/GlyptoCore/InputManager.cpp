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

                case SDL_MOUSEBUTTONDOWN:
                {
                    ProcessInputMouseButtons(sdl_event.button.button, SDL_TRUE);
                    break;
                }

                case SDL_MOUSEBUTTONUP:
                {
                    ProcessInputMouseButtons(sdl_event.button.button, SDL_FALSE);
                    break;   
                }

                case SDL_MOUSEMOTION:
                {
                    ProcessInputMousePosition(sdl_event.motion.x, sdl_event.motion.y);
                    break;
                }

                default:
                    break;
            }
        }
    }

    void InputManager::ProcessInputKeys(SDL_Keycode keycode, uint8_t is_keydown)
    {
        if(keycode < 0 || keycode >= 128) return;

        if(s_Input.current_keystate[keycode] != is_keydown)
        {
            s_Input.current_keystate[keycode] = is_keydown;

            Event event;
            event.type = is_keydown ? EVENT_INPUT_KEYDOWN : EVENT_INPUT_KEYUP;
            event.keycode = keycode;
            NotifyAll(event);
        }
    }

    void InputManager::ProcessInputMouseButtons(uint8_t mouse_btn, uint8_t is_btn_down)
    {
        // Bounds check
        if(mouse_btn >= 12) return;

        if(s_Input.current_mousebtn_state[mouse_btn] != is_btn_down)
        {
            s_Input.current_mousebtn_state[mouse_btn] = is_btn_down;

            Event event;
            event.type = is_btn_down ? EVENT_INPUT_MOUSE_BTNDOWN : EVENT_INPUT_MOUSE_BTNUP;
            event.mouse_btn = mouse_btn;
            NotifyAll(event);
        }
    }

    void InputManager::ProcessInputMousePosition(int32_t mouse_x, int32_t mouse_y)
    {
        if(s_Input.current_mouse_x != mouse_x && s_Input.current_mouse_y != mouse_y)
        {
            s_Input.current_mouse_x = mouse_x;
            s_Input.current_mouse_y = mouse_y;

            Event event;
            event.type = EVENT_INPUT_MOUSE_MOTION;
            event.mouse_pos[0] = mouse_x;
            event.mouse_pos[1] = mouse_y;
            NotifyAll(event);
        }
    }

    void InputManager::UpdatePrevState()
    {
        std::memcpy(s_Input.prev_keystate, s_Input.current_keystate, sizeof(s_Input.current_keystate));

        std::memcpy(s_Input.prev_mousebtn_state, s_Input.current_mousebtn_state, sizeof(s_Input.current_mousebtn_state));

        s_Input.prev_mouse_x = s_Input.current_mouse_x;
        s_Input.prev_mouse_y = s_Input.current_mouse_y;
    }

    void InputManager::NotifyAll(Event event)
    {
        for(EventObserver* observer : m_Observers)
        {
            observer->OnNotify(event);
        }
    }
}