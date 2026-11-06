#pragma once
#include "SDL3/SDL_scancode.h"

class Keys
{
public:
    /// <summary>
    /// Initialises the key input system
    /// </summary>
    static int Init();

    /// <summary>
    /// Updates the key input system
    /// </summary>
    static int Update();

    /// <summary>
    /// Checks if the inputted key is currently down
    /// </summary>
    static bool GetKey(unsigned short key);

    /// <summary>
    /// Checks if the inputted key has been pressed this frame
    /// </summary>
    static bool GetKeyDown(unsigned short key);

    /// <summary>
    /// Checks if the inputted key has been released this frame
    /// </summary>
    static bool GetKeyUp(unsigned short key);

private:
    static bool keys[SDL_SCANCODE_COUNT];
    static bool keys_down[SDL_SCANCODE_COUNT];
    static bool keys_up[SDL_SCANCODE_COUNT];
};