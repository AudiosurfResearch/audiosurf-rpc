#pragma once

// DLL Exports
#ifdef DLLHIGHPOLY_EXPORTS
#define DLLHIGHPOLY_API __declspec(dllexport)
#else
#define DLLHIGHPOLY_API __declspec(dllimport)
#endif

#include "A3d_Channels.h"

class DLLHIGHPOLY_API EngineListener
{
public:
	EngineListener(void);
	virtual ~EngineListener(void);

	virtual void		OnAboutToReleaseChannel(A3d_Channel* channel);
};
