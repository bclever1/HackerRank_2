#include "stdafx.h"
#include "Tries.h"

#include <iostream>

int myHashTable[27][27];

int Tries::myHash(string theString)
{
	int dim1 = theString[0] - 'a';
	int dim2 = 0;
	
	if (theString.length() >= 2)
	{
		dim2 = theString[1] - 'a';
	}
	//int dim3 = theString[2] - 'a';

	return myHashTable[dim1][dim2];
}

void initHash()
{
	int hashCounter = 0;
	for (int i = 0; i < 27; ++i)
	{
		for (int j = 0; j < 27; ++j)
		{
			myHashTable[i][j] = hashCounter++;
		}
	}
}

int find(string theParam, vector<vector<string>>&myBuckets)
{
	string theNewParam = theParam;
	char theChar = 'b';

	int doSomething = true;
	int theMatchCount = 0;
	int theHashId = 0;

	while (doSomething)
	{
		theHashId = Tries::myHash(theNewParam);

		for (int i = 0; i < myBuckets[theHashId].size(); ++i)
		{
			const char* buffer1 = theParam.c_str();

			string theSubstr = myBuckets[theHashId][i].substr(0, theParam.length());
			const char* buffer2 = theSubstr.c_str();

			int n;

			n = strcmp(buffer1, buffer2);

			if (n == 0)
			{
				++theMatchCount;
			}
		}

		if (theParam.length() == 1)
		{
			if (theChar == 'z' + 1)
			{
				break;
			}
			else
			{
				theNewParam = theParam + theChar;
				theChar++;
			}

		}
		else
		{
			break;
		}
	}

	return theMatchCount;
}

void Tries::Contacts()
{
	initHash();

	vector<vector<string>>myBuckets(27 * 27);

	sTestManager* s = new sTestManager();
	s->GetInput();

	int numCommands = atoi(s->GetLine().c_str());

	int theHashId = 0;
	int theMatchCount = 0;

	string theCommand = "";
	string theParam = "";

	vector<stringstream> theCommands(numCommands);

	for (int i = 0; i < numCommands; ++i)
	{
		theCommands[i].str(s->GetLine());
		theCommands[i] >> theCommand >> theParam;

		if (theCommand == "add")
		{
			theHashId = myHash(theParam);
			myBuckets[theHashId].push_back(theParam);
		}
		else if (theCommand == "find")
		{
			std::cout << find(theParam, myBuckets) << endl;
		}
	}
}