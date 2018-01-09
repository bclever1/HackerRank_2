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

	static void displayVector(vector<int>& theVector);
	static void displayVector(vector<int*>& theVector);
	static void displayStack(deque<int>& theStack);

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
	static void sort(vector<int*>& v);
	static bool isSorted(vector<int*>& v);

	static int isElementOf(vector<dataWrapper*>& v, int theData);
	static int isElementOf(vector<int*>& v, int* theData);

	static int getMaxElement(vector<int>& v, int lower, int upper);

	static long long factorial(int n);
	static long long N_Choose_M(int n, int m);

	static int primes[NUM_PRIMES];

	static int GCD(int, int);

	static vector<int> GetDigits(int n);

	static vector<vector<int>>findAllSubsets(vector<int>&);
	static vector<vector<int*>>generateAllSubsets(vector<int*>&);

	template <typename T>
	static T modpow(T base, T exp, T modulus) {
		base %= modulus;
		T result = 1;
		while (exp > 0) {
			if (exp & 1) result = (result * base) % modulus;
			base = (base * base) % modulus;
			exp >>= 1;
		}
		return result;
	}
};

