//==================================================================
/**
	@file	GB_Log.h
	@brief	This file includes the GB_Log class

	The GB_Log class writes GB_LERRORs, warnings and other messages into
	a file.

	@author	drubner
	@date Created at 2012-08-15
**/
//==================================================================
#pragma once 

//==================================================================
//	INCLUDE
//==================================================================
#include "GooseBerry.h"

//==================================================================
//	NAMESPACE
//==================================================================

//==================================================================
//	FUNCTION
//==================================================================
GOOSEBERRY_API GB_Enum::gbResult	InitializeLog();
GOOSEBERRY_API GB_Enum::gbResult	StopLog();
GOOSEBERRY_API GB_Enum::gbResult	Log(std::string msg);
GOOSEBERRY_API std::string			CurrentTime();
GOOSEBERRY_API std::string			CurrentDate();

//==================================================================
//	INLINE
//==================================================================
inline GOOSEBERRY_API VOID GB_LDEBUG(string msg)				{ if (DEBUG_MODE) Log("<td class=\"GB_LDEBUG\">" + msg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LINFO(string msg)					{ Log("<td class=\"GB_LINFO\">" + msg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LWARNING(string msg)				{ Log("<td class=\"GB_LWARNING\">" + msg + "</td>\n"); }
inline GOOSEBERRY_API VOID GB_LERROR(string msg, string id)		{ Log("<td class=\"GB_LERROR\">" + msg + "<" + id + "></td>\n"); }
inline GOOSEBERRY_API VOID GB_MSGBOXERR(LPCSTR msg, LPCSTR id)	{ MessageBox(NULL, msg, id, MB_OK | MB_ICONERROR); }