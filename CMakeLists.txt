cmake_minimum_required(VERSION 3.25)
project(SDLBasicsMain VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 26)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

option(SDLBASICS_BUILD_SHARED "Build shared library" ON)
option(SDLBASICS_BUILD_STATIC "Build static library" ON)


# Ensures only necessary SDL files are built
set(SDL_STATIC ON)

if (SDLBASICS_BUILD_STATIC)
    set(SDL_SHARED ON)
else()
    set(SDL_SHARED OFF)
endif()

add_subdirectory(SDL)

add_subdirectory(SDLBasics)

add_subdirectory(SDLB_Testing)
