#include "SDLBasics.h"

int SDLBasics::Init()
{
    Log::Init();
    Time::Init();
    Keys::Init();
    Mouse::Init();

    SDL::Init();

    return 0;
}
