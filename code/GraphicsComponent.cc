#pragma once
#include "GraphicsComponent.h"

namespace ECS
{
	__ImplementClass(ECS::GraphicsComponent, 'GRAC', Core::RefCounted);
}

ECS::GraphicsComponent::GraphicsComponent()
{
	this->graphicsEntity = Graphics::CreateEntity();
	Graphics::RegisterEntity<Models::ModelContext, Visibility::ObservableContext>(this->graphicsEntity);
}

ECS::GraphicsComponent::~GraphicsComponent()
{

}

void ECS::GraphicsComponent::update()
{

}

void ECS::GraphicsComponent::init()
{

}

void ECS::GraphicsComponent::shutdown()
{

}

void ECS::GraphicsComponent::recieveMessage(ECS::Message msg)
{

}

Util::KeyValuePair<Util::StringAtom, Util::Array<void*>> ECS::GraphicsComponent::getVars()
{
	Util::Array<void*> arr;
	
	Util::KeyValuePair< Util::StringAtom, Util::Array<void*>> pair("graphicsEntity",arr);
	return pair;
}
