#include "GlyptoCore/InputManager.h"

namespace Glypto
{
    InputManager::InputManager()
    {
        m_Input.current_keystate = SDL_GetKeyboardState(&m_Input.key_array_size);
        if(!m_Input.key_array_size)
        {
            Logger::GLYPTO_CRITICAL("Unable to retrieve key array size from SDL!");
            exit(-1);
        }

        m_Input.prev_keystate = (Uint8*)calloc(m_Input.key_array_size, sizeof(Uint8));
    }

    InputManager::~InputManager()
    {
        free((Uint8*)m_Input.prev_keystate);
    }

    void InputManager::UpdatePrevState()
    {
        std::memcpy(const_cast<Uint8*>(m_Input.prev_keystate), m_Input.current_keystate, sizeof(m_Input.key_array_size));
    }

    void InputManager::NotifyAll(Event e)
    {
        for(EventObserver* observer : m_Observers)
        {
            observer->OnNotify(e);
        }
    }
}