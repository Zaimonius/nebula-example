#pragma once
#include "MessageDispatcher.h"
#include "core/refcounted.h"
#include "core/rttimacros.h"
#include "Message.h"


namespace ECS
{
	


	class BaseComponent : public Core::RefCounted
	{
		__DeclareClass(BaseComponent);
	public:
		/// <summary>
		/// empty constructor
		/// </summary>
		BaseComponent();
		/// <summary>
		/// empty constructor
		/// </summary>
		~BaseComponent();
		/// <summary>
		/// virtual void init method for all components
		/// </summary>
		virtual void init() {};
		/// <summary>
		/// virtual void init method for all components
		/// </summary>
		virtual void update() {};
		/// <summary>
		/// virtual void init method for all components
		/// </summary>
		virtual void shutdown() {};
		virtual void recieveMessage(Message msg) {};
		virtual Util::HashTable<Util::StringAtom, void*> getVars() {};
	private:
	};

}

