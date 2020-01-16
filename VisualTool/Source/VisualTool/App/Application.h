#pragma once

#include "Core.h"

namespace vt
{
	class VT_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};
}