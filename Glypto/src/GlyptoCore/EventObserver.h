#pragma once
#include <string>

namespace Glypto
{
    class EventObserver
    {
    public:
        virtual ~EventObserver();
        virtual void OnNotify() = 0;
    };

}