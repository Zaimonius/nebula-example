#include "foundation/stdneb.h"
#include "EntityManager.h"

namespace ECS
{
	__ImplementSingleton(EntityManager);


	EntityManager::EntityManager()
	{
		__ConstructSingleton;
	}



	EntityManager::~EntityManager()
	{
		__DestructSingleton;
	}

	void EntityManager::update()
	{
		Util::HashTable< Util::StringAtom, Ptr<GameEntity>>::Iterator iterator = this->_entities.Begin();
		for (int i = 0; i < this->_entities.Size(); i++)
		{
			(*iterator.val)->update();
			iterator++;
		}
	}

	void EntityManager::init()
	{
		Util::HashTable< Util::StringAtom, Ptr<GameEntity>>::Iterator iterator = this->_entities.Begin();
		for (int i = 0; i < this->_entities.Size(); i++)
		{
			(*iterator.val)->init();
			iterator++;
		}
	}

	void EntityManager::shutdown()
	{
		Util::HashTable< Util::StringAtom, Ptr<GameEntity>>::Iterator iterator = this->_entities.Begin();
		for (int i = 0; i < this->_entities.Size(); i++)
		{
			(*iterator.val)->shutdown();
			iterator++;
		}
		this->_entities.Clear();
	}

	void EntityManager::createEntity(Util::StringAtom entityID, Util::Array<Ptr<BaseComponent>> components)
	{
		Ptr<GameEntity> newEntity = GameEntity::Create();
		newEntity->setID(entityID);
		for (int i = 0; i < components.Size(); i++)
		{
			newEntity->addComponent(entityID,components[i]);
		}
		this->_entities.Add(entityID, newEntity);
	}

	GameEntity* EntityManager::getEntity(Util::StringAtom key)
	{
		return this->_entities[key];
	}

	void EntityManager::createCharacter(Util::StringAtom modelName, Util::StringAtom tag, Util::StringAtom entityID, float x, float y, float z)
	{
		Ptr<GameEntity> newChar = GameEntity::Create();
		newChar->makeCharacter(modelName, tag, entityID, x, y, z);
		this->_entities.Add(entityID, newChar);
	}

}
