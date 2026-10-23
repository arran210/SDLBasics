#include "SDLBasics.h"

int main(int argc, char* argv[])
{
    // Initialize the SDLBasics library
    if (SDLBasics::Init() != 0)
    {
        return 1;
    }
    // Main loop
    bool running = true;
    while (running)
    {
        // Update the time management system
        Time::Update();
        // Log the delta time for debugging purposes
        Log::LogInfo("Delta Time: " + std::to_string(Time::GetDeltaTime()));
        // Here you would typically handle events and rendering
        // For demonstration, we'll just run for a few iterations and then exit
        static int frameCount = 0;
        if (++frameCount > 100) // Run for 100 frames
        {
            running = false;
        }
    }
    return 0;
}