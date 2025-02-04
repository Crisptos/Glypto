#pragma once

#ifdef GLYPTO_PLATFORM_WINDOWS
	#ifdef GLYPTO_BUILD_DLL
		#define GLYPTO_API __declspec(dllexport)
	#else
		#define GLYPTO_API __declspec(dllimport)
	#endif
#else
	#error Glypto does not support the current platform detected
#endif