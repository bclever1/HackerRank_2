#include "stdafx.h"
#include <fstream>
#include <iostream>

#include "TestManager.h"


using namespace::std;

TestManager::TestManager(string theFileName)
{
	int counter = 0;
	for (counter = 0; counter < MAX_FILE_SIZE; ++counter)
	{
		myInputArray[counter] = "";
	}

	myCurrentLinePtr = 0;
	ifstream myInFile(theFileName, std::ifstream::in);

	if (!myInFile)
	{
		cout << "File does not exist." << endl;
		return;
	}

	counter = 0;
	while (!myInFile.eof())
	{
		getline(myInFile, myInputArray[counter++]);
	}

	myInFile.close();

}

TestManager::TestManager()
{
	myCurrentLinePtr = 0;

	for (int i = 0; i < MAX_FILE_SIZE; ++i)
	{
		myInputArray[i] = "";
	}

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


TestManager::~TestManager()
{
}

string TestManager::GetLine()
{
	return myInputArray[myCurrentLinePtr++];

}

void TestManager::populateResults(string theFileName)
{
	ifstream resultsFile(theFileName, std::ifstream::in);

	string theLine = "";
	while (!resultsFile.eof())
	{
		getline(resultsFile, theLine);
		myExpectedResults.push_back(theLine);
	}

	resultsFile.close();
}

int min(int a, int b)
{
	if (a <= b) return a;
	return b;
}

bool TestManager::compareResult(unsigned int theTestNum, string theResult)
{
	if (theTestNum >= myExpectedResults.size()) return false;

	if (myExpectedResults[theTestNum] == theResult)
	{
		return true;
	}

	cout << "Expected result: " << endl;
	cout << myExpectedResults[theTestNum] << endl;
	cout << "Your result: " << endl;
	cout << theResult << endl;

	cout << "Your result length: " << theResult.length() << " EXP length: " << myExpectedResults[theTestNum].length() << endl;

	for (int i = 0; i < min(theResult.length(), myExpectedResults[theTestNum].length()); ++i)
	{
		if (myExpectedResults[theTestNum][i] != theResult[i])
		{
			cout << "They differ at position: " << i << endl;
			cout << "    theResult[i]:" << theResult[i] << ", " << "myExpectedResults[theTestNum][i]: " << myExpectedResults[theTestNum][i] << endl;
			break;
		}
	}

	return false;
}