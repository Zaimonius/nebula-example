#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include "BaseComponent.h"

class GameEntity
{
public:
	/// <summary>
	/// empty constructor
	/// </summary>
	GameEntity();
	/// <summary>
	/// constrcutor for setting id to the game entity
	/// </summary>
	/// <param name="entityID">id for the entity as a string</param>
	GameEntity(Util::StringAtom entityID);
	/// <summary>
	/// constructor for both a component list and an id
	/// </summary>
	/// <param name="entityID">entity ID</param>
	/// <param name="components">component list(util array)</param>
	GameEntity(Util::StringAtom entityID, Util::Array<BaseComponent*> components);
	/// <summary>
	/// empty destructor
	/// </summary>
	~GameEntity();
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
	/// sets the ID of the game entity if not already done in constructor
	/// </summary>
	/// <param name="entityID">the entityid</param>
	void setID(Util::StringAtom entityID);
	/// <summary>
	/// method for adding a component
	/// </summary>
	/// <param name="component">pointer to the component you want to add</param>
	void addComponent(BaseComponent* component);
	/// <summary>
	/// method for removing a component
	/// </summary>
	/// <param name="component">pointer to the component you want to remove</param>
	void removeComponent(BaseComponent* component);
	Util::StringAtom ID;
private:
	Util::Array<BaseComponent*> _components;
};

