#include <iostream>

#include "SDL3/SDL.h"
#include "SDLB_SDL.h"

int SDL::Init()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
		return 1;
	}

	return 0;
}
