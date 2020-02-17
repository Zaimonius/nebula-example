#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include "BaseComponent.h"
#include "MessageDispatcher.h"
#include "graphics/graphicscontext.h"
#include "models/modelcontext.h"
#include "visibility/visibilitycontext.h"
#include "core/refcounted.h"
#include "core/rttimacros.h"

namespace ECS
{
	class GraphicsComponent : public BaseComponent
	{
		__DeclareClass(GraphicsComponent);
	public:
		GraphicsComponent();
		GraphicsComponent(Util::StringAtom modelName, Util::StringAtom tag);
		~GraphicsComponent();
		void update();
		void init();
		void shutdown();
		void move(float x,float y, float z);
		void move(Math::matrix44 transform);
		void recieveMessage(Message msg);
		Util::HashTable<Util::StringAtom, void*> getVars();
	private:
		Graphics::GraphicsEntityId graphicsEntity;
	};

}

