#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include <chrono>
#include "core/refcounted.h"
#include "core/rttimacros.h"
#include "EntityManager.h"
#include "Message.h"


namespace ECS
{
	

	class MessageDispatcher : public Core::RefCounted
	{
		__DeclareSingleton(MessageDispatcher);
	public:
		/// empty constructor
		MessageDispatcher();
		/// deletes the instance
		~MessageDispatcher();
		/// sends the message to th entity
		void DispatchMessage(Message msg);
		/// method for constucting a message and then sending it
		void SendMessage(Util::StringAtom senderID, Util::StringAtom receiverID, MessageType message, int delay, void* extraInfo);
	private:
	};

}
