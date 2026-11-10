#pragma once
#include <string>

class SDL_Window;

class Window
{
public:
    Window() = default;
    Window(const std::string& title, int width, int height);
    ~Window();

    bool Update();

    bool Create(const std::string& title, int width, int height);

    void SetTitle(const std::string& title);
    void Resize(int width, int height);

    int GetWidth() const;
    int GetHeight() const;


private:
    SDL_Window* window = nullptr;
};