#pragma once
#define SDL_MAIN_HANDLED
#include "GlyptoCore/Application.h"

extern Glypto::Application* CreateApplication();

int main(int argc, char** argv)
{
    Glypto::Application* client_app = CreateApplication();
    Glypto::Logger::InitializeLogger();
    client_app->Run();
    delete client_app;
    return 0;
}