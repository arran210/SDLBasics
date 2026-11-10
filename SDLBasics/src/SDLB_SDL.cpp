#include <iostream>

#include "SDL3/SDL.h"
#include "SDLB_SDL.h"
#include "SDLB_Log.h"

int SDL::Init()
{
    Log::LogInfo("Initializing SDL...");

	if (!SDL_Init(SDL_INIT_VIDEO))
	{
        Log::LogError("SDL_Init failed: " + std::string(SDL_GetError()));
		return 1;
	}

    Log::LogInfo("SDL initialized successfully.");

	return 0;
}
