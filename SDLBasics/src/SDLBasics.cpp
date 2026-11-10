#include "SDLBasics.h"

bool SDLBasics::Init()
{
    if (!Log::Init()) return false;
    if (!Time::Init()) return false;
    if (!Keys::Init()) return false;
    if (!Mouse::Init()) return false;

    if (!SDL::Init()) return false;

    return true;
}

bool SDLBasics::Update()
{
    if (!Time::Update()) return false;
    if (!Keys::Update()) return false;
    if (!Mouse::Update()) return false;


    return true;
}
