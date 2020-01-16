#pragma once

#define VT_PLATFORM_WINDOWS
#define VT_BUILD_DLL

#ifdef VT_PLATFORM_WINDOWS

	#ifdef VT_BUILD_DLL
		#define VT_API _declspec(dllexport)
	#else
		#define	VT_API _declspec(dllimport)
	#endif // VT_PLATFORM_WINDOWS

	#ifdef VT_BUILD_STATIC
		#define VT_API
	#endif // VT_BUILD_STATIC

	#else
		#error Only Windows supported for now

#endif //VT_BUILD_DLL