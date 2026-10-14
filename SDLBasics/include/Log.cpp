#include <sstream>

#include "Log.h"
#include "Time.h"

std::stringstream Log::message_builder;

int Log::Init()
{
	return 0;
}

int Log::LogInfo(const std::string& message)
{
	PrefixMessage();

	message_builder << "[INFO]: " << message;

    return 0;
}

int Log::LogWarning(const std::string& message)
{
	PrefixMessage();


	message_builder << "[WARNING]: " << message;

    return 0;
}

int Log::LogError(const std::string& message)
{
	PrefixMessage();

	message_builder << "[ERROR]: " << message;

    return 0;
}

int Log::PrefixMessage()
{
	message_builder << "[" << /*TIMESTAMP TO BE ADDED*/ "" << "]";
	return 0;
}

int Log::SaveLogToFile()
{
	/* SAVE THE LOG MESSAGE TO A FILE */

	// Clear the message builder after saving
	message_builder.str("");
	return 0;
}
