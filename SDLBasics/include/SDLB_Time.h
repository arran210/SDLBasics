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
    /// Amount of time that has passed since the epoch (1 Jan 1970) in seconds
    /// </summary>
    static double GetTime();

	/// <summary>
	/// Gets the current date and time as a string
	/// </summary>
	static const std::string& GetDateTimeString();

private:
    static double delta_time;
    static double elapsed_time;
    static double true_elapsed_time;
    static double previous_frame_time;
};