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
        const Uint8* current_keystate;
        const Uint8* prev_keystate;
        int key_array_size;
    } Input;

    class GLYPTO_API InputManager : public EventSubject
    {
    public:
        InputManager();
        ~InputManager();

        void UpdatePrevState();

        // EventSubject overridable functions
        void NotifyAll(Event e) override;

        Input m_Input;

    private:
    };
}