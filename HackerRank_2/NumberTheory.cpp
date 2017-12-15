#include "stdafx.h"
#include "NumberTheory.h"
#include "sTestManager.h"
#include "Utilities.h"
#include <cmath>
#include <sstream>
#include <iostream>
#include <vector>

NumberTheory::NumberTheory()
{
}


NumberTheory::~NumberTheory()
{
}

void NumberTheory::ClosestNumber()
{
	sTestManager* s = new sTestManager();
	s->GetInput();

	int numTests = atoi(s->GetLine().c_str());

	for (int tc = 1; tc <= numTests; ++tc)
	{
		long a, b, x;
		stringstream ss(s->GetLine());
		ss >> a >> b >> x;

		long a_to_the_b = pow(a, b);

		int multiple = 0;

		while (multiple * x <= a_to_the_b)
		{
			++multiple;
		}

		//cout << "Here multiple of x: " << multiple * x << endl;
		long one_less = (multiple - 1) * x;
		long exact    = (multiple) * x;
		long one_more = (multiple + 1) * x;

		if (abs(one_less - a_to_the_b) < abs(exact - a_to_the_b))
		{
			cout << one_less << endl;
		}
		else if (abs(one_more - a_to_the_b) < abs(exact - a_to_the_b))
		{
			cout << one_more << endl;
		}
		else
		{
			cout << exact << endl;
		}

	}
}

void NumberTheory::SherlockAndGCD()
{
	sTestManager* s = new sTestManager();
	s->GetInput();

	int numTests = atoi(s->GetLine().c_str());

	for (int tc = 1; tc <= numTests; ++tc)
	{
		int numElements = atoi(s->GetLine().c_str());

		vector<int>theElements (numElements);
		stringstream ss(s->GetLine());
		for (int i = 0; i < numElements; ++i)
		{
			ss.clear();
			ss >> theElements[i];
		}

		// Pick an element as the starter for the set
		// Then loop through looking for new elements to add
		vector<int> theSubset;
		bool found1 = false;
		for (int j = 0; j < theElements.size() - 1; ++j)
		{
			theSubset.clear();
			theSubset.push_back(theElements[j]);

			for (int k = j + 1; k < theElements.size(); ++k)
			{
				// Can I add this element to the subset?
				// Make sure the element isn't in the set already
				bool found2 = 0;
				for (int z = 0; z < theSubset.size(); ++z)
				{
					if (theElements[k] == theSubset[z])
					{
						// Can't add this guy.
						found2 = true;
						break;
					}
				}

				if (found2 == true)
				{
					continue;
				}

				if (Utilities::GCD(theSubset[0], theElements[k]) == 1)
				{
					theSubset.push_back(theElements[k]);
					found1 = true;
					goto label;
				}
			}

			if (theSubset.size() > 1)
			{
				found1 = true;
				break;
			}
		}

		label:
		if (found1 == true)
		{
			cout << "YES" << endl;
			//Utilities::displayVector(theSubset);
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}