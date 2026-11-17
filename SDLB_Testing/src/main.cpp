#include "SDLBasics.h"

#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char* argv[])
{
    // Initialize the SDLBasics library
    if (!SDLBasics::Init())
    {
        Log::LogError("Failed to initialize SDLBasics. Exiting application.");
        return 1;
    }
    // Main loop
    bool running = true;

    Window window;
    if (!window.Create("SDLBasics Window", 800, 600))
    {
        Log::LogError("Failed to create window. Exiting application.");
        return 1;
    }

    while (running)
    {
        // Update the SDLB system
        SDLBasics::Update();

        window.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // Simulate frame time (~60 FPS)

        // Log the delta time for debugging purposes
        Log::LogInfo("Delta Time: " + std::to_string(Time::GetDeltaTime()));
        // Here you would typically handle events and rendering
        // For demonstration, we'll just run for a few iterations and then exit
        static int frameCount = 0;
        if (++frameCount > 100) // Run for 1000 frames
        {

            running = false;
        }
    }
    return 0;
}