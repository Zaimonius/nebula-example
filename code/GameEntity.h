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
		void addComponent(Util::StringAtom compName,Ptr<BaseComponent> component);
		/// <summary>
		/// method for removing a component
		/// </summary>
		/// <param name="component">pointer to the component you want to remove</param>
		void removeComponent(Util::StringAtom compName);
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
		void makeCharacter(Util::StringAtom modelName, Util::StringAtom tag, Util::StringAtom entityID, float x, float y, float z);
		void addVar(Util::KeyValuePair<Util::StringAtom, void*> var);
		void* getVar(Util::StringAtom varName);
		void removeVar(Util::StringAtom varName);
	private:
		Util::StringAtom ID;
		Util::HashTable<Util::StringAtom, Ptr<BaseComponent>> _components;
		Util::HashTable<Util::StringAtom, void*> componentVars;
	};

}
