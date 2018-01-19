#pragma once

#include "DataStructures.h"

template
<class T>
class Stacks : public DataStructures
{
	virtual void GameOfTwoStacks();
	virtual void MaximumElement();
	virtual void BalancedBrackets();
	virtual void EqualStacks();
};

template
<class T>
void Stacks<T>::BalancedBrackets()
{
	deque<char> myStack;

	TestManager* tm = new TestManager("d:\\TestCases\\stacks_balanced_brackets_input_test_case_1.txt");
	tm->populateResults("d:\\TestCases\\stacks_balanced_brackets_input_test_case_1_results.txt");

	int numQueries = atoi(tm->GetLine().c_str());

	for (int g = 0; g < numQueries; ++g)
	{
		myStack.clear();

		string theLine = tm->GetLine();

		for (int ch = theLine.length() - 1; ch >= 0; --ch)
		{
			if (myStack.size() == 0)
			{
				myStack.push_front(theLine[ch]);
			}

			else
			{
				if (myUtilities::isPairedChar(theLine[ch], myStack[0]))
				{
					myStack.pop_front();
				}
				else
				{
					myStack.push_front(theLine[ch]);
				}
			}
		}

		if (myStack.size() != 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}


template
<class T>
void Stacks<T>::EqualStacks()
{
	TestManager* tm = new TestManager("d:\\TestCases\\stacks_equal_stacks_test_case_6.txt");
	tm->populateResults("d:\\TestCases\\stacks_equal_stacks_test_case_6_results.txt");

	stringstream ss(tm->GetLine());
	int sizeA, sizeB, sizeC;

	ss >> sizeA >> sizeB >> sizeC;

	vector<int> myStackA(sizeA);
	vector<int> myRunningA(sizeA + 1);
	vector<int> myStackB(sizeB);
	vector<int> myRunningB(sizeB + 1);
	vector<int> myStackC(sizeC);
	vector<int> myRunningC(sizeC + 1);

	int theMaxHeight = 0;

	stringstream ssA(tm->GetLine());

	for (int i = sizeA - 1; i >= 0; --i)
	{
		ssA.clear();
		ssA >> myStackA[i];
	}

	myRunningA[0] = myStackA[0];
	for (int i = 1; i < sizeA; ++i)
	{
		myRunningA[i] = myRunningA[i - 1] + myStackA[i];
	}

	stringstream ssB(tm->GetLine());

	for (int i = sizeB - 1; i >= 0; --i)
	{
		ssB.clear();
		ssB >> myStackB[i];
	}

	myRunningB[0] = myStackB[0];
	for (int i = 1; i < sizeB; ++i)
	{
		myRunningB[i] = myRunningB[i - 1] + myStackB[i];
	}

	stringstream ssC(tm->GetLine());

	for (int i = sizeC - 1; i >= 0; --i)
	{
		ssC.clear();
		ssC >> myStackC[i];
	}

	myRunningC[0] = myStackC[0];
	for (int i = 1; i < sizeC; ++i)
	{
		myRunningC[i] = myRunningC[i - 1] + myStackC[i];
	}

	for (int A = 0; A < sizeA; ++A)
	{
		if (myRunningA[A] > myRunningB[sizeB - 1] ||
			myRunningA[A] > myRunningC[sizeC - 1])
		{
			break;
		}

		// Find the range for B
		int bCount = 0;
		while (myRunningB[bCount] < myRunningA[A])
		{
			++bCount;
		}

		for (int B = bCount - 1; B < sizeB; ++B)
		{
			if (myRunningB[B] > myRunningA[A]) break;

			if (myRunningB[B] > myRunningA[sizeA - 1] ||
				myRunningB[B] > myRunningC[sizeC - 1])
			{
				break;
			}

			if (myRunningA[A] == myRunningB[B])
			{
				int cCount = 0;
				while (myRunningC[cCount] < myRunningB[B])
				{
					++cCount;
				}

				for (int C = cCount - 1; C < sizeC; ++C)
				{
					if (myRunningC[C] > myRunningB[B]) break;

					if (myRunningC[C] > myRunningA[sizeA - 1] ||
						myRunningC[C] > myRunningB[sizeB - 1])
					{
						break;
					}

					if ((myRunningB[B] == myRunningC[C]))
					{
						if (myRunningA[A] > theMaxHeight)
						{
							theMaxHeight = myRunningA[A];
						}
					}
				}
			}
		}
	}

	cout << theMaxHeight << endl;
}


template <class T>
void Stacks<T>::GameOfTwoStacks()
{
	//TestManager* tm = new TestManager();
	TestManager* tm = new TestManager("d:\\TestCases\\game_of_two_stacks_input_test_case_2.txt");
	tm->populateResults("d:\\TestCases\\game_of_two_stacks_input_test_case_2_results.txt");

	int numGames;
	numGames = atoi(tm->GetLine().c_str());

	for (int g = 0; g < numGames; ++g)
	{
		int sizeStack1;
		int sizeStack2;
		int maxVal = 0;

		stringstream ss_params(tm->GetLine());
		ss_params >> sizeStack1 >> sizeStack2 >> maxVal;

		stringstream ss1(tm->GetLine());
		vector<int> stack_1(sizeStack1);

		vector<int> runningSum1(sizeStack1 + 1);
		runningSum1[0] = 0;

		int sum1 = 0;
		for (int v1 = 0; v1 < sizeStack1; ++v1)
		{
			ss1.clear();
			ss1 >> stack_1[v1];
			sum1 += stack_1[v1];
			runningSum1[v1 + 1] = sum1;
			if (sum1 > maxVal)
			{
				sizeStack1 = v1 + 1;
				break;
			}
		}

		stringstream ss2(tm->GetLine());
		vector<int> stack_2(sizeStack2);
		vector<int> runningSum2(sizeStack2 + 1);
		runningSum2[0] = 0;
		int sum2 = 0;

		for (int v2 = 0; v2 < sizeStack2; ++v2)
		{
			ss2.clear();
			ss2 >> stack_2[v2];
			sum2 += stack_2[v2];
			runningSum2[v2 + 1] = sum2;

			if (sum2 > maxVal)
			{
				sizeStack2 = v2 + 1;
				break;
			}
		}

		int maxPicks = 0;

		int stack1Picks = sizeStack1;
		int stack2Picks = 0;

		int totalSum = 0;

		while (stack1Picks >= 0)
		{
			stack2Picks = 0;

			while (stack2Picks <= sizeStack2)
			{
				totalSum = runningSum1[stack1Picks] + runningSum2[stack2Picks];

				if (totalSum <= maxVal)
				{
					if ((stack1Picks + stack2Picks > maxPicks))
					{
						maxPicks = stack1Picks + stack2Picks;
					}
				}

				++stack2Picks;
			}

			--stack1Picks;
		}

		cout << maxPicks << endl;

		stringstream theResult;
		theResult << maxPicks;

		cout << "Max score: " << maxVal << endl;

		if (tm->compareResult(g, theResult.str()))
		{
			cout << "PASSED!" << endl;
		}
		else
		{
			cout << "FAILED!! Test case: " << g << endl;

			cout << "Max score: " << maxVal << endl;

			u.displayVector(stack_1);
			u.displayVector(stack_2);
		}
	}
}



template
<class T>
void Stacks<T>::MaximumElement()
{
	deque<int> myStack;
	int myMax = 0;

	TestManager* tm = new TestManager("d:\\TestCases\\stacks_max_element_input_test_case_1.txt");
	tm->populateResults("d:\\TestCases\\stacks_max_element_input_test_case_1_results.txt");

	int numQueries;
	numQueries = atoi(tm->GetLine().c_str());

	int theCmd;
	int theVal;

	for (int g = 0; g < numQueries; ++g)
	{
		stringstream ss_params(tm->GetLine());
		if (ss_params.str()[0] == '1')
		{
			ss_params >> theCmd >> theVal;
			myStack.push_front(theVal);
			if (theVal > myMax) myMax = theVal;

			//myUtilities::displayStack(myStack);

		}
		else if (ss_params.str()[0] == '2')
		{
			if (myStack[0] == myMax)
			{
				myMax = 0;
				for (int i = 1; i < myStack.size(); ++i)
				{
					if (myStack[i] > myMax) myMax = myStack[i];
				}
			}

			myStack.pop_front();
			//myUtilities::displayStack(myStack);
		}
		else if (ss_params.str()[0] == '3')
		{
			cout << myMax << endl;
		}
	}
}