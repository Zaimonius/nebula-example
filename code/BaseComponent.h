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
		/// virtual void init method for all components
		virtual void init() = 0;
		/// virtual void update method for all components
		virtual void update() = 0;
		/// virtual void shutdown method for all components
		virtual void shutdown() = 0;
		///virtual void method for all components to receive messages
		virtual void recieveMessage(Message msg) = 0;
		///virtual method for getting a components variables as an array
		virtual Util::Array<Util::KeyValuePair<Util::StringAtom,void*>> getVars() = 0;
	private:
	};

}

