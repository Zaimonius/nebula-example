#pragma once
#include "MessageDispatcher.h"

namespace ECS
{
	__ImplementClass(ECS::MessageDispatcher, 'MEDP', Core::RefCounted);
}

ECS::MessageDispatcher* ECS::MessageDispatcher::instance = nullptr;

ECS::MessageDispatcher::MessageDispatcher()
{
}

ECS::MessageDispatcher::~MessageDispatcher()
{
	delete this->instance;
}

ECS::MessageDispatcher* ECS::MessageDispatcher::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ECS::MessageDispatcher();
	}
	return instance;
}

void ECS::MessageDispatcher::DispatchMessage(ECS::Message msg)
{
	ECS::EntityManager::getInstance()->getEntity(msg.receiverID)->onMessage(msg);
}

void ECS::MessageDispatcher::SendMessage(Util::StringAtom senderID, Util::StringAtom receiverID, ECS::MessageType message, int delay, void* extraInfo)
{
	DispatchMessage(ECS::Message(senderID, receiverID, message, delay, extraInfo));
}

