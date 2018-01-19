#ifndef S_TEST_MANAGER_H
#define S_TEST_MANAGER_H

#pragma once

#include <string>

using namespace std;

static const int _STDIN_MAX_INPUTS = 500000;

class sTestManager
{
public:

	sTestManager();
	~sTestManager();

	string GetLine();
	void GetInput();

private:

	int myCurrentLinePtr;
	string myInputArray[_STDIN_MAX_INPUTS];
};

#if 0

This code is for pasting into HackerRank

#include <sstream>

static const int _STDIN_MAX_INPUTS = 500000;

class sTestManager
{
public:

	sTestManager();
	~sTestManager();

	string GetLine();
	void GetInput();

private:

	int myCurrentLinePtr;
	string myInputArray[_STDIN_MAX_INPUTS];
};

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
#endif

#endif

