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
		///constructor for setting a transform
		TransformComponent(float x, float y, float z);
		~TransformComponent();
		///update gets called once per second
		void update();
		///initializaton 
		void init();
		///shutdown
		void shutdown();
		///method for receiving a message
		void recieveMessage(Message msg);
		///method for moving the transform
		void move(float x, float y, float z);
		///method for rotating the transform in x-axis
		void rotateX(float angle);
		///method for rotating the transform in y-axis
		void rotateY(float angle);
		///method for rotating the transform in z-axis
		void rotateZ(float angle);
		///returns transform
		Math::matrix44 getTransform();
		///returns all the variables in form of an array with keyvalue pairs
		Util::Array<Util::KeyValuePair<Util::StringAtom, void*>> getVars();
	private:
		Math::matrix44 transform;
	};

}

