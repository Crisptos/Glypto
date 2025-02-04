#pragma once
#include <cstring>
#include <memory>
#include "SDL2/SDL.h"
#include "GlyptoCore/Logger.h"
#include "GlyptoCore/Event.h"

namespace Glypto
{
    typedef struct Input
    {   // TODO - For now only support ASCII, add more key codes later
        uint8_t current_keystate[128];
        uint8_t prev_keystate[128];
        // ------
        uint8_t current_mousebtn_state[12];
        uint8_t prev_mousebtn_state[12];
        // ------
        int32_t current_mouse_x;
        int32_t current_mouse_y;
        int32_t prev_mouse_x;
        int32_t prev_mouse_y;
    } Input;

    class GLYPTO_API InputManager : public EventSubject
    {
    public:
        InputManager() {};
        ~InputManager() {};

        void ProcessInput();
        void UpdatePrevState();

    private:
        void ProcessInputKeys(SDL_Keycode keycode, uint8_t is_keydown);
        void ProcessInputMouseButtons(uint8_t mouse_btn, uint8_t is_btn_down);
        void ProcessInputMousePosition(int32_t mouse_x, int32_t mouse_y);
        static Input s_Input;
    };
}