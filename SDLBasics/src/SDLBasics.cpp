#include "SDLBasics.h"

bool SDLBasics::Init()
{
    Log::Init();
    Time::Init();
    Keys::Init();
    Mouse::Init();

    SDL::Init();

    return true;
}
