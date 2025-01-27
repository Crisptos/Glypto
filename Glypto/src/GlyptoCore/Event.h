#pragma once
#include <forward_list>

namespace Glypto
{
    typedef enum EventType
    {
        APPLICATION_QUIT = 0x0,
        INPUT_KEYDOWN,
        INPUT_KEYUP,
    } EventType; 

    typedef struct Event
    {
        EventType event_type;
    } Event;

    class EventObserver
    {
    public:
        virtual ~EventObserver() {};
        virtual void OnNotify(Event e) = 0;
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

        virtual void NotifyAll(Event e)
        {
            
        }

    protected:
        std::forward_list<EventObserver *> m_Observers;
    };
}