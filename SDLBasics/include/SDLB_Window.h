#pragma once
#include <string>

class SDL_Window;

class Window
{
public:
    Window(const std::string& title, int width, int height)
        : window(nullptr)
    {
        Create(title, width, height);
    }
    ~Window();

    bool Create(const std::string& title, int width, int height);

    void SetTitle(const std::string& title);
    void Resize(int width, int height);

    int GetWidth() const;
    int GetHeight() const;


private:
    SDL_Window* window;
};