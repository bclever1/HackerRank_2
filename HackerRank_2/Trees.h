#pragma once

#include "DataStructures.h"
#include "TestManager.h"

#include <vector>

using namespace std;

template<class T>
class Node
{

public:

	Node(T data, int index, int depth) { myData = data; right = 0; left = 0; myIndex = index; myDepth = depth; }
	void SetRight(Node<T>* theRight) { right = theRight; }
	Node<T>* GetRight() { return right; }
	void SetLeft(Node<T>* theLeft) { left = theLeft; }
	Node<T>* GetLeft() { return left; }
	T GetData() { return myData; }
	int GetIndex() { return myIndex; }
	int GetDepth() { return myDepth; }
	void SetDepth(int theDepth) { myDepth = theDepth; }

private:

	Node<T>* left;
	Node<T>* right;
	T myData;
	int myIndex;
	int myDepth;
};

/*==================================================*/
template <class T>
class Trees : public DataStructures
{

public:
	Trees() {};
	~Trees() {};
	void ArrayPairs() {}
	Node<T>* GetNode(vector<Node<T>*>& theNodes, T theData);
	void SwapNodes(string);
	static void displayTree(Node<T>* head, string& theResult);
	void swapSubTrees(Node<T>* head, int theDepth);

};

/*==================================================*/
template <class T>
Node<T>* Trees<T>::GetNode(vector<Node<T>*>& theNodes, T theData)
{
	if (theData == 0)
	{
		return theNodes[0];
	}

	for (unsigned int i = 0; i < theNodes.size(); ++i)
	{
		if (theNodes[i]->GetData() == theData)
		{
			return theNodes[i];
		}
	}

	return 0;
}

/*==================================================*/
template <class T>
void Trees<T>::SwapNodes(string theTestCaseFile)
{
	TestManager* tm = 0;
	if (theTestCaseFile == "STDIN")
	{
		tm = new TestManager();
	}
	else
	{
		tm = new TestManager("d:\\TestCases\\hackerrank_1.txt");
		tm->populateResults("d:\\TestCases\\hackerrank_1_results.txt");
	}

	string inputLine = "";
	int nodeIndex = 1;
	int numNodes;
	inputLine = tm->GetLine();
	numNodes = atoi(inputLine.c_str());


	vector<nodePair*> theNodeInputs;
	nodePair* blank = new nodePair();
	theNodeInputs.push_back(blank);

	int lineNum = 1;
	while (nodeIndex < numNodes)
	{
		inputLine = tm->GetLine();
		stringstream ss(inputLine);

		nodePair* ni = new nodePair();
		ss >> ni->lVal >> ni->rVal;
		ni->line = lineNum;

		if (ni->lVal != -1)
		{
			++nodeIndex;
		}
		if (ni->rVal != -1)
		{
			++nodeIndex;
		}

		theNodeInputs.push_back(ni);

		++lineNum;
	}

	vector<Node<int>*> theNodes;
	Node<int>* _1 = new Node<int>(1, 1, 0);
	theNodes.push_back(_1);

	// Make all the nodes
	for (unsigned int i = 1; i < theNodeInputs.size(); ++i)
	{
		if (theNodeInputs[i]->lVal != -1)
		{
			Node<int>* x = new Node<int>(theNodeInputs[i]->lVal, 0, 0);
			theNodes.push_back(x);

		}
		if (theNodeInputs[i]->rVal != -1)
		{
			Node<int>* x = new Node<int>(theNodeInputs[i]->rVal, 0, 0);
			theNodes.push_back(x);
		}
	}

	// Relate to the parent
	int maxDepth = 0;
	for (unsigned int i = 0; i < theNodes.size(); ++i)
	{
		if (i + 1 == theNodeInputs.size()) break;

		Node<int>* newLeft = GetNode(theNodes, theNodeInputs[i + 1]->lVal);
		if (newLeft)
		{
			theNodes[i]->SetLeft(newLeft);
			newLeft->SetDepth(theNodes[i]->GetDepth() + 1);
			if (newLeft->GetDepth() > maxDepth) maxDepth = newLeft->GetDepth();
		}
		Node<int>* newRight = GetNode(theNodes, theNodeInputs[i + 1]->rVal);
		if (newRight)
		{
			theNodes[i]->SetRight(newRight);
			newRight->SetDepth(theNodes[i]->GetDepth() + 1);
			if (newRight->GetDepth() > maxDepth) maxDepth = newRight->GetDepth();
		}
	}

	// Finished getting the nodes from input
	// Now suck up the rest of the tree data
	inputLine = tm->GetLine();

	while (inputLine == "-1 -1")
	{
		inputLine = tm->GetLine();
	}

	// Here inputLine will contain the number of test cases

	int numTestCases = atoi(inputLine.c_str());

	string theResult = "";
	int testCase = 0;
	int theOriginalSwap;
	int theCurrentSwap;
	int theSwapCounter;

	while (testCase < numTestCases)
	{
		// Get the swap number
		inputLine = tm->GetLine();
		theOriginalSwap = atoi(inputLine.c_str());

		theSwapCounter = 1;
		theCurrentSwap = theOriginalSwap;
		while (theCurrentSwap <= maxDepth)
		{
			swapSubTrees(_1, theCurrentSwap);
			++theSwapCounter;
			theCurrentSwap = theOriginalSwap * theSwapCounter;
		}

		theResult = "";
		displayTree(_1, theResult);
		int resultLength = theResult.length();
		if (theResult[resultLength - 1] == ' ')
		{
			theResult.pop_back();
		}

		if (tm->compareResult(testCase, theResult))
		{
			cout << "PASSED!" << endl;
		}
		else
		{
			cout << "FAILED!!" << endl;
		}
		//cout << endl;

		++testCase;
	}
}

/*==================================================*/
template <class T>
void Trees<T>::displayTree(Node<T>* head, string& theResult)
{
	Node<T>* theLeft = 0;
	Node<T>* theRight = 0;

	theLeft = head->GetLeft();
	if (theLeft != 0)
		displayTree(theLeft, theResult);

	stringstream ss;
	ss << head->GetData();
	string str = ss.str();
	theResult += str;
	theResult += " ";

	theRight = head->GetRight();
	if (theRight != 0)
		displayTree(theRight, theResult);

}


/*==================================================*/
template <class T>
void Trees<T>::swapSubTrees(Node<T>* head, int theDepth)
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