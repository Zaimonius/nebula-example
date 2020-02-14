#pragma once
#include "EntityManager.h"

namespace ECS
{
	__ImplementClass(ECS::EntityManager, 'ENTM', Core::RefCounted);
}

ECS::EntityManager::EntityManager()
{
}

ECS::EntityManager* ECS::EntityManager::instance = nullptr;


ECS::EntityManager::~EntityManager()
{
	delete this->instance;
}

void ECS::EntityManager::update()
{
	Util::HashTable< Util::StringAtom, ECS::GameEntity*>::Iterator iterator = this->_entities.Begin();
	for (int i = 0; i < this->_entities.Size(); i++)
	{
		(*iterator.val)->update();
		iterator++;
	}
}

void ECS::EntityManager::init()
{
	Util::HashTable< Util::StringAtom, ECS::GameEntity*>::Iterator iterator = this->_entities.Begin();
	for (int i = 0; i < this->_entities.Size(); i++)
	{
		(*iterator.val)->init();
		iterator++;
	}
}

void ECS::EntityManager::shutdown()
{
	Util::HashTable< Util::StringAtom, ECS::GameEntity*>::Iterator iterator = this->_entities.Begin();
	for (int i = 0; i < this->_entities.Size(); i++)
	{
		(*iterator.val)->shutdown();
		iterator++;
	}
	this->_entities.Clear();
}

ECS::EntityManager* ECS::EntityManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new EntityManager();
	}
	return instance;
}

void ECS::EntityManager::createEntity(Util::StringAtom entityID,Util::Array<BaseComponent> components)
{
	ECS::GameEntity *newEntity = new ECS::GameEntity(entityID);

	this->_entities.Add(entityID, newEntity);
}

ECS::GameEntity* ECS::EntityManager::getEntity(Util::StringAtom key)
{
	return this->_entities[key];
}
