#include "stdafx.h"
#include "Algebra.h"

#include <cmath>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define DEBUG 0
Algebra::Algebra()
{
}


Algebra::~Algebra()
{
}

int Algebra::LittleGauravAndSequence()
{
	int numTests;
	cin >> numTests;

	int tc = 1;
	while (tc <= numTests)
	{
		vector<long long> v;
		int i = 0;
		long long n;

		cin >> n;

		int theSum = 0;

		while (pow(2, i) <= n)
		{
			int theTermSum = 0;
			int theTerm = 0;
			
			for (int j = 0; j <= n; ++j)
			{
#if DEBUG
				cout << "i,j: " << i << ", " << j << endl;
#endif

				int theExp = pow(2, i) + 2 * j;
				theTerm = pow(2, theExp);

				theTermSum += theTerm;
				theTermSum = theTermSum % 10;

#if DEBUG
				cout << "    theTermSum: " << theTermSum << endl;
#endif

			}

			theSum += theTermSum;
			theSum = theSum % 10;

			++i;
		}

#if DEBUG
		cout << "The total summation: "  << theSum << endl;
#endif

		string theSumString = to_string(theSum);
		cout << theSumString[theSumString.length()-1] << endl;
		
		++tc;
	}

	return 0;
}
