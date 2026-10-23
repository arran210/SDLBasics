#pragma once
#include <string>

class Time
{
public:
	/// <summary>
	/// Initializes the time management system
	/// </summary>
	static int Init();

	/// <summary>
	/// Called at the end of every frame to update the time management system
	/// </summary>
	static int Update();

	/// <summary>
	/// Amount of time passed since the last frame and the one before in seconds
	/// </summary>
	static double GetDeltaTime();

	/// <summary>
	/// Amount of time passed since the initialization of the Time class in seconds and the start of the current frame
	/// </summary>
	static double GetElapsedTime();

	/// <summary>
	/// Amount of time passed since the initialization of the Time class in seconds
	/// </summary>
	static double GetTrueElapsedTime();

	/// <summary>
	/// Gets the current date and time as a string
	/// </summary>
	static const std::string& GetDateTimeString();
};