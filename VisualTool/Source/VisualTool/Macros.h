#pragma once

#include "App/Application.h"
#include "stdpch.h"

#define VT_ASSERT(EXPR) assert(EXPR)

#define IMPLEMENT_APP(APP)\
int main(int argc, char* argv)\
{\
	std::unique_ptr<vt::Application> app = std::make_unique<APP>();\
	app->Run();\
}