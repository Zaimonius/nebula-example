#pragma once
#include "EntityManager.h"

EntityManager::EntityManager()
{
	this->instance = 0;
}

EntityManager::~EntityManager()
{
	delete this->instance;
}

void EntityManager::update()
{
	Util::HashTable< Util::StringAtom, GameEntity*>::Iterator iterator = this->_entities.Begin();
	for (int i = 0; i < this->_entities.Size(); i++)
	{
		(*iterator.val)->update();
		iterator++;
	}
}

void EntityManager::init()
{
	Util::HashTable< Util::StringAtom, GameEntity*>::Iterator iterator = this->_entities.Begin();
	for (int i = 0; i < this->_entities.Size(); i++)
	{
		(*iterator.val)->init();
		iterator++;
	}
}

void EntityManager::shutdown()
{
	Util::HashTable< Util::StringAtom, GameEntity*>::Iterator iterator = this->_entities.Begin();
	for (int i = 0; i < this->_entities.Size(); i++)
	{
		(*iterator.val)->shutdown();
		iterator++;
	}
	this->_entities.Clear();
}

EntityManager* EntityManager::getInstance()
{
	if (instance == 0)
	{
		instance = new EntityManager();
	}
	return instance;
}

void EntityManager::createEntity(Util::StringAtom entityID,Util::Array<BaseComponent> components)
{
	GameEntity *newEntity = new GameEntity(entityID);

	this->_entities.Add(entityID, newEntity);
}

GameEntity* EntityManager::getEntity(Util::StringAtom key)
{
	return this->_entities[key];
}
