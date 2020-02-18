#include "foundation/stdneb.h"
#include "GraphicsComponent.h"

namespace ECS
{

	__ImplementClass(ECS::GraphicsComponent, 'GRAC', ECS::BaseComponent);


	GraphicsComponent::GraphicsComponent()
	{

	}

	GraphicsComponent::GraphicsComponent(Util::StringAtom modelName, Util::StringAtom tag)
	{
		this->graphicsEntity = Graphics::CreateEntity();
		Graphics::RegisterEntity<Models::ModelContext, Visibility::ObservableContext>(this->graphicsEntity);
		Models::ModelContext::SetTransform(this->graphicsEntity, Math::matrix44::translation(Math::point(0, 0, 0)));
		Models::ModelContext::Setup(this->graphicsEntity, modelName, tag);
		Visibility::ObservableContext::Setup(this->graphicsEntity, Visibility::VisibilityEntityType::Model);
	}

	GraphicsComponent::~GraphicsComponent()
	{

	}

	void GraphicsComponent::update()
	{

	}

	void GraphicsComponent::init()
	{

	}

	void GraphicsComponent::shutdown()
	{

	}

	void GraphicsComponent::move(float x, float y, float z)
	{
		Models::ModelContext::SetTransform(this->graphicsEntity, Math::matrix44::translation(Math::point(x, y, z)));
	}

	void GraphicsComponent::move(Math::matrix44 transform)
	{
		Models::ModelContext::SetTransform(this->graphicsEntity, transform);
	}

	void GraphicsComponent::recieveMessage(Message msg)
	{

	}

	Util::HashTable<Util::StringAtom, void*> GraphicsComponent::getVars()
	{
		Util::HashTable<Util::StringAtom, void*> varTable;
		Graphics::GraphicsEntityId* graphicsPointer = &this->graphicsEntity;
		varTable["graphicsEntity"] = graphicsPointer;
		return varTable;
	}

}