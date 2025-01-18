#include "GlyptoCore/EntryPoint.h"

class Testbed : public Glypto::Application
{

public:
    Testbed() {}
    ~Testbed() {}

};

Glypto::Application* CreateApplication()
{
    return new Testbed();
}