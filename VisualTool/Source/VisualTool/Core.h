#pragma once

#define VT_PLATFORM_WINDOWS
#define VT_BUILD_STATIC

#ifdef VT_PLATFORM_WINDOWS
	#ifdef VT_BUILD_DLL
		#define VT_API _declspec(dllexport)
	#elif defined VT_RUN_DLL
		#define	VT_API _declspec(dllimport)
	#endif
	#ifdef VT_BUILD_STATIC
		#define VT_API
	#endif
#else
	#error Only Windows supported for now
#endif

#define IMPLEMENT_APP(APP)\
int main(int argc, char* argv)\
{\
	std::unique_ptr<vt::Application> app = std::make_unique<APP>();\
	app->Run();\
}

#define VT_ASSERT(EXPR) assert(EXPR)