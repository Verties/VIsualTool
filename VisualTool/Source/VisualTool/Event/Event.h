#pragma once

#include "stdpch.h"
#include "Core.h"

namespace vt_event
{
	template<class ...TArgs>
	class VT_API IEventHandler
	{
	public:
		virtual void Handle(TArgs... args) = 0;
	};

	template<class ...TArgs>
	class VT_API Event
	{
	private:
		using EventHandler = IEventHandler<TArgs...>;
		using HandlersList = std::list<EventHandler*>;
		HandlersList m_HandlersList;

	public:
		Event() {}

		~Event()
		{
			for (EventHandler* handler : m_HandlersList)
				delete handler;

			m_HandlersList.clear();
		}

		void operator()(TArgs... args)
		{
			for (EventHandler* handler : m_HandlersList)
				handler->Handle(args...);
		}

		void operator+=(EventHandler* handler)
		{
			m_HandlersList.push_back(handler);
		}
	};
}