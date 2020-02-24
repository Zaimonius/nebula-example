#pragma once
#include "util/hashtable.h"
#include "util/stringatom.h"
#include "GameEntity.h"
#include "BaseComponent.h"
#include "core/refcounted.h"
#include "core/rttimacros.h"
#include <iostream>

namespace ECS
{

	class BaseComponent;
	class GameEntity;


	class EntityManager
	{
		__DeclareSingleton(EntityManager);
	public:
		/// empty constructor
		EntityManager();
		/// empty destructor
		~EntityManager();
		/// calls every components update function
		void update();
		/// calls every components init function
		void init();
		/// calls every components shutdown function
		void shutdown();
		/// method for creating a new entity with an array of component and register it to the hash table 
		void createEntity(Util::StringAtom entityID, Util::Array<Ptr<BaseComponent>> components);
		/// method for getting an entity from the hashtable
		GameEntity* getEntity(Util::StringAtom key);
		///method for creating a new entity and insreting it into the hashtable
		void createCharacter(Util::StringAtom modelName, Util::StringAtom tag, Util::StringAtom entityID, float x, float y, float z);
	private:
		Util::HashTable<Util::StringAtom, Ptr<GameEntity>> _entities;
	};

}