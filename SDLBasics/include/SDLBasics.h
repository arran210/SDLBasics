#pragma once
#include "SDLB_Log.h"
#include "SDLB_Time.h"
#include "SDLB_Keys.h"
#include "SDLB_Mouse.h"
#include "SDLB_SDL.h"
#include "SDLB_Window.h"
#include "SDLB_FileSystem.h"


class SDLBasics
{
public:
	/// <summary>
	/// Initializes the SDLBasics library and all its subsystems
	/// </summary>
	static bool Init();

	/// <summary>
	/// Updates each SDLBasics subsystem, intended to be called once per frame
	/// </summary>
	static bool Update();
};