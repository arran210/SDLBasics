#pragma once

#include <string>

class Log
{
public:
	/// <summary>
	/// Initializes the logging system
	/// </summary>
	static int Init();

	/// <summary>
    /// Runs at the end of the program to signal program exit and save the log to a file
	/// </summary>
	static int Exit();

	/// <summary>
	/// Logs an info message
	/// </summary>
	static int LogInfo(const std::string& message);

	/// <summary>
	/// Logs a warning message
	/// </summary>
	static int LogWarning(const std::string& message);

	/// <summary>
	/// Logs an error message
	/// </summary>
	static int LogError(const std::string& message);


private:
	static std::stringstream message_builder;

	/// <summary>
	/// Prefixes the message_builder with the current timestamp
	/// </summary>
	static int PrefixMessage();

	/// <summary>
	/// Saves every log currently made since the last save and clears the message_builder variable
	/// </summary>
	static int SaveLogToFile();
};