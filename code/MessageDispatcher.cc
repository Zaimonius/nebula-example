#include "foundation/stdneb.h"
#include "MessageDispatcher.h"

namespace ECS
{
	__ImplementSingleton(MessageDispatcher);


	MessageDispatcher::MessageDispatcher()
	{
		__ConstructSingleton;
	}

	MessageDispatcher::~MessageDispatcher()
	{
		__DestructSingleton;
	}

	void MessageDispatcher::DispatchMessage(Message msg)
	{
		ECS::EntityManager::Instance()->getEntity(msg.receiverID)->onMessage(msg);
	}

	void MessageDispatcher::SendMessage(Util::StringAtom senderID, Util::StringAtom receiverID, MessageType message, int delay, void* extraInfo)
	{
		DispatchMessage(Message(senderID, receiverID, message, delay, extraInfo));
	}

}
