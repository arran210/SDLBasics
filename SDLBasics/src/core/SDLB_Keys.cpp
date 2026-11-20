#include "SDLB_Keys.h"

#include "SDLB_Log.h"
#include "SDL3/SDL.h"

bool Keys::keys[SDL_SCANCODE_COUNT];
bool Keys::keys_down[SDL_SCANCODE_COUNT];
bool Keys::keys_up[SDL_SCANCODE_COUNT];

bool Keys::Init()
{
    Log::LogInfo("Initializing Keys...");
    Log::LogInfo("Keys initialized successfully.");
    return true;
}

bool Keys::Update()
{
    const bool* current_key_states = SDL_GetKeyboardState(NULL);
    for (int i = 0; i < SDL_SCANCODE_COUNT; ++i)
    {
        bool is_pressed = current_key_states[i] != 0;
        keys_down[i] = is_pressed && !keys[i];
        keys_up[i] = !is_pressed && keys[i];
        keys[i] = is_pressed;
    }
    return true;
}

bool Keys::GetKey(unsigned short key)
{
    return keys[key];
}

bool Keys::GetKeyDown(unsigned short key)
{
    return keys_down[key];
}

bool Keys::GetKeyUp(unsigned short key)
{
    return keys_up[key];
}
