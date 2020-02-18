#include "foundation/stdneb.h"
#include "MessageDispatcher.h"

namespace ECS
{

	__ImplementClass(MessageDispatcher, 'MEDP', Core::RefCounted);
	

	MessageDispatcher* MessageDispatcher::instance = nullptr;

	MessageDispatcher::MessageDispatcher()
	{
	}

	MessageDispatcher::~MessageDispatcher()
	{
		delete this->instance;
	}

	MessageDispatcher* MessageDispatcher::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new MessageDispatcher();
		}
		return instance;
	}

	void MessageDispatcher::DispatchMessage(Message msg)
	{
		ECS::EntityManager::getInstance()->getEntity(msg.receiverID)->onMessage(msg);
	}

	void MessageDispatcher::SendMessage(Util::StringAtom senderID, Util::StringAtom receiverID, MessageType message, int delay, void* extraInfo)
	{
		DispatchMessage(Message(senderID, receiverID, message, delay, extraInfo));
	}

}
