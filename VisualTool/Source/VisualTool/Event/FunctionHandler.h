#pragma once

#include "stdpch.h"
#include "Core.h"
#include "Event.h"

namespace vt_event
{
	template<class ...TArgs>
	class VT_API FunctionHandler : public IEventHandler<TArgs...>
	{
	private:
		using HandlerFunction = std::function<void(TArgs...)>;
		HandlerFunction m_Handler;

	public:
		FunctionHandler(HandlerFunction handler) :
		m_Handler(handler) {}

		~FunctionHandler() {}

		void Handle(TArgs... args) override
		{
			m_Handler(args...);
		}
	};
}