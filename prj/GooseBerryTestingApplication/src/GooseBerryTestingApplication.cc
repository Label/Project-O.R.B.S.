/**
@file	GooseBerryTestingApplication.cc
@brief	Includes main program
@author	drubner
@date	2013-12-17
**/
//==================================================================
//	INCLUDE
//==================================================================
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#include "..\..\Log\inc\Log.h"
#include "..\..\GooseBerry\inc\GooseBerry.h"

//==================================================================
//	NAMESPACE
//==================================================================
using namespace std;

//==================================================================
//	GLOBALS
//==================================================================
GB_OpenGL g_open_gl;

//==================================================================
//	MAIN
//==================================================================
int WINAPI WinMain(HINSTANCE h_instance, HINSTANCE h_prev_instance, PSTR cmd_line, int cmd_show)
{
	GB_Var::g_hinstance				= h_instance;
	GB_Var::g_HWND					= NULL;
	GB_Var::g_wnd_title				= "GooseBerryTestApplication";
	GB_Var::g_wnd_name				= "GooseBerryTestApplication";
	GB_Var::g_wnd_width				= 800;
	GB_Var::g_wnd_height			= 600;
	GB_Var::g_wnd_x					= 0;
	GB_Var::g_wnd_y					= 0;
	GB_Var::g_bits_color			= 32;
	GB_Var::g_bits_depth			= 32;
	GB_Var::g_bits_alpha			= 32;
	GB_Var::g_fullscreen			= FALSE;
	GB_Var::g_active				= TRUE;

	Log::getInstance()->set_file_path_and_name(string("log"), string("log.html"));
	Log::getInstance()->debug_mode_ = true;
	LOG_DEBUG("GooseBerryTestingApplication started");
	LOG_DEBUG("Log system initialized succesfully");

	//	Start code here
	try
	{
		GB_Func::Initialize();



		GB_Func::Exit();
	}
	catch (const GB_Exception &exception)
	{
		GB_LERROR(exception.GetStr(), exception.GetId());
		GB_MSGBOXERR(exception.GetStr(), exception.GetId());
	}

	LOG_DEBUG("GooseBerryTestingApplication finished");
	getchar();

	delete Log::getInstance();
	getchar();

	return 0;
}

