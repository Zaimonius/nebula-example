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

	GameEntity::GameEntity(Util::StringAtom entityID, Util::Array<BaseComponent*> components)
	{
		GameEntity::Create();
		this->ID = entityID;
		for (int i = 0; i < components.size(); i++)
		{
			this->_components.Append(components[i]);
		}
	}

	GameEntity::~GameEntity()
	{
	}

	void GameEntity::update()
	{
		for (int i = 0; i < this->_components.size(); i++)
		{
			this->_components[i]->update();
		}
	}

	void GameEntity::init()
	{
		for (int i = 0; i < this->_components.size(); i++)
		{
			this->_components[i]->init();
		}
	}

	void GameEntity::shutdown()
	{
		for (int i = 0; i < this->_components.size(); i++)
		{
			this->_components[i]->shutdown();
			delete this->_components[i];
		}
	}


	void GameEntity::setID(Util::StringAtom entityID)
	{
		this->ID = entityID;
	}

	void GameEntity::addComponent(BaseComponent* component)
	{
		this->_components.Append(component);
	}

	void GameEntity::removeComponent(BaseComponent* component)
	{
		for (int i = 0; i < this->_components.size(); i++)
		{
			if (this->_components[i] == component)
			{
				this->_components.EraseIndex(i);
			}
		}
	}

	Util::StringAtom GameEntity::getID()
	{
		return this->ID;
	}

	void GameEntity::onMessage(Message msg)
	{
	}

	GameEntity GameEntity::createCharacter(Util::StringAtom modelName, Util::StringAtom tag, Util::StringAtom entityID, float x, float y, float z)
	{
		GameEntity newChar(entityID);
		TransformComponent transformComp(x, y, z);
		GraphicsComponent graphicsComp(modelName, tag, transformComp.getTransform());
		return newChar;
	}

	void GameEntity::makeCharacter(Util::StringAtom modelName, Util::StringAtom tag, Util::StringAtom entityID, float x, float y, float z)
	{
		setID(entityID);
		Ptr<TransformComponent> transform = TransformComponent::Create();
		transform->move(x, y, z);
		Ptr<GraphicsComponent> graphics = GraphicsComponent::Create();
		graphics->registerObservable(modelName, tag, transform->getTransform());
		graphics->move(transform->getTransform());
		addComponent(transform);
		addComponent(graphics);

	}

}
