#pragma once
#include "core/refcounted.h"
#include "core/rttimacros.h"
#include "Message.h"


namespace ECS
{
	
	class BaseComponent : public Core::RefCounted
	{
		__DeclareAbstractClass(BaseComponent);
	public:
		/// <summary>
		/// virtual void init method for all components
		/// </summary>
		virtual void init() = 0;
		/// <summary>
		/// virtual void init method for all components
		/// </summary>
		virtual void update() = 0;
		/// <summary>
		/// virtual void init method for all components
		/// </summary>
		virtual void shutdown() = 0;
		virtual void recieveMessage(Message msg) = 0;
		virtual Util::HashTable<Util::StringAtom, void*> getVars() = 0;
	private:
	};

}

