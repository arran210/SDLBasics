#include "SDLBasics.h"

bool SDLBasics::Init()
{
    Log::LogInfo("Initializing SDLBasics...");

    if (!Log::Init()) return false;
    if (!Time::Init()) return false;
    if (!Keys::Init()) return false;
    if (!Mouse::Init()) return false;
    if (!FileSystem::Init()) return false;

    if (!SDL::Init()) return false;

    Log::LogInfo("SDLBasics initialized successfully.");
    return true;
}

bool SDLBasics::Update()
{
    if (!Time::Update()) return false;
    if (!Keys::Update()) return false;
    if (!Mouse::Update()) return false;


    return true;
}
