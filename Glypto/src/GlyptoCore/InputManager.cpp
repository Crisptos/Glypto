#include "GlyptoCore/InputManager.h"

namespace Glypto
{
    Input InputManager::s_Input;

    void InputManager::InitializeInputManager()
    {
        s_Input.current_keystate = SDL_GetKeyboardState(&s_Input.key_array_size);
        if(!s_Input.key_array_size)
        {
            Logger::GLYPTO_CRITICAL("Unable to retrieve key array size from SDL!");
            exit(-1);
        }

        s_Input.prev_keystate = (Uint8*)calloc(s_Input.key_array_size, sizeof(Uint8));
    }

    InputManager::~InputManager()
    {
        free((Uint8*)s_Input.prev_keystate);
    }

    void InputManager::UpdatePrevState()
    {
        std::memcpy(const_cast<Uint8*>(s_Input.prev_keystate), s_Input.current_keystate, sizeof(s_Input.key_array_size));
    }

    void InputManager::AddObserver(EventObserver *observer)
    {

    }

    void InputManager::RemoveObserver(EventObserver *observer) 
    {

    }

    void InputManager::NotifyAll()
    {

    }
}