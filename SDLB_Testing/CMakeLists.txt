include_directories(../SDLBasics/include)

add_executable(SDLB_Testing
    src/main.cpp
)


target_link_libraries(SDLB_Testing PUBLIC
        SDLB_shared # replace with SDLB_static to link to static library
)