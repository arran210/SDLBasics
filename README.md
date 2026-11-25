# SDLBasics

A lightweight C++ wrapper around SDL3.

## Features

- Window management
- Keyboard input
- Mouse input
- Logging
- Timing utilities

## Example

```cpp
#include <SDLB/SDLB_Window.h>

int main()
{
    Window window("Test", 800, 600);

    while (window.Update())
    {
    }

    return 0;
}
```
