#pragma once

#ifdef GLYPTO_PLATFORM_WINDOWS
	#ifdef GLYPTO_BUILD_DLL
		#define GLYPTO_API __declspec(dllexport) 
	#else
		#define GLYPTO_API __declspec(dllimport)
	#endif
#else
	#error Crisp only supports Windows at the moment 
#endif