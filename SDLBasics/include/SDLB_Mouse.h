#pragma once

class Mouse
{
public:
    /// <summary>
    /// Initialises the mouse input system
    /// </summary>
    static int Init();

    /// <summary>
    /// Updates the mouse input system each frame
    /// </summary>
    static int Update();

    /// <summary>
    /// Checks if the current mouse button is down
    /// </summary>
    static bool GetButton(unsigned short button);

    /// <summary>
    /// Checks if the entered mouse button was pushed this frame
    /// </summary>
    static bool GetButtonDown(unsigned short button);

    /// <summary>
    /// Checks if the entered mouse button was released this frame
    /// </summary>
    static bool GetButtonUp(unsigned short button);

    /// <summary>
    /// Gets the X position of the mouse pointer
    /// </summary>
    static float GetX();

    /// <summary>
    /// Gets the Y position of the mouse pointer
    /// </summary>
    static float GetY();

    /// <summary>
    /// Gets the X Delta of the mouse pointer
    /// </summary>
    static float GetDeltaX();

    /// <summary>
    /// Gets the Y Delta of the mouse pointer
    /// </summary>
    static float GetDeltaY();

private:
    static bool buttons[5];
    static bool buttons_down[5];
    static bool buttons_up[5];
    static float x;
    static float y;
    static float delta_x;
    static float delta_y;
};