#include "GlyptoCore/EntryPoint.h"

class Testbed : public Glypto::Application
{

public:
    using Application::Application;
    ~Testbed() {}
};

Glypto::Application *CreateApplication()
{
    return new Testbed("Glypto App", 800, 600);
}