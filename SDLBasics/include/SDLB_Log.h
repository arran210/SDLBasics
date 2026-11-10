#pragma once

#include <string>

class Log
{
public:
	/// <summary>
	/// Initializes the logging system
	/// </summary>
	static bool Init();

	/// <summary>
    /// Runs at the end of the program to signal program exit and save the log to a file
	/// </summary>
	static bool Exit();

	/// <summary>
	/// Logs an info message
	/// </summary>
	static void LogInfo(const std::string& message);

	/// <summary>
	/// Logs a warning message
	/// </summary>
	static void LogWarning(const std::string& message);

	/// <summary>
	/// Logs an error message
	/// </summary>
	static void LogError(const std::string& message);


private:
	static std::stringstream message_builder;

	/// <summary>
	/// Prefixes the message_builder with the current timestamp
	/// </summary>
	static void PrefixMessage();

	/// <summary>
	/// Saves every log currently made since the last save and clears the message_builder variable
	/// </summary>
	static bool SaveLogToFile();
};