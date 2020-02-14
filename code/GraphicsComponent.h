#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include "BaseComponent.h"
#include "graphics/graphicscontext.h"
#include "models/modelcontext.h"
#include "visibility/visibilitycontext.h"
#include "core/refcounted.h"
#include "core/rttimacros.h"

namespace ECS
{

	class GraphicsComponent : public ECS::BaseComponent
	{
		__DeclareClass(ECS::GraphicsComponent);
	public:
		GraphicsComponent();
		~GraphicsComponent();
		void update();
		void init();
		void shutdown();
		void recieveMessage(ECS::Message msg);
		Util::KeyValuePair<Util::StringAtom, Util::Array<void*>> getVars();
	private:
		Graphics::GraphicsEntityId graphicsEntity;
	};

}