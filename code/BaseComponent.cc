#pragma once
#include "BaseComponent.h"

namespace ECS
{
	__ImplementAbstractClass(ECS::BaseComponent, 'BASC', Core::RefCounted);
}

ECS::BaseComponent::BaseComponent()
{
}

ECS::BaseComponent::~BaseComponent()
{
}