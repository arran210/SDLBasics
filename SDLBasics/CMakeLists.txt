include_directories(
        include
)

add_library(SDLB_shared SHARED
        src/SDLB.cpp

        src/core/SDLB_FileSystem.cpp
        src/core/SDLB_Keys.cpp
        src/core/SDLB_Log.cpp
        src/core/SDLB_Mouse.cpp
        src/core/SDLB_SDL.cpp
        src/core/SDLB_Time.cpp

        src/components/SDLB_Window.cpp
)

add_library(SDLB_static STATIC
        src/SDLB.cpp

        src/core/SDLB_FileSystem.cpp
        src/core/SDLB_Keys.cpp
        src/core/SDLB_Log.cpp
        src/core/SDLB_Mouse.cpp
        src/core/SDLB_SDL.cpp
        src/core/SDLB_Time.cpp

        src/components/SDLB_Window.cpp
)

# Link to the actual SDL3 library.
target_link_libraries(SDLB_shared PRIVATE SDL3::SDL3)
target_link_libraries(SDLB_static PRIVATE SDL3::SDL3)

set_target_properties(SDLB_shared PROPERTIES PREFIX "")
set_target_properties(SDLB_static PROPERTIES PREFIX "")