#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include "BaseComponent.h"
#include "MessageDispatcher.h"
#include "core/refcounted.h"
#include "core/rttimacros.h"
#include "GraphicsComponent.h"
#include "TransformComponent.h"



namespace ECS
{
	class BaseComponent;

	class GameEntity : public Core::RefCounted
	{
		__DeclareClass(GameEntity);
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
		/// <summary>
		/// method for getting an ID
		/// </summary>
		/// <returns>the </returns>
		Util::StringAtom getID();
		/// <summary>
		/// method for receiving a message
		/// </summary>
		/// <param name="msg">the message received</param>
		void onMessage(Message msg); 
		static GameEntity createCharacter(Util::StringAtom modelName, Util::StringAtom tag, Util::StringAtom entityID, float x, float y, float z);
	private:
		Util::StringAtom ID;
		Util::Array<BaseComponent*> _components;
		Util::HashTable<Util::StringAtom, Util::Array<void*>> componentVars;
	};

}
