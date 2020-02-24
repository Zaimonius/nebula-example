#pragma once
#include "BaseComponent.h"
#include "util/stringatom.h"
#include "util/array.h"
#include "graphics/graphicscontext.h"
#include "models/modelcontext.h"
#include "visibility/visibilitycontext.h"
#include "Message.h"



namespace ECS
{

	class GraphicsComponent : public BaseComponent
	{
		__DeclareClass(GraphicsComponent);
	public:
		GraphicsComponent();
		///constructor for creating the graphics entity with model name, tag and transform
		GraphicsComponent(Util::StringAtom modelName, Util::StringAtom tag, Math::matrix44 transform);
		~GraphicsComponent();
		///gets called every frame
		void update();
		///initialization
		void init();
		///shutdown
		void shutdown();
		///sets the graphicsentitys transform in form of a point
		void move(float x,float y, float z);
		///sets the graphicsentitys transform
		void move(Math::matrix44 transform);
		///method for receiving messages
		void recieveMessage(Message msg);
		///method for doing the same thing as the first constructor
		void registerObservable(Util::StringAtom modelName, Util::StringAtom tag,Math::matrix44 transform);
		///returns an array of the components variables
		Util::Array<Util::KeyValuePair<Util::StringAtom, void*>> getVars();
	private:
		Graphics::GraphicsEntityId graphicsEntity;
	};

}

