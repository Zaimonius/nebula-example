#include "foundation/stdneb.h"
#include "TransformComponent.h"

namespace ECS
{

	__ImplementClass(ECS::TransformComponent, 'TRFC', ECS::BaseComponent);


	TransformComponent::TransformComponent()
	{
		this->transform.set_position(Math::point(0, 0, 0));
	}

	TransformComponent::TransformComponent(float x, float y, float z)
	{
		this->transform.set_position(Math::point(x,y,z));
	}

	TransformComponent::~TransformComponent()
	{

	}

	void TransformComponent::update()
	{

	}

	void TransformComponent::init()
	{

	}

	void TransformComponent::shutdown()
	{
	
	}

	void TransformComponent::recieveMessage(Message msg)
	{

	}

	Util::HashTable<Util::StringAtom, void*> TransformComponent::getVars()
	{
		Util::HashTable<Util::StringAtom, void*> varTable;
		Math::matrix44* varPtr = &this->transform;
		varTable["transform"] = varPtr;
		return varTable;
	}

	void TransformComponent::move(float x, float y, float z)
	{
		Math::float4 currentpos = this->transform.get_position();
		Math::float4 newpos = Math::point(x, y, z) + currentpos;
		this->transform.set_position(newpos);
	}

	void TransformComponent::rotateX(float angle)
	{
		this->transform = this->transform * Math::matrix44::rotationx(angle);
	}

	void TransformComponent::rotateY(float angle)
	{
		this->transform = this->transform * Math::matrix44::rotationy(angle);
	}

	void TransformComponent::rotateZ(float angle)
	{
		this->transform = this->transform * Math::matrix44::rotationz(angle);
	}

	Math::matrix44 TransformComponent::getTransform()
	{
		return this->transform;
	}

	Util::KeyValuePair<Util::StringAtom, void*> TransformComponent::getVar()
	{
		Math::matrix44* transformPointer = &this->transform;
		Util::KeyValuePair<Util::StringAtom, void*> var("transform", transformPointer);
		return var;
	}


}
