#pragma once
#include "MessageDispatcher.h"
#include "core/refcounted.h"
#include "core/rttimacros.h"

namespace ECS
{
	struct Message;


	class BaseComponent : public Core::RefCounted
	{
		__DeclareAbstractClass(ECS::BaseComponent);
	public:
		/// <summary>
		/// empty constructor
		/// </summary>
		BaseComponent();
		/// <summary>
		/// empty constructor
		/// </summary>
		~BaseComponent();
		/// <summary>
		/// virtual void init method for all components
		/// </summary>
		virtual void init() = 0;
		/// <summary>
		/// virtual void init method for all components
		/// </summary>
		virtual void update() = 0;
		/// <summary>
		/// virtual void init method for all components
		/// </summary>
		virtual void shutdown() = 0;
		virtual void recieveMessage(ECS::Message msg) = 0;
		virtual Util::Array<BaseComponent*> getVars() = 0;
	private:
	};

}