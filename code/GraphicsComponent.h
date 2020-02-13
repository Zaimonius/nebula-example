#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include "BaseComponent.h"
#include "graphics/graphicscontext.h"
#include "models/modelcontext.h"
#include "visibility/visibilitycontext.h"

namespace ECS
{

	class GraphicsComponent : public ECS::BaseComponent
	{
	public:
		GraphicsComponent();
		~GraphicsComponent();
		Util::KeyValuePair<Util::StringAtom, Util::Array<void*>> getVars();
	private:
		Graphics::GraphicsEntityId graphicsEntity;
	};

}