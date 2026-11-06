#pragma once

class Keys
{
public:
    static int Init();

    static int Update();

    static bool GetKey(unsigned short key);
    static bool GetKeyDown(unsigned short key);
    static bool GetKeyUp(unsigned short key);

private:
    static bool keys[SDL_SCANCODE_COUNT];
    static bool keys_down[SDL_SCANCODE_COUNT];
    static bool keys_up[SDL_SCANCODE_COUNT];
};