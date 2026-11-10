#include "SDLB_Window.h"

#include "SDL3/SDL.h"
#include "SDLB_Log.h"

Window::Window(const std::string& title, int width, int height)
{
    if (window != nullptr)
    {
        Log::LogWarning("Window already exists. Destroying the existing window before creating a new one.");
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    Create(title, width, height);
}

Window::~Window()
{
    SDL_DestroyWindow(window);
}

bool Window::Update()
{
    SDL_UpdateWindowSurface(window);

    return true;
}

bool Window::Create(const std::string& title, int width, int height)
{
    window = SDL_CreateWindow(title.c_str(), width, height, NULL);
    if (!window)
    {
        Log::LogError("Failed to create window: " + std::string(SDL_GetError()));
        return false;
    }

    Log::LogInfo("Window created successfully: " + title + " (" + std::to_string(width) + "x" + std::to_string(height) + ")");
    return true;
    
}

void Window::SetTitle(const std::string& title)
{
    SDL_SetWindowTitle(window, title.c_str());
}

void Window::Resize(int width, int height)
{
    SDL_SetWindowSize(window, width, height);
}

int Window::GetWidth() const
{
    int width;
    SDL_GetWindowSize(window, &width, nullptr);
    return width;
}

int Window::GetHeight() const
{
    int height;
    SDL_GetWindowSize(window, nullptr, &height);
    return height;
}
