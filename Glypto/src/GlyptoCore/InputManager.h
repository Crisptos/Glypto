#pragma once
#include <cstring>
#include <memory>
#include "SDL2/SDL.h"
#include "GlyptoCore/Logger.h"
#include "GlyptoCore/Event.h"

namespace Glypto
{
    typedef struct Input
    {
        uint8_t current_keystate[SDL_NUM_SCANCODES];
        uint8_t prev_keystate[SDL_NUM_SCANCODES];
    } Input;

    class GLYPTO_API InputManager : public EventSubject
    {
    public:
        InputManager() {};
        ~InputManager() {};

        void ProcessInput();
        void UpdatePrevState();

        // EventSubject overridable functions
        void NotifyAll(Event event) override;

    private:
        void ProcessInputKeys(SDL_Keycode keycode, uint8_t is_keydown);
        void ProcessInputMouseButtons();
        void ProcessInputMousePosition();
        static Input s_Input;
    };
}