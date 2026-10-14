#include <iostream>

#include "SDL3/SDL.h"
#include "SDL.h"

int SDL::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
		return 1;
	}
}
