#pragma once

#include "Application.hpp"

extern Pumpkin::Application *Pumpkin::CreateApplication();

int main(int argc, char **argv) {
    Pumpkin::Log::Init();
    PUMPKIN_CORE_WARN("Initialized Log!");
    PUMPKIN_INFO("Hello!");
    
    auto app = Pumpkin::CreateApplication();
    app->Run();
    delete app;
}