#pragma once
#include <fstream>
#include <string>

enum class FileMode
{
    Read,
    Write,
    Append

};

class FileSystem
{
public:
    /// <summary>
    /// Initializes the file system handler
    /// </summary>
    static bool Init();

    /// <summary>
    /// Returns a handle to the opened file
    /// Does not create the file if it doesn't exist
    /// </summary>
    static std::fstream Open(const std::string& path, FileMode mode);

    /// <summary>
    /// Returns a handle to the created file in the specified open mode
    /// </summary>
    static std::fstream Create(const std::string& path, FileMode mode);

    /// <summary>
    /// closes the file passed
    /// </summary>
    static void Close(std::fstream& file);

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