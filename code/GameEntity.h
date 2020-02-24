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
		/// empty constructor
		GameEntity();
		/// constrcutor for setting id to the game entity
		GameEntity(Util::StringAtom entityID);
		/// empty destructor
		~GameEntity();
		/// calls every components update function
		void update();
		/// calls every components init function
		void init();
		/// calls every components shutdown function
		void shutdown();
		/// sets the ID of the game entity if not already done in constructor
		void setID(Util::StringAtom entityID);
		/// method for adding a component
		void addComponent(Util::StringAtom compName,Ptr<BaseComponent> component);
		/// method for removing a component
		void removeComponent(Util::StringAtom compName);
		/// method for getting an ID
		Util::StringAtom getID();
		/// method for receiving a message
		void onMessage(Message msg);
		///method for making the current entity a character with a certain model and transform
		void makeCharacter(Util::StringAtom modelName, Util::StringAtom tag, Util::StringAtom entityID, float x, float y, float z);
		///method for registering a varibale from component
		void registerVar(Util::StringAtom compName, Util::Array<Util::KeyValuePair<Util::StringAtom, void*>> vars);
		///method for getting a registered variable
		void* getVar(Util::StringAtom compName,Util::StringAtom varName);
		///method for removing a registered variable
		void removeVar(Util::StringAtom varName);
	private:
		Util::StringAtom ID;
		Util::HashTable<Util::StringAtom, Ptr<BaseComponent>> _components;
		Util::HashTable<Util::StringAtom, Util::Array<Util::KeyValuePair<Util::StringAtom, void*>>> componentVars;
	};

}
