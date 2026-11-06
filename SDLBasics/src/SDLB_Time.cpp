#include "SDLB_Time.h"

#include <chrono>

double Time::delta_time = 0.0;
double Time::elapsed_time = 0.0;
double Time::previous_frame_time = 0.0;
double Time::start_time = 0.0;
unsigned long long Time::frame_count = 0;

int Time::Init()
{
    delta_time = 0.0;
    elapsed_time = 0.0;
    previous_frame_time = GetCurrentTime();
    start_time = GetCurrentTime();
    frame_count = 0;
    return 0;
}

int Time::Update()
{
    delta_time = GetCurrentTime() - previous_frame_time;
    elapsed_time = GetCurrentTime() - start_time;

    frame_count++;

    return 0;
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
    return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

const std::string& Time::GetDateTimeString()
{
    return std::format("{:%Y-%m-%d %H:%M:%S}", std::chrono::system_clock::now());
}
