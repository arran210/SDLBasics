include_directories(include)

add_library(SDLBasics
        src/SDLBasics.cpp

        src/core/SDLB_Keys.cpp
        src/core/SDLB_Log.cpp
        src/core/SDLB_Mouse.cpp
        src/core/SDLB_SDL.cpp
        src/core/SDLB_Time.cpp

        src/components/SDLB_Window.cpp
)

# Link to the actual SDL3 library.
target_link_libraries(SDLBasics PRIVATE SDL3::SDL3)
