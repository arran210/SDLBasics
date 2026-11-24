#include "SDL3/SDL.h"
#include "../../include/SDLB/SDLB_SDL.h"
#include "SDLB/SDLB_Log.h"

bool SDL::Init()
{
    Log::LogInfo("Initializing SDL...");

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        Log::LogError("SDL_Init failed: " + std::string(SDL_GetError()));
        return false;
    }

    Log::LogInfo("SDL initialized successfully.");

    return true;
}
