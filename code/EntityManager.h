#pragma once
#include "util/hashtable.h"
#include "util/stringatom.h"
#include "GameEntity.h"
#include "BaseComponent.h"

class EntityManager
{
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
	/// method for returning the entity manager instance and if it doesnt already exist, create it
	/// </summary>
	/// <returns>instance of entitymanager</returns>
	static EntityManager* getInstance();
	/// <summary>
	/// method for creating a new entity with an array of component and register it to the hash table 
	/// </summary>
	/// <param name="entityID"></param>
	/// <param name="components"></param>
	void createEntity(Util::StringAtom entityID, Util::Array<BaseComponent> components);
private:
	Util::HashTable<Util::StringAtom,GameEntity> _entities();
	static EntityManager* instance;
};

