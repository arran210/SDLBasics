#pragma once

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
    static bool keys[512];
    static bool keys_down[512];
    static bool keys_up[512];
};