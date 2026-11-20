#include "../../include/SDLB_FileSystem.h"

#include "../../include/SDLB_Log.h"
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#elif __APPLE__
#include <mach-o/dyld.h>
#endif
#include <filesystem>


std::string FileSystem::executable_path;
std::string FileSystem::executable_directory;

bool FileSystem::Init()
{
    Log::LogInfo("Initializing FileSystem...");

#ifdef _WIN32
    char buffer[MAX_PATH];
    DWORD length = GetModuleFileNameA(nullptr, buffer, MAX_PATH);

    if (length != -1)
    {
        executable_path = std::string(buffer);
        executable_directory = std::filesystem::path(buffer).parent_path().string();
    }
    else
    {
        Log::LogError("File system failed to initialize");
        return false;
    }

#elif __linux__
    char buffer[4096];
    ssize_t length = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);

    if (length != -1)
    {
        buffer[length] = '\0';
        executable_path = std::filesystem::path(buffer).string();
        executable_directory = std::filesystem::path(buffer).parent_path().string()
    }
    else
    {
        Log::LogError("File system failed to initialize")
        return false;
    }

#elif __APPLE__
    uint32_t size = 0;
    _NSGetExecutablePath(nullptr, &size);

    std::string buffer(size, '\0');

    if (_NSGetExecutablePath(buffer.data(), &size) == 0)
    {
        executable_path = std::filesystem::canonical(buffer).string();
        executable_directory = std::filesystem::path(buffer).parent_path().string();
    }

#endif

    Log::LogInfo("Executable Path is: " + executable_path);

    Log::LogInfo("FileSystem initialized successfully.");
    return true;
}

std::fstream FileSystem::Create(const std::string& path, FileMode mode)
{
    std::ofstream file = std::ofstream(path);

    return Open(path, mode);
}

std::fstream FileSystem::Open(const std::string& path, FileMode mode)
{
    if (!std::filesystem::exists(path))
    {
        Log::LogError("File does not exist: " + path);
        return std::fstream{};
    }

    std::ios::openmode open_mode = std::ios::in;

    switch (mode)
    {
    case FileMode::Read:
        open_mode = std::ios::in;
        break;

    case FileMode::Write:
        open_mode = std::ios::out;
        break;

    case FileMode::Append:
        open_mode = std::ios::out | std::ios::app;
        break;
    }

    std::fstream file = std::fstream(path, open_mode);

    if (!file.is_open())
    {
        Log::LogError("File failed to open: " + path);
        return std::fstream{};
    }

    return file;
}

void FileSystem::Close(std::fstream& file)
{
    file.close();
}

const std::string& FileSystem::GetExecutablePath()
{
    return executable_path;
}

const std::string& FileSystem::GetExecutableDirectory()
{
    return executable_directory;
}