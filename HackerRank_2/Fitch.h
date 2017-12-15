#pragma once

#include <string>
#include <vector>

using namespace std;

class caller
{
public:
	void MakeCall();
};

enum MessageType_e
{
	MessageType_unknown = 0,
    MessageType_red = 1,
	MessageType_yellow = 2,
	MessageType_blue = 3
};

struct Message
{
	string myMessage;
	void (*myCompletionCallback);
	MessageType_e myMessageType;
	int myPriority;
};

struct Response
{
	string theMessage;
	void* myCallbackAddr;

};

class ThreadSafeClass
{
public:
	ThreadSafeClass();
	~ThreadSafeClass();

	void NewRequest(Message* theMessage);
	Message* GetRequest(MessageType_e theMessageType);

	void Test();

private:

	vector<Message*>myMessages;
};

ThreadSafeClass::ThreadSafeClass()
{
}


ThreadSafeClass::~ThreadSafeClass()
{
}

void ThreadSafeClass::NewRequest(Message* theMessage)
{
	// mutex here
	// Validate
	// add to myMessages
	// callback
	// release mutex
}

Message* ThreadSafeClass::GetRequest(MessageType_e theMessageType)
{
	// mutex here
	// search myrequests based on instructions
	// return message
	// release mutex
}

void ThreadSafeClass::Test()
{

}