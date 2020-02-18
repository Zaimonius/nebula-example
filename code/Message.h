#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include "core/refcounted.h"
#include "core/rttimacros.h"




namespace ECS
{
	enum MessageType
	{
		MSG_MSG
	};

	class Message : public Core::RefCounted
	{
		__DeclareClass(Message);
	public:
		Util::StringAtom senderID;
		Util::StringAtom receiverID;
		MessageType message;
		float delay;
		void* extraInfo;
		Message(Util::StringAtom senderID, Util::StringAtom receiverID, MessageType message, int delay, void* extraInfo);
		Message();
	};
}
