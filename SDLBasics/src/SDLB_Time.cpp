#include "SDLB_Time.h"

#include "SDLB_Log.h"

#include <chrono>
#include <iostream>
#include <format>

double Time::delta_time = 0.0;
double Time::elapsed_time = 0.0;
double Time::previous_frame_time = 0.0;
double Time::start_time = 0.0;
unsigned long long Time::frame_count = 0;

bool Time::Init()
{
    Log::LogInfo("Initializing Time management system...");

    delta_time = 0.0;
    elapsed_time = 0.0;
    previous_frame_time = GetCurrentTime();
    start_time = GetCurrentTime();
    frame_count = 0;

    Log::LogInfo("Time management system initialized successfully.");

    return true;
}

bool Time::Update()
{
    double current_time = GetCurrentTime();

    delta_time = current_time - previous_frame_time;
    elapsed_time = current_time - start_time;

    previous_frame_time = current_time;

    frame_count++;

    return true;
}

double Time::GetDeltaTime()
{
    return delta_time;
}

double Time::GetElapsedTime()
{
    return elapsed_time;
}

double Time::GetTrueElapsedTime()
{
    return GetCurrentTime() - start_time;
}

double Time::GetCurrentTime()
{
    auto now = std::chrono::system_clock::now();

    return std::chrono::duration<double>(now.time_since_epoch()).count();
}

std::string Time::GetDateTimeString()
{
    auto now = std::chrono::system_clock::now();
    auto str = std::format("{:%d/%m/%Y %H:%M:%S}", now);

    return str;
}
