#pragma once
#include <forward_list>

namespace Glypto
{
    enum class EventType : uint8_t
    {
        EVENT_APPLICATION_QUIT = 0x0,
        EVENT_APPLICATION_RESIZE_WINDOW,
        EVENT_INPUT_KEYDOWN,
        EVENT_INPUT_KEYUP,
        EVENT_INPUT_MOUSE_BTNDOWN,
        EVENT_INPUT_MOUSE_BTNUP,
        EVENT_INPUT_MOUSE_MOTION
    };

    typedef struct Event
    {
        EventType type;
        uint8_t handled = 0;
        union
        {
            int32_t keycode;
            int32_t mouse_pos[2];
            uint8_t mouse_btn;
        };
    } Event;

    class EventObserver
    {
    public:
        virtual ~EventObserver() {};
        virtual void OnNotify(Event &event) = 0;
    };

    class EventSubject
    {
    public:
        virtual ~EventSubject() {};

        void AddObserver(EventObserver *observer)
        {
            m_Observers.push_front(observer);
        }

        void RemoveObserver(EventObserver *observer)
        {
            m_Observers.remove(observer);
        }

        void NotifyAll(Event &event)
        {
            for (EventObserver *observer : m_Observers)
            {
                if(event.handled) break;
                observer->OnNotify(event);
            }
        }

    protected:
    
        std::forward_list<EventObserver *> m_Observers;
    };
}