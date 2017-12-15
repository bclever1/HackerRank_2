#include "stdafx.h"
#include <iostream>

#include "sTestManager.h"

using namespace::std;

sTestManager::sTestManager()
{
	myCurrentLinePtr = 0;
}

sTestManager::~sTestManager()
{
}

string sTestManager::GetLine()
{
	return myInputArray[myCurrentLinePtr++];
}

void sTestManager::GetInput()
{
	int counter = 0;

	std::string line;
	while (getline(cin, line))
	{
		//getline(cin, myInputArray[counter++]);
		if (line == "")
		{
			break;
		}
		else
		{
			myInputArray[counter++] = line;
		}
	}
}