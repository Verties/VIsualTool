#pragma once

#pragma once

#include "Core.h"
#include "FunctionHandler.h"

namespace vt_event
{
	template<class ...TArgs>
	using StaticMethodHandler = FunctionHandler<TArgs...>;
}