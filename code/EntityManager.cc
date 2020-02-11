#pragma once
#include "EntityManager.h"

EntityManager::EntityManager()
{
	this->instance = 0;
}

EntityManager::~EntityManager()
{
}

void EntityManager::update()
{
	Util::HashTable< Util::StringAtom, GameEntity>::Iterator iterator = this->_entities.begin();
	for (int i = 0; i < this->_entities.size(); i++)
	{
		iterator.val->update();
		iterator++;
	}
}

void EntityManager::init()
{
	Util::HashTable< Util::StringAtom, GameEntity>::Iterator iterator = this->_entities.begin();
	for (int i = 0; i < this->_entities.size(); i++)
	{
		iterator.val->init();
		iterator++;
	}
}

void EntityManager::shutdown()
{
	Util::HashTable< Util::StringAtom, GameEntity>::Iterator iterator = this->_entities.begin();
	for (int i = 0; i < this->_entities.size(); i++)
	{
		iterator.val->shutdown();
		iterator++;
	}
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

	this->_entities->Add(entityID, newEntity);
}
