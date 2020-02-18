#include "foundation/stdneb.h"
#include "Message.h"

namespace ECS
{

	__ImplementClass(Message, 'MESS', Core::RefCounted);

	Message::Message(Util::StringAtom senderID, Util::StringAtom receiverID, MessageType message, int delay, void* extraInfo)
	{
		this->senderID = senderID;
		this->receiverID = receiverID;
		this->message = message;
		this->delay = delay;
		this->extraInfo = extraInfo;
	}

	Message::Message()
	{

	}
}
