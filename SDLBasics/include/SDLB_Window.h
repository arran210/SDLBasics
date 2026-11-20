#pragma once
#include <string>

class SDL_Window;

class Window
{
public:
    Window() = default;
    Window(const std::string& title, int width, int height);
    ~Window();

    bool Update() const;

    bool Create(const std::string& title, int width, int height);

    void SetTitle(const std::string& title) const;
    void Resize(int width, int height) const;

    int GetWidth() const;
    int GetHeight() const;

private:
    SDL_Window* window = nullptr;
};