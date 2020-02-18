#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include "math/matrix44.h"
#include "math/float4.h"
#include "BaseComponent.h"
#include "Message.h"

namespace ECS
{
	
	class TransformComponent : public ECS::BaseComponent
	{
		__DeclareClass(ECS::TransformComponent);
	public:
		TransformComponent();
		TransformComponent(float x, float y, float z);
		~TransformComponent();
		void update();
		void init();
		void shutdown();
		void recieveMessage(Message msg);
		Util::HashTable<Util::StringAtom, void*> getVars();
		void move(float x, float y, float z);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
		Math::matrix44 getTransform();
	private:
		Math::matrix44 transform;
	};

}

