#pragma once
#include <forward_list>
#include "GlyptoCore/EventObserver.h"

namespace Glypto
{

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

        virtual void NotifyAll()
        {
            for(EventObserver* observer : m_Observers)
            {
                observer->OnNotify();
            } 
        }

    private:
        std::forward_list<EventObserver*> m_Observers;
    };

}