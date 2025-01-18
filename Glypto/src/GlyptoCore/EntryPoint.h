#pragma once
#include "GlyptoCore/Application.h"

extern Glypto::Application* CreateApplication();

int main(int argc, char** argv)
{
    Glypto::Logger::InitializeLogger();
    Glypto::Application* client_app = CreateApplication();
    client_app->Run();
    delete client_app;
    return 0;
}