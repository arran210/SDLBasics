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

	static int SaveLogToFile();
};