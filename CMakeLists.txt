cmake_minimum_required(VERSION 4.4)
project(SDLBasicsMain)

set(CMAKE_CXX_STANDARD 26)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(SDL-3.4.20)

add_subdirectory(SDLBasics)

add_subdirectory(SDLB_Testing)

# Link to the actual SDL3 library.
target_link_libraries(SDLBasics PUBLIC SDL3::SDL3)

target_link_libraries(SDLB_Testing PRIVATE SDLBasics)