#include "SDLBasics.h"

#include "SDLB_Log.h"
#include "SDLB_Time.h"
#include "SDLB_Keys.h"
#include "SDLB_SDL.h"

int SDLBasics::Init()
{
    Log::Init();
    Time::Init();
    Keys::Init();

    SDL::Init();

    return 0;
}
