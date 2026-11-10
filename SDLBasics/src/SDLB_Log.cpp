#include <sstream>
#include <fstream>
#include <iostream>

#include "SDLB_Log.h"
#include "SDLB_Time.h"

std::stringstream Log::message_builder;

bool Log::Init()
{
    std::atexit((void(*)())SaveLogToFile);

    std::ofstream log_file("SDLBasics_Log.txt", std::ios::out | std::ios::trunc);
    if (!log_file.is_open())
    {
        std::cerr << "Failed to create log file: SDLBasics_Log.txt" << std::endl;
        return false;
    }
	log_file.close();

	return true;
}

bool Log::Exit()
{
	LogInfo("Program exiting...");

	if (!SaveLogToFile())
	{
		std::cerr << "Failed to save log to file." << std::endl;
		return false;
	}

	return true;
}

void Log::LogInfo(const std::string& message)
{
	PrefixMessage();

	message_builder << "[INFO]: " << message << std::endl;
}

void Log::LogWarning(const std::string& message)
{
	PrefixMessage();

	message_builder << "[WARNING]: " << message << std::endl;
}

void Log::LogError(const std::string& message)
{
	PrefixMessage();

	message_builder << "[ERROR]: " << message << std::endl;
}

void Log::PrefixMessage()
{
	message_builder << "[" << Time::GetDateTimeString() << "]";
}

bool Log::SaveLogToFile()
{
	/* SAVE THE LOG MESSAGE TO A FILE */
    std::ofstream log_file("SDLBasics_Log.txt", std::ios::out | std::ios::app);
    if (!log_file.is_open())
    {
        std::cerr << "Failed to open log file for writing: SDLBasics_Log.txt" << std::endl;
        return false;
    }
    log_file << message_builder.str();
    log_file.close();

	// Clear the message builder after saving
	message_builder.str("");
	return true;
}
