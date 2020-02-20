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
		GraphicsComponent(Util::StringAtom modelName, Util::StringAtom tag, Math::matrix44 transform);
		~GraphicsComponent();
		void update();
		void init();
		void shutdown();
		void move(float x,float y, float z);
		void move(Math::matrix44 transform);
		void recieveMessage(Message msg);
		void registerObservable(Util::StringAtom modelName, Util::StringAtom tag,Math::matrix44 transform);
		Util::KeyValuePair<Util::StringAtom, void*> getVar();
	private:
		Graphics::GraphicsEntityId graphicsEntity;
	};

}

