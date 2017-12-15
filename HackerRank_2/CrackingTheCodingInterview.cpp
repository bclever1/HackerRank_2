#include "stdafx.h"
#include "CrackingTheCodingInterview.h"
#include <sstream>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include "sTestManager.h"
#include "Utilities.h"

CrackingTheCodingInterview::CrackingTheCodingInterview()
{
}


CrackingTheCodingInterview::~CrackingTheCodingInterview()
{
}

bool done(vector<int>maxCoins, vector<int>theCounters)
{
	for (int i = 0; i < maxCoins.size(); ++i)
	{
		if (theCounters[i] >= maxCoins[i] + 1) return true;
	}

	return false;
}

int getComboValue(map<vector<int>,int>& theCache, vector<int>& combo, int subset, vector<int>& denoms, int dollarAmount)
{
	if (subset == 0)
	{
		return combo[0] * denoms[0];
	}
	else
	{
		map<vector<int>, int>::iterator it = theCache.find(combo);

		if (it != theCache.end())
		{
			cout << "cache hit!!!" << endl;
			return it->second;
		}

		int comboValue = 0;

		comboValue = getComboValue(theCache, combo, subset - 1, denoms, dollarAmount) + combo[subset] * denoms[subset];

		if (comboValue <= dollarAmount)
		{
			theCache[combo] = comboValue;
		}

		return comboValue;
	}
}



long long make_change(vector<int>&theDenoms, int totalDollars)
{
	map<vector<int>, int> theCache;

	Utilities::sort(theDenoms);

	int theResult = 0;
	int theValue = 0;
	int numDenoms = theDenoms.size();
	int maxPos = 0;

	vector<int>maxCoins(numDenoms);

	for (int i = 0; i < numDenoms; ++i)
	{
		maxCoins[i] = totalDollars / theDenoms[i];
	}

	vector<int>theCounters(numDenoms);

	while (!done(maxCoins, theCounters))
	{
		//Utilities::displayVector(theCounters);

		theValue = getComboValue(theCache, theCounters, theCounters.size() - 1, theDenoms, totalDollars);

		if (theValue == totalDollars)
		{
			++theResult;
		}

		++theCounters[0];

		for (int i = 0; i < numDenoms - 1; ++i)
		{
			if (theCounters[i] >= maxCoins[i] + 1)
			{
				if (i + 1 < numDenoms)
				{
					theCounters[i] = 0;
					++theCounters[i + 1];
				}
			}
		}
	}

	return theResult;
}

void CrackingTheCodingInterview::CoinChange()
{
	sTestManager* tm = new sTestManager();
	tm->GetInput();
	int numTests = 1;

	for (int tc = 1; tc <= numTests; ++tc)
	{
		long long theResults;
		stringstream ss[2];
		ss[0].str(tm->GetLine());
		int numDollars;
		int numCoins;
		ss[0] >> numDollars >> numCoins;
		ss[1].str(tm->GetLine());

		vector<int>values(numCoins);

		for (int i = 0; i < numCoins; ++i)
		{
			ss[1].clear();
			ss[1] >> values[i];
		}

		theResults = make_change(values, numDollars);
		cout << theResults << endl;
	}
}

int lonely_integer(vector < int > a) {

	int theResult = 0;
	long int theMaxElement;

	vector<int>::iterator max = max_element(a.begin(), a.end());
	vector<int> theCounts(*max + 1);

	for (int i = 0; i < a.size(); ++i)
	{
		++theCounts[a[i]];
	}

	for (int i = 0; i < theCounts.size(); ++i)
	{
		if (theCounts[i] == 1)
		{
			theResult = i; 
			break;
		}
	}

	return theResult;
}

void CrackingTheCodingInterview::LonelyInteger()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int a_i = 0; a_i < n; a_i++) {
		cin >> a[a_i];
	}
	cout << lonely_integer(a) << endl;
}

void CrackingTheCodingInterview::IceCreamParlor()
{
	sTestManager* s = new sTestManager();
	s->GetInput();

	int numTests = atoi(s->GetLine().c_str());

	for (int tc = 1; tc <= numTests; ++tc)
	{
		stringstream ss[3];
		ss[0].str(s->GetLine());
		ss[1].str(s->GetLine());
		ss[2].str(s->GetLine());

		int dollars;
		ss[0] >> dollars;

		int flavors;
		ss[1] >> flavors;

		vector<int>ic1(flavors);
		vector<int>ic2(flavors);

		for (int i = 0; i < flavors; ++i)
		{
			ss[2].clear();
			ss[2] >> ic1[i];
			ic2[i] = ic1[i];
		}

		bool found = false;
		for (int i = 0; i < flavors; ++i)
		{
			for (int j = 0; j < flavors; ++j)
			{
				if (ic1[i] + ic2[j] == dollars)
				{
					cout << i + 1 << " " << j + 1 << endl;
					found = true;
					break;
				}
			}

			if (found == true)
			{
				break;
			}
		}
	}
}