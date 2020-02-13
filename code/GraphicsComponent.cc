#pragma once
#include "GraphicsComponent.h"


ECS::GraphicsComponent::GraphicsComponent()
{
	this->graphicsEntity = Graphics::CreateEntity();
	Graphics::RegisterEntity<Models::ModelContext, Visibility::ObservableContext>(this->graphicsEntity);
}

ECS::GraphicsComponent::~GraphicsComponent()
{
}

Util::KeyValuePair<Util::StringAtom, Util::Array<void*>> ECS::GraphicsComponent::getVars()
{
	Util::Array<void*> arr;
	
	Util::KeyValuePair< Util::StringAtom, Util::Array<void*>> pair("graphicsEntity",arr);
	return pair;
}
