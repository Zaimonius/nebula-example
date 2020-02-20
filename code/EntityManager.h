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
		/// <summary>
		/// empty constructor
		/// </summary>
		EntityManager();
		/// <summary>
		/// empty destructor
		/// </summary>
		~EntityManager();
		/// <summary>
		/// calls every components update function
		/// </summary>
		void update();
		/// <summary>
		/// calls every components init function
		/// </summary>
		void init();
		/// <summary>
		/// calls every components shutdown function
		/// </summary>
		void shutdown();
		/// <summary>
		/// method for creating a new entity with an array of component and register it to the hash table 
		/// </summary>
		/// <param name="entityID">id of the entity</param>
		/// <param name="components">the component you want the entity to have</param>
		void createEntity(Util::StringAtom entityID, Util::Array<Ptr<BaseComponent>> components);
		/// <summary>
		/// method for getting an entity from the hashtable
		/// </summary>
		/// <param name="key">the entityID you wish to get</param>
		/// <returns>an entity</returns>
		GameEntity* getEntity(Util::StringAtom key);
		void createCharacter(Util::StringAtom modelName, Util::StringAtom tag, Util::StringAtom entityID, float x, float y, float z);
	private:
		Util::HashTable<Util::StringAtom, Ptr<GameEntity>> _entities;
	};

}