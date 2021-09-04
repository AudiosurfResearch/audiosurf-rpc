// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

//quest3d headers
//these things are so old that editing them so they actually work was like putting together the skeleton of a fucking dinosaur
//ancient shit
//#include "quest3d/A3d_Channels.h"
//#include "quest3d/A3d_EngineInterface.h"
//#include "quest3d/Aco_String.h"
//#include "quest3d/EngineListener.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

//microsoft detours for function hooking
#include <detours.h>

// reference additional headers your program requires here
#include <iostream>
#include <vector>