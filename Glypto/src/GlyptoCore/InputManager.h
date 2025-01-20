#pragma once
#include <cstring>
#include <memory>
#include "SDL2/SDL.h"
#include "GlyptoCore/Logger.h"
#include "GlyptoCore/EventSubject.h"

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
        static void InitializeInputManager(); // SDL must be initialized before Input!
        ~InputManager();

        static Input* GetInputState() {return &s_Input; };
        static void UpdatePrevState();

        // EventSubject overridable functions
        void AddObserver(EventObserver *observer) override;
        void RemoveObserver(EventObserver *observer) override;
        void NotifyAll() override;

    private:
        static Input s_Input;
    };
}