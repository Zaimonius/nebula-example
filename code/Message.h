#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include "core/refcounted.h"
#include "core/rttimacros.h"




namespace ECS
{
	enum class MessageType
	{
		MSG_MSG
	};

	class Message : public Core::RefCounted
	{
	public:
		Util::StringAtom senderID;
		Util::StringAtom receiverID;
		MessageType message;
		float delay;
		void* extraInfo;
		///standard constructor for setting all the values
		Message(Util::StringAtom senderID, Util::StringAtom receiverID, MessageType message, int delay, void* extraInfo);
		Message();
	};
}

