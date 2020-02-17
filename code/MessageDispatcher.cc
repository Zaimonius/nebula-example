#include "MessageDispatcher.h"

namespace ECS
{
	__ImplementClass(Message, 'MESG', Core::RefCounted);
	__ImplementClass(MessageDispatcher, 'MEDP', Core::RefCounted);

	Message::Message(Util::StringAtom senderID, Util::StringAtom receiverID, MessageType message, int delay, void* extraInfo)
	{
		this->senderID = senderID;
		this->receiverID = receiverID;
		this->message = message;
		this->delay = delay;
		this->extraInfo = extraInfo;
	}

	Message::Message()
	{

	}

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
		EntityManager::getInstance()->getEntity(msg.receiverID)->onMessage(msg);
	}

	void MessageDispatcher::SendMessage(Util::StringAtom senderID, Util::StringAtom receiverID, MessageType message, int delay, void* extraInfo)
	{
		DispatchMessage(Message(senderID, receiverID, message, delay, extraInfo));
	}

}
