#pragma once

#include "Core.h"

namespace vt
{
	class VT_API Event
	{
	public:
		virtual void Dispatch();

	private:
		std::list<std::function<int()>> m_Subscribers;
	};
}