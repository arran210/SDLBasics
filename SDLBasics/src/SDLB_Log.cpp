#include <sstream>

#include "SDLB_Log.h"
#include "SDLB_Time.h"

std::stringstream Log::message_builder;

int Log::Init()
{
    std::atexit((void(*)())SaveLogToFile);
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

	// Clear the message builder after saving
	message_builder.str("");
	return 0;
}
