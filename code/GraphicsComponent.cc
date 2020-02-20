#include "foundation/stdneb.h"
#include "GraphicsComponent.h"

namespace ECS
{

	__ImplementClass(ECS::GraphicsComponent, 'GRAC', ECS::BaseComponent);

	GraphicsComponent::GraphicsComponent()
	{

	}

	GraphicsComponent::GraphicsComponent(Util::StringAtom modelName, Util::StringAtom tag,Math::matrix44 transform)
	{
		this->graphicsEntity = Graphics::CreateEntity();
		Graphics::RegisterEntity<Models::ModelContext, Visibility::ObservableContext>(this->graphicsEntity);
		Models::ModelContext::SetTransform(this->graphicsEntity, transform);
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

	void GraphicsComponent::registerObservable(Util::StringAtom modelName, Util::StringAtom tag, Math::matrix44 transform)
	{
		this->graphicsEntity = Graphics::CreateEntity();
		Graphics::RegisterEntity<Models::ModelContext, Visibility::ObservableContext>(this->graphicsEntity);
		Models::ModelContext::SetTransform(this->graphicsEntity, transform);
		Models::ModelContext::Setup(this->graphicsEntity, modelName, tag);
		Visibility::ObservableContext::Setup(this->graphicsEntity, Visibility::VisibilityEntityType::Model);
	}

	Util::KeyValuePair<Util::StringAtom, void*> GraphicsComponent::getVar()
	{
		Graphics::GraphicsEntityId* graphicsPointer = &this->graphicsEntity;
		Util::KeyValuePair<Util::StringAtom, void*> var("graphics", graphicsPointer);
		return var;
	}

}