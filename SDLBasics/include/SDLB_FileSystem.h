#pragma once
#include <fstream>
#include <string>

class FileSystem
{
public:
    /// <summary>
    /// Initializes the file system handler
    /// </summary>
    static bool Init();

    /// <summary>
    /// returns a handle back to the opened file
    /// </summary>
    static std::fstream OpenFile(const std::string& filename, std::ios::openmode mode);

    /// <summary>
    /// closes the file passed
    /// </summary>
    static void CloseFile(std::fstream& file);

    /// <summary>
    /// returns the path of the executable file being executed
    /// </summary>
    static const std::string& GetExecutablePath();

    /// <summary>
    /// returns the directory the exe file is held in
    /// </summary>
    static const std::string& GetExecutableDirectory();

private:
    static std::string executable_path;
    static std::string executable_directory;
};