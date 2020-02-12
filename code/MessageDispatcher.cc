#pragma once
#include "MessageDispatcher.h"



MessageDispatcher::MessageDispatcher()
{
	this->instance = 0;
}

MessageDispatcher::~MessageDispatcher()
{
	delete this->instance;
}

MessageDispatcher* MessageDispatcher::getInstance()
{
	if (instance == 0)
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
