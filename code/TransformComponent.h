#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include "BaseComponent.h"
#include "core/refcounted.h"
#include "core/rttimacros.h"
#include "math/matrix44.h"

namespace ECS
{

	class TransformComponent : public ECS::BaseComponent
	{
		__DeclareClass(ECS::TransformComponent);
	public:
		TransformComponent();
		~TransformComponent();
		void update();
		void init();
		void shutdown();
		void recieveMessage(ECS::Message msg);
		Util::Array<BaseComponent*> getVars();
		void move(float x, float y, float z);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
	private:
		Math::matrix44 transform;
	};

}