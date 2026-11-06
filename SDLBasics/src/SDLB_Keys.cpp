#include "SDLB_Keys.h"

#include "SDL3/SDL.h"

class Keys
{
public:

private:
    static bool keys[SDL_NUM_SCANCODES];
    static bool keys_down[SDL_NUM_SCANCODES];
    static bool keys_up[SDL_NUM_SCANCODES];
};