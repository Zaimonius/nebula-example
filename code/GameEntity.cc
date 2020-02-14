#pragma once
#include "GameEntity.h"
#include "core/rttimacros.h"

namespace ECS
{
	__ImplementClass(ECS::GameEntity, 'GMEN', Core::RefCounted);
}

ECS::GameEntity::GameEntity()
{
}

ECS::GameEntity::GameEntity(Util::StringAtom entityID)
{
	this->ID = entityID;
}

ECS::GameEntity::GameEntity(Util::StringAtom entityID, Util::Array<ECS::BaseComponent*> components)
{
	this->ID = entityID;
	for (int i = 0; i < components.size(); i++)
	{
		this->_components.Append(components[i]);
	}
}

ECS::GameEntity::~GameEntity()
{
}

void ECS::GameEntity::update()
{
	for (int i = 0; i < this->_components.size(); i++)
	{
		this->_components[i]->update();
	}
}

void ECS::GameEntity::init()
{
	for (int i = 0; i < this->_components.size(); i++)
	{
		this->_components[i]->init();
	}
}

void ECS::GameEntity::shutdown()
{
	for (int i = 0; i < this->_components.size(); i++)
	{
		this->_components[i]->shutdown();
		delete this->_components[i];
	}
}

void ECS::GameEntity::setID(Util::StringAtom entityID)
{
	this->ID = entityID;
}

void ECS::GameEntity::addComponent(ECS::BaseComponent* component)
{
	this->_components.Append(component);
}

void ECS::GameEntity::removeComponent(ECS::BaseComponent* component)
{
	for (int i = 0; i < this->_components.size(); i++)
	{
		if (this->_components[i] == component)
		{
			this->_components.EraseIndex(i);
		}
	}
}

Util::StringAtom ECS::GameEntity::getID()
{
	return this->ID;
}

void ECS::GameEntity::onMessage(ECS::Message msg)
{
}
