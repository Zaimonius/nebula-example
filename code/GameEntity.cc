#include "GameEntity.h"


namespace ECS
{
	__ImplementClass(GameEntity, 'GMEN', Core::RefCounted);


	GameEntity::GameEntity()
	{
	}

	GameEntity::GameEntity(Util::StringAtom entityID)
	{
		this->ID = entityID;
	}

	GameEntity::GameEntity(Util::StringAtom entityID, Util::Array<BaseComponent*> components)
	{
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

	GameEntity GameEntity::createCharacter(Util::StringAtom modelName, Util::StringAtom tag, Util::StringAtom entityID, Math::point pos)
	{
		GameEntity newChar(entityID);
		TransformComponent transformComp(pos.x, pos.y, pos.z);
		GraphicsComponent graphicsComp(modelName, tag);
		graphicsComp.move(transformComp.getTransform());
		return newChar;
	}

}
