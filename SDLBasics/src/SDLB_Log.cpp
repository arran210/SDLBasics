#include <sstream>
#include <fstream>
#include <iostream>

#include "SDLB_Log.h"
#include "SDLB_Time.h"

std::stringstream Log::message_builder;

int Log::Init()
{
    std::atexit((void(*)())SaveLogToFile);

    std::ofstream log_file("SDLBasics_Log.txt", std::ios::out | std::ios::trunc);
    if (!log_file.is_open())
    {
        std::cerr << "Failed to create log file: SDLBasics_Log.txt" << std::endl;
        return 1;
    }
	log_file.close();

	return 0;
}

int Log::Exit()
{
	LogInfo("Program exiting...");

	SaveLogToFile();

	return 0;
}

int Log::LogInfo(const std::string& message)
{
	PrefixMessage();

	message_builder << "[INFO]: " << message << std::endl;

    return 0;
}

int Log::LogWarning(const std::string& message)
{
	PrefixMessage();

	message_builder << "[WARNING]: " << message << std::endl;

    return 0;
}

int Log::LogError(const std::string& message)
{
	PrefixMessage();

	message_builder << "[ERROR]: " << message << std::endl;

    return 0;
}

int Log::PrefixMessage()
{
	message_builder << "[" << Time::GetDateTimeString() << "]";
	return 0;
}

int Log::SaveLogToFile()
{
	/* SAVE THE LOG MESSAGE TO A FILE */
    std::ofstream log_file("SDLBasics_Log.txt", std::ios::out | std::ios::app);
    if (!log_file.is_open())
    {
        std::cerr << "Failed to open log file for writing: SDLBasics_Log.txt" << std::endl;
        return 1;
    }
    log_file << message_builder.str();
    log_file.close();

	// Clear the message builder after saving
	message_builder.str("");
	return 0;
}
