//=============================================================================
/**
  @file   stdafx.h
  @brief  include file for standard system include files,
          or project specific include files that are used frequently,
          but are changed infrequently
  @author mwilhelm
  @date   2013-11-27
**/
//=============================================================================
// INCLUDE GUARD
//=============================================================================
#pragma once

//=============================================================================
// INCLUDES
//=============================================================================
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>



// reference additional headers your program requires here
#include <iostream>

#include "WorldGenerator.h"
#include "Universe.h"
#include "ParameterContainer.h"
#include "Orb.h"
#include "GlobalEnums.h"

// needs to be included after the defines
#include "..\..\Log\inc\Log.h"