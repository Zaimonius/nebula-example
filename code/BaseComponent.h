#pragma once
#include "MessageDispatcher.h"

class BaseComponent
{
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
	virtual void recieveMessage(Message msg) = 0;
private:
};