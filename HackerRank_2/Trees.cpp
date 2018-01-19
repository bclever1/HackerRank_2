#include "stdafx.h"
#include "Trees.h"
#include "TestManager.h"
#include "Utilities.h"

#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;


#if 0
/*==================================================*/
template <class T>
void swapSubTrees(Node<T>* head, int theDepth)
{
	Node<T>* theLeft = 0;
	Node<T>* theRight = 0;

	theLeft = head->GetLeft();
	theRight = head->GetRight();

	if (theLeft && theRight)
	{
		if (theLeft->GetDepth() == theDepth)
		{
			head->SetLeft(theRight);
			head->SetRight(theLeft);
		}
		else
		{
			swapSubTrees(theLeft, theDepth);
			swapSubTrees(theRight, theDepth);
		}
	}
	else if (theLeft != 0)
	{
		if (theLeft->GetDepth() == theDepth)
		{
			head->SetLeft(0);
			head->SetRight(theLeft);
		}
		else
		{
			swapSubTrees(theLeft, theDepth);
		}
	}
	else if (theRight != 0)
	{
		if (theRight->GetDepth() == theDepth)
		{
			head->SetLeft(theRight);
			head->SetRight(0);
		}
		else
		{
			swapSubTrees(theRight, theDepth);
		}
	}
}

class nodePair
{
public:
	int lVal;
	int rVal;
	int line;

	void display()
	{
		cout << "lVal: " << lVal << ", rVal: " << rVal << " ";
	}
};

#endif
