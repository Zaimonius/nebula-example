#pragma once
#include "util/stringatom.h"
#include "util/array.h"
#include "BaseComponent.h"
#include "GameEntity.h"
#include "EntityManager.h"
#include <chrono>


namespace ECS
{

	enum MessageType
	{
		MSG_MSG
	};

	struct Message
	{
		Util::StringAtom senderID;
		Util::StringAtom receiverID;
		ECS::MessageType message;
		float delay;
		void* extraInfo;
		Message(Util::StringAtom senderID, Util::StringAtom receiverID, ECS::MessageType message, int delay, void* extraInfo)
		{
			this->senderID = senderID;
			this->receiverID = receiverID;
			this->message = message;
			this->delay = delay;
			this->extraInfo = extraInfo;
		}
	};

	class MessageDispatcher
	{
	public:
		/// <summary>
		/// empty constructor
		/// </summary>
		MessageDispatcher();
		/// <summary>
		/// deletes the instance
		/// </summary>
		~MessageDispatcher();
		/// <summary>
		/// singleton get instance
		/// </summary>
		/// <returns>an instance of the message dispatcher</returns>
		ECS::MessageDispatcher* getInstance();
		/// <summary>
		/// sends the message to th entity
		/// </summary>
		/// <param name="msg">the message you want to send</param>
		void DispatchMessage(Message msg);
		/// <summary>
		/// method for constucting a message and then sending it
		/// </summary>
		/// <param name="senderID">id string of the sender</param>
		/// <param name="receiverID">id string of the receiver</param>
		/// <param name="message">message type</param>
		/// <param name="delay">the dealy of the message</param>
		/// <param name="extraInfo">extra info if you want</param>
		void SendMessage(Util::StringAtom senderID, Util::StringAtom receiverID, ECS::MessageType message, int delay, void* extraInfo);
	private:
		static ECS::MessageDispatcher* instance;
	};

}
