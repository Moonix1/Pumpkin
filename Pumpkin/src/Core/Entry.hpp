#pragma once

#include "Application.hpp"

extern Pumpkin::Application *Pumpkin::CreateApplication();

int main(int argc, char **argv) {
    auto app = Pumpkin::CreateApplication();
    app->Run();
    delete app;
}