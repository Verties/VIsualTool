#pragma once

#include "Core.h"
#include "Event.h"

namespace vt_event
{
	template<class TObject, class ...TArgs>
	class VT_API MethodHandler : public IEventHandler<TArgs...>
	{
	private:
		using HandlerMethod = void(TObject::*)(TArgs...);
		TObject& m_Object;
		HandlerMethod m_Handler;

	public:
		MethodHandler(TObject& object, HandlerMethod handler) :
			IEventHandler<TArgs...>(),
			m_Object(object),
			m_Handler(handler) {}

		~MethodHandler() {}

		void Handle(TArgs... args) override
		{
			(m_Object.*m_Handler)(args...);
		}
	};
}