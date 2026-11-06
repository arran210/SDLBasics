#include "SDLB_Mouse.h"
#include "SDL3/SDL.h"

bool Mouse::buttons[5];
bool Mouse::buttons_down[5];
bool Mouse::buttons_up[5];
float Mouse::x;
float Mouse::y;
float Mouse::delta_x;
float Mouse::delta_y;

int Mouse::Init()
{
    return 0;
}

int Mouse::Update()
{
    float current_x, current_y;
    unsigned int mouse_state = SDL_GetMouseState(&current_x, &current_y);

    delta_x = current_x - x;
    delta_y = current_y - y;

    x = current_x;
    y = current_y;

    for (int i = 0; i < 5; ++i)
    {
        bool is_pressed = (mouse_state & SDL_BUTTON_MASK(i + 1)) != 0;
        buttons_down[i] = is_pressed && !buttons[i];
        buttons_up[i] = !is_pressed && buttons[i];
        buttons[i] = is_pressed;
    }
    return 0;
}

bool Mouse::GetButton(unsigned short button)
{
    return buttons[button];
}

bool Mouse::GetButtonDown(unsigned short button)
{
    return buttons_down[button];
}

bool Mouse::GetButtonUp(unsigned short button)
{
    return buttons_up[button];
}

float Mouse::GetX()
{
    return x;
}

float Mouse::GetY()
{
    return y;
}

float Mouse::GetDeltaX()
{
    return delta_x;
}

float Mouse::GetDeltaY()
{
    return delta_y;
}