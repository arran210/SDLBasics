#include "SDLB_FileSystem.h"

#include "SDLB_Log.h"

#include <Windows.h>
#include <filesystem>

std::string FileSystem::executable_path;
std::string FileSystem::executable_directory;

bool FileSystem::Init()
{
    Log::LogInfo("Initializing FileSystem...");

    char buffer[MAX_PATH];
    GetModuleFileNameA(nullptr, buffer, MAX_PATH);

    executable_path = std::string(buffer);
    executable_directory = std::filesystem::path(buffer).parent_path().string();

    Log::LogInfo("Executable Path is: " + executable_path);

    Log::LogInfo("FileSystem initialized successfully.");
    return true;
}

std::fstream FileSystem::OpenFile(const std::string& filename, std::ios::openmode mode)
{
    std::fstream file(filename, mode);
    return file;
}

void FileSystem::CloseFile(std::fstream& file)
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