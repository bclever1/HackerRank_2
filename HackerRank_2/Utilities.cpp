#include "stdafx.h"
#include "Utilities.h"
#include <vector>
#include <stack>
#include <iostream>
#include "dataWrapper.h"
#include <string>

using namespace std;

Utilities::Utilities()
{
}


Utilities::~Utilities()
{
}

int Utilities::primes[NUM_PRIMES] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

//-----------------------------------------------------------//
void Utilities::displayVector(vector<int>& theVector)
{
	cout << endl;
	for (unsigned int i = 0; i < theVector.size(); ++i)
	{
		cout << theVector[i];

		if (i < theVector.size() - 1)
		{
			cout << " ";
		}
	}

	cout << endl;
}

//-----------------------------------------------------------//
void Utilities::displayStack(deque<int>& theStack)
{
	for (unsigned int i = 0; i < theStack.size(); ++i)
	{
		cout << theStack[i];

		if (i < theStack.size() - 1)
		{
			cout << " ";
		}
	}

	cout << endl;
}

//-----------------------------------------------------------//
bool Utilities::isSorted(vector<int>& v)
{
	for (unsigned int i = 0; i < v.size() - 1; ++i)
	{
		if (v[i] > v[i + 1]) return false;
	}

	return true;

}

//-----------------------------------------------------------//
void Utilities::sort(vector<int>& v)
{
	if (v.size() == 0) return;

	int temp = 0;

	while (!Utilities::isSorted(v))
	{
		for (unsigned int i = 0; i < v.size() - 1; ++i)
		{
			if (v[i] > v[i + 1])
			{
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
	}
}


//-----------------------------------------------------------//
bool Utilities::isSorted(vector<string>& v)
{
	for (unsigned int i = 0; i < v.size() - 1; ++i)
	{
		if (v[i] > v[i + 1]) return false;
	}

	return true;

}

//-----------------------------------------------------------//
void Utilities::sort(vector<string>& v)
{
	if (v.size() == 0) return;

	string temp = "";

	while (!Utilities::isSorted(v))
	{
		for (unsigned int i = 0; i < v.size() - 1; ++i)
		{
			if (v[i] > v[i + 1])
			{
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
	}
}

//-----------------------------------------------------------//
int Utilities::isElementOf(vector<dataWrapper*>& v, int theData)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		if (v[i]->myData == theData)
		{
			return i;
		}
	}

	return -1;
}

//-----------------------------------------------------------//
int Utilities::getMaxElement(vector<int>& v, int lower, int upper)
{
	int theResult = v[lower];

	for (int i = lower + 1; i <= upper; ++i)
	{
		if (v[i] > theResult) theResult = v[i];
	}

	return theResult;

}

//-----------------------------------------------------------//
long long Utilities::factorial(int n)
{
	long long theResult = 1;
	for (int i = 1; i <= n; ++i)
	{
		theResult *= i;
	}

	return theResult;
}

//-----------------------------------------------------------//
long long Utilities::N_Choose_M(int n, int m)
{
	if (n == m) return 1;

	long long nFact = factorial(n);
	long long mFact = factorial(m);
	long long nMinusM = factorial(n - m);

	return  nFact / (mFact * nMinusM);
}

//-----------------------------------------------------------//
int Utilities::GCD(int a, int b)
{
	int theGCD = 1;
	int theNewA = a;
	int theNewB = b;

	for (int p = 0; p < NUM_PRIMES; ++p)
	{
		if (theNewA % Utilities::primes[p] == 0 && theNewB % Utilities::primes[p] == 0)
		{
			while (theNewA % Utilities::primes[p] == 0 && theNewB % Utilities::primes[p] == 0)
			{
				theGCD *= Utilities::primes[p];
				theNewA /= Utilities::primes[p];
				theNewB /= Utilities::primes[p];
			}
		}
	}

	return theGCD;
}

//-----------------------------------------------------------//
vector<int> Utilities::GetDigits(int a)
{
	vector<int> v;

	string theStringRep = to_string(a);

	for (unsigned i = 0; i < theStringRep.length(); ++i)
	{
		v.push_back(theStringRep[i] - 48);
	}

	return v;
}