#include "stdafx.h"
#include "ThirtyDaysOfCode.h"
#include "sTestManager.h"
#include "Utilities.h"
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <regex>

ThirtyDaysOfCode::ThirtyDaysOfCode()
{
}


ThirtyDaysOfCode::~ThirtyDaysOfCode()
{
}

void ThirtyDaysOfCode::LetsReview()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();

	//TestManager* tm = new TestManager("D:\\TestCases\\connecting_towns_tc_0.txt");
	//tm->populateResults("D:\\TestCases\\connecting_towns_tc_0_results.txt");

	int numTests;

	stringstream ss;
	ss.str(tm->GetLine());
	ss >> numTests;

	for (int tc = 1; tc <= numTests; ++tc)
	{
	    stringstream ss[5];

	    ss[0].str(tm->GetLine());
	 
	    string theString = "";

		ss[0] >> theString;

		for (unsigned i = 0; i < theString.length(); ++i)
		{
			if (i % 2 == 0)
				cout << theString[i];
		}

		cout << " ";

		for (int i = 0; i < theString.length(); ++i)
		{
			if (i % 2 == 1)
				cout << theString[i];
		}

		cout << endl;
	}
}

void ThirtyDaysOfCode::Arrays()
{

}

void ThirtyDaysOfCode::DictionariesAndMaps()
{
	sTestManager* tm = new sTestManager();
	//tm->GetInput();

	int numTests = 1;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		map<string, int> myDictionary;

		string sNumEntries = "";
		int numEntries;

		getline(cin, sNumEntries);

		stringstream ss(sNumEntries);
		ss >> numEntries;

		for (int i = 0; i < numEntries; ++i)
		{
			string input = "";
			string name;
			int id;

			getline(cin, input);

			stringstream ss(input);
			ss >> name >> id;

			myDictionary[name] = id;
		}

		//string theQuery = tm->GetLine();
		string theQuery = "";

		getline(cin, theQuery);

		while (theQuery != "")
		{
			map<string, int>::iterator it = myDictionary.find(theQuery);

			if (it != myDictionary.end())
			{
				cout << it->first << "=" << it->second << endl;
			}
			else
			{
				cout << "Not found" << endl;

			}
			//theQuery = tm->GetLine();
			getline(cin, theQuery);
		}
	}
}

long long factorial(int n)
{
	if (n <= 1) return 1;
	return n * factorial(n - 1);

}

void ThirtyDaysOfCode::Recursion()
{
	int theInput;
	cin >> theInput;

	cout << factorial(theInput) << endl;
}


void ThirtyDaysOfCode::BinaryNumbers()
{
	unsigned theInput;
	cin >> theInput;
	int max1s = 0;
	int consecutive1s = 0;

	string theOutput = "";

	for (int i = 31; i >= 0; i--)
	{
		if ((theInput >> i) & 1)
			theOutput += "1";
		else
			theOutput += "0";
	}


	for (int j = 0; j < 32; ++j)
	{
		if (theOutput[j] == '1')
		{
			++consecutive1s;
			if (consecutive1s > max1s) max1s = consecutive1s;
		}
		else
		{
			consecutive1s = 0;
		}
	}

	cout << theOutput << endl;
	cout << consecutive1s << endl;
}


void ThirtyDaysOfCode::TwoDArrays()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();

	int numTests = 1;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		int rowCounter = 0;
		int theArray[6][6];

		stringstream ss[6];
		for (int i = 0; i < 6; ++i)
		{
			ss[i].str(tm->GetLine());

			for (int j = 0; j < 6; ++j)
			{
				ss[i].clear();
				ss[i] >> theArray[rowCounter][j];
			}
			++rowCounter;
		}

		//int upperLeft = 2;
		int lowerLeft = 2;

		int hourglass = 0;
		int maxHourglass = -1000;

		int rowCount = 0;

		while (rowCount + 2 < 6)
		{
			for (int right = 2; right < 6; ++right)
			{
				hourglass = theArray[rowCount][right - 2] +
							theArray[rowCount][right - 1] +
							theArray[rowCount][right] +
							theArray[rowCount + 1][right - 1] +
							theArray[rowCount + 2][right - 2] +
							theArray[rowCount + 2][right - 1] +
							theArray[rowCount + 2][right];

				if (hourglass > maxHourglass) maxHourglass = hourglass;
			}

			++rowCount;
		}

		cout << maxHourglass << endl;
	}
}

void ThirtyDaysOfCode::Exceptions()
{
	string input = "";
	cin >> input;

	try
	{
		int theResult = stoi(input);
	}
	catch (...)
	{
		cout << "Bad string" << endl;
	}

}

void ThirtyDaysOfCode::QueuesAndStacks()
{
	class Solution {
		//Write your code here
		deque<char> myStack;
		deque<char> myQueue;

	public:
		void pushCharacter(char theChar)
		{
			myStack.push_back(theChar);
		}
		char popCharacter()
		{
			char theChar = myStack.back();
			myStack.pop_back();
			return theChar;
		}
		void enqueueCharacter(char theChar)
		{
			myQueue.push_back(theChar);
		}
		char dequeueCharacter()
		{
			char theChar = myQueue.front();
			myQueue.pop_front();
			return theChar;
		}
	};

	string s;
	getline(cin, s);

	// create the Solution class object p.
	Solution obj;

	// push/enqueue all the characters of string s to stack.
	for (unsigned i = 0; i < s.length(); i++) {
		obj.pushCharacter(s[i]);
		obj.enqueueCharacter(s[i]);
	}

	bool isPalindrome = true;

	// pop the top character from stack.
	// dequeue the first character from queue.
	// compare both the characters.
	for (int i = 0; i < s.length() / 2; i++) {
		if (obj.popCharacter() != obj.dequeueCharacter()) {
			isPalindrome = false;

			break;
		}
	}

	// finally print whether string s is palindrome or not.
	if (isPalindrome) {
		cout << "The word, " << s << ", is a palindrome.";
	}
	else {
		cout << "The word, " << s << ", is not a palindrome.";
	}
}

void ThirtyDaysOfCode::RunningTimeAndComplexity()
{
	int numCases;
	cin >> numCases;

	int tc = 1;
	while (tc <= numCases)
	{
		int theVal;
		cin >> theVal;

		bool foundFactor = false;
		if (theVal == 1)
		{
			foundFactor = true;
		}
		else
		{
			int theUpperBound = sqrt(theVal);


			for (int p = 0; p < NUM_PRIMES; ++p)
			{
				if (theVal == Utilities::primes[p])
				{
					foundFactor = false;
					break;
				}
				if (theVal % Utilities::primes[p] == 0)
				{
					foundFactor = true;
					break;
				}
			}
		}
		if (foundFactor == true)
		{
			cout << "Not primne" << endl;
		}
		else
		{
			cout << "Prime" << endl;
		}

		++tc;
	}
}

class phonebookEntry
{
public:
	phonebookEntry(string& theName, string& theEmail)
	{
		name = theName;
		email = theEmail;
	}

	string name;
	string email;
};

int ThirtyDaysOfCode::Regex()
{
#if 0
	std::string s("this subject has a submarine as a subsequence");
	std::smatch m;
	std::regex e("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

	std::cout << "Target sequence: " << s << std::endl;
	std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
	std::cout << "The following matches and submatches were found:" << std::endl;

	while (std::regex_search(s, m, e)) {
		for (auto x : m) std::cout << x << " ";
		std::cout << std::endl;
		s = m.suffix().str();
	}
#endif

	int N;
	cin >> N;

	vector<phonebookEntry*>myPhonebook;
	vector<string>mySearchResults;


	for (int a0 = 0; a0 < N; a0++) {
		string firstName;
		string emailID;
		cin >> firstName >> emailID;

		myPhonebook.push_back(new phonebookEntry(firstName, emailID));
	}

	std::smatch m;
	std::regex e("\\b(@gmail.com)([^ ]*)");
	
	for (unsigned i = 0; i < myPhonebook.size(); ++i)
	{
		std::string s(myPhonebook[i]->email);
		if (std::regex_search(s, m, e))
		{
			//std::cout << s << std::endl;
			mySearchResults.push_back(myPhonebook[i]->name);
		}
	}

	Utilities::sort(mySearchResults);

	for (int i = 0; i < mySearchResults.size(); ++i)
	{
		std::cout << mySearchResults[i] << std::endl;
	}

	return 0;
}

int ThirtyDaysOfCode::BitwiseAnd()
{
	int N;
	cin >> N;

	for (int tc = 0; tc < N; ++tc)
	{
		int S, K;
		cin >> S;
		cin >> K;

		unsigned max = 0;

		for (unsigned i = 1; i < S; ++i)
		{
			for (unsigned j = i + 1; j <= S; ++j)
			{
				unsigned R = (unsigned)i & (unsigned)j;
				if (R > max && R < K)
				{
					max = R;
				}
				//std::cout << R << std::endl;
			}
		}

		std::cout << max << std::endl;
	}

	return 0;
}