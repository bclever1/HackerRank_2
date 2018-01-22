#pragma once

#include <vector>
#include <deque>

using namespace std;

class dataWrapper;

const int NUM_PRIMES = 168;

class Utilities
{
public:
	Utilities();
	~Utilities();

	static void display(vector<int>& theVector);
	static void display(deque<int>& theStack);

	static bool isPairedChar(char theLChar, char theRChar)
	{
		if (theLChar == '{' && theRChar == '}') return true;
		if (theLChar == '[' && theRChar == ']') return true;
		if (theLChar == '(' && theRChar == ')') return true;

		return false;
	}

	static int getRunningSum(vector<int>& v, int theIndex)
	{
		int theResult = 0;
		for (int i = 0; i <= theIndex; ++i)
		{
			theResult += v[i];
		}

		return theResult;
	}

	static void sort(vector<int>& v);
	static bool isSorted(vector<int>& v);
	static void sort(vector<string>& v);
	static bool isSorted(vector<string>& v);

	static void sort(deque<int>& v);
	static bool isSorted(deque<int>& v);


	static int isElementOf(vector<dataWrapper*>& v, int theData);

	static int getMaxElement(vector<int>& v, int lower, int upper);

	static long long factorial(int n);
	static long long N_Choose_M(int n, int m);

	static int primes[NUM_PRIMES];

	static int GCD(int, int);

	static vector<int> GetDigits(int n);

	static void orderedInsertAt(deque<int>& d, int pos1, int pos2, int theVal);
};

