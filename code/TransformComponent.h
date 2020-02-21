#pragma once
#include "BaseComponent.h"
#include "util/stringatom.h"
#include "util/array.h"
#include "math/matrix44.h"
#include "math/float4.h"
#include "Message.h"

namespace ECS
{
	
	class TransformComponent : public BaseComponent
	{
		__DeclareClass(TransformComponent);
	public:
		TransformComponent();
		TransformComponent(float x, float y, float z);
		~TransformComponent();
		void update();
		void init();
		void shutdown();
		void recieveMessage(Message msg);
		void move(float x, float y, float z);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
		Math::matrix44 getTransform();
		Util::Array<Util::KeyValuePair<Util::StringAtom, void*>> getVars();
	private:
		Math::matrix44 transform;
	};

}

