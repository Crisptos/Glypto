#pragma once
#include <forward_list>

namespace Glypto
{
    typedef enum EventType
    {
        EVENT_APPLICATION_QUIT = 0x0,
        EVENT_INPUT_KEYDOWN,
        EVENT_INPUT_KEYUP,
        EVENT_INPUT_MOUSE_BTNDOWN,
        EVENT_INPUT_MOUSE_BTNUP,
        EVENT_INPUT_MOUSE_MOTION
    } EventType; 

    typedef struct Event
    {
        EventType type;
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
        virtual void OnNotify(Event event) = 0;
    };

    class EventSubject
    {
    public:
        virtual ~EventSubject() {};

        virtual void AddObserver(EventObserver *observer)
        {
            m_Observers.push_front(observer);
        }

        virtual void RemoveObserver(EventObserver *observer)
        {
            m_Observers.remove(observer);
        }

        virtual void NotifyAll(Event event)
        {
            
        }

    protected:
        std::forward_list<EventObserver *> m_Observers;
    };
}