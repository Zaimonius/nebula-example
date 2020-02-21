#include "foundation/stdneb.h"
#include "GameEntity.h"


namespace ECS
{
	__ImplementClass(ECS::GameEntity, 'GMEN', Core::RefCounted);


	GameEntity::GameEntity()
	{

	}

	GameEntity::GameEntity(Util::StringAtom entityID)
	{
		this->ID = entityID;
	}


	GameEntity::~GameEntity()
	{
	}

	void GameEntity::update()
	{
		Util::HashTable< Util::StringAtom, Ptr<BaseComponent>>::Iterator iterator = this->_components.Begin();
		for (int i = 0; i < this->_components.Size(); i++)
		{
			(*iterator.val)->update();
			iterator++;
		}
	}

	void GameEntity::init()
	{
		///register component vars here!!!
		Util::HashTable< Util::StringAtom, Ptr<BaseComponent>>::Iterator iterator = this->_components.Begin();
		for (int i = 0; i < this->_components.Size(); i++)
		{
			(*iterator.val)->init();
			iterator++;
		}
	}

	void GameEntity::shutdown()
	{
		Util::HashTable< Util::StringAtom, Ptr<BaseComponent>>::Iterator iterator = this->_components.Begin();
		for (int i = 0; i < this->_components.Size(); i++)
		{
			(*iterator.val)->shutdown();
			iterator++;
		}
		this->_components.Clear();
		this->componentVars.Clear();
	}


	void GameEntity::setID(Util::StringAtom entityID)
	{
		this->ID = entityID;
	}

	void GameEntity::addComponent(Util::StringAtom compName, Ptr<BaseComponent> component)
	{
		this->_components.Add(compName, component);
		this->registerVar(compName,component->getVars());
	}

	void GameEntity::removeComponent(Util::StringAtom compName)
	{
		this->componentVars.Erase(compName);
		this->_components.Erase(compName);
	}

	Util::StringAtom GameEntity::getID()
	{
		return this->ID;
	}

	void GameEntity::onMessage(Message msg)
	{

	}

	void GameEntity::makeCharacter(Util::StringAtom modelName, Util::StringAtom tag, Util::StringAtom entityID, float x, float y, float z)
	{
		this->setID(entityID);
		Ptr<TransformComponent> transform = TransformComponent::Create();
		transform->move(x, y, z);
		Ptr<GraphicsComponent> graphics = GraphicsComponent::Create();
		graphics->registerObservable(modelName, tag, transform->getTransform());
		graphics->move(transform->getTransform());
		this->addComponent("transform",transform);
		this->addComponent("graphics",graphics);
	}

	void GameEntity::registerVar(Util::StringAtom compName, Util::Array<Util::KeyValuePair<Util::StringAtom,void*>> vars)
	{
		if (this->componentVars.Contains(compName))
		{
			for (int i = 0; i < this->componentVars[compName].Size(); i++)
			{
				if (this->componentVars[compName].Find())
				{
					//check if in table else add...
				}
			}
		}
		this->componentVars.Add(compName,vars);
	}

	void* GameEntity::getVar(Util::StringAtom compName,Util::StringAtom varName)
	{
		for (int i = 0; i < this->componentVars[compName].Size(); i++)
		{
			if (this->componentVars[compName][i].Key() == varName)
			{
				return this->componentVars[compName][i].Value();
			}
		}
		return nullptr;
	}

	void GameEntity::removeVar(Util::StringAtom varName)
	{
		this->componentVars.Erase(varName);
	}

}
