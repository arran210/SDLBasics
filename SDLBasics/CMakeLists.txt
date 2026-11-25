include_directories(
        include
)

set(SDLBASICS_SOURCES
        src/SDLB.cpp

        src/core/SDLB_FileSystem.cpp
        src/core/SDLB_Keys.cpp
        src/core/SDLB_Log.cpp
        src/core/SDLB_Mouse.cpp
        src/core/SDLB_SDL.cpp
        src/core/SDLB_Time.cpp

        src/components/SDLB_Window.cpp
)

if(SDLBASICS_BUILD_SHARED)
    add_library(SDLB_shared SHARED ${SDLBASICS_SOURCES})

    target_link_libraries(
            SDLB_shared
            PUBLIC
            SDL3::SDL3-static
    )

    set_target_properties(SDLB_shared PROPERTIES
            OUTPUT_NAME "SDLB"
            PREFIX ""
    )

endif()

if(SDLBASICS_BUILD_STATIC)

    add_library(SDLB_static STATIC ${SDLBASICS_SOURCES})

    target_link_libraries(
            SDLB_static
            PUBLIC
            SDL3::SDL3-shared
    )

    set_target_properties(SDLB_static PROPERTIES
            OUTPUT_NAME "SDLB_lib"
            PREFIX ""
            ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>"
    )

endif()