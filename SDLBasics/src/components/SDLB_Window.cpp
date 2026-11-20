#include "SDLB_Window.h"

#include "SDL3/SDL.h"
#include "SDLB_Log.h"

Window::Window(const std::string& title, const int width, const int height)
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

bool Window::Update() const
{
    SDL_UpdateWindowSurface(window);

    return true;
}

bool Window::Create(const std::string& title, const int width, const int height)
{
    window = SDL_CreateWindow(title.c_str(), width, height, NULL);
    if (!window)
    {
        Log::LogError("Failed to create window: " + std::string(SDL_GetError()));
        return false;
    }

    Log::LogInfo(
        "Window created successfully: " + title + " (" + std::to_string(width) + "x" + std::to_string(height) + ")");
    return true;
}

void Window::SetTitle(const std::string& title) const
{
    SDL_SetWindowTitle(window, title.c_str());
}

void Window::Resize(const int width, const int height) const
{
    SDL_SetWindowSize(window, width, height);
}

int Window::GetWidth() const
{
    int width = 0;
    SDL_GetWindowSize(window, &width, nullptr);
    return width;
}

int Window::GetHeight() const
{
    int height = 0;
    SDL_GetWindowSize(window, nullptr, &height);
    return height;
}
