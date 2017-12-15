#include "stdafx.h"
#include "List.h"


List::List()
{
}


List::~List()
{
}


#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

/*==================================================*/
Node* List::InsertNth(Node *head, int data, int position)
{
	Node* pos = head;
	int counter = 0;

	if (position == 0)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = head;
		return newNode;
	}
	else
	{
		while (counter < position - 1)
		{
			pos = pos->next;
			++counter;
		}

		// pos should point the guy we want to split
		Node* newNode = new Node();
		newNode->data = data;

		if (pos->next == 0)
		{
			pos->next = newNode;
		}
		else
		{
			newNode->next = pos->next;
			pos->next = newNode;
		}
	}

	return head;
}

/*==================================================*/
void List::displayList(Node* head)
{
	Node* node = head;
	while (node != 0)
	{
		cout << node->data << " ";
		node = node->next;
	}

	cout << endl;
}

/*==================================================*/
Node* List::Delete(Node* head, int position)
{
	Node* pos = head;


	if (position == 0)
	{
		// Deleting the head;
		Node* nextGuy = head->next;
		Node* deadGuy = head;
		head->next = 0;
		delete deadGuy;
		return nextGuy;
	}
	else
	{
		int counter = 0;
		while (counter < position - 1)
		{
			pos = pos->next;
			++counter;
		}

		// pos should point the guy right whose next is the one we want to delete

		if (pos->next == 0)
		{
			return head;
		}
		else
		{
			Node* deadGuy = pos->next;

			if (deadGuy->next == 0)
			{
				pos->next = 0;
				delete deadGuy;
			}
			else
			{
				pos->next = deadGuy->next;
				delete deadGuy;
			}
		}
	}

	return head;
}

/*==================================================*/
void List::ReversePrint(Node* head)
{
	Node* node = head;
	vector<int> theResult;
	while (node != 0)
	{
		theResult.push_back(node->data);
		node = node->next;
	}

	for (int i = theResult.size() - 1; i >= 0; --i)
	{
		cout << theResult[i] << endl;
	}
}

/*==================================================*/
Node* List::Reverse(Node* head)
{
	vector<Node*>v;

	Node* node = head;
	while (node != 0)
	{
		v.push_back(node);
		node = node->next;
	}

	for (int i = v.size() - 1; i >= 0; --i)
	{
		node = v[i];
		node->next = v[i - 1];
	}

	v[0]->next = 0;

	return v[v.size() - 1];
}

/*==================================================*/
vector<Node*> List::convertListToVector(Node* head)
{
	vector<Node*> v;

	Node* node = head;
	while (node != 0)
	{
		v.push_back(node);
		node = node->next;
	}

	return v;
}

/*==================================================*/
int List::CompareLists(Node* headA, Node* headB)
{
	int result = 1;

	vector<Node*>a = convertListToVector(headA);
	vector<Node*>b = convertListToVector(headB);

	if (a.size() != b.size())
	{
		return 0;
	}

	for (unsigned int i = 0; i < a.size(); ++i)
	{
		if (a[i]->data != b[i]->data)
		{
			return 0;
		}
	}

	return 1;
}

/*==================================================*/
bool List::isSorted(vector<Node*>& v)
{
	for (unsigned int i = 0; i < v.size() - 1; ++i)
	{
		if (v[i]->data > v[i + 1]->data)
		{
			return false;
		}
	}

	return true;
}

/*==================================================*/
void List::sort(vector<Node*>& v)
{
	while (isSorted(v) == false)
	{
		for (unsigned int i = 0; i < v.size() - 1; ++i)
		{
			if (v[i]->data > v[i + 1]->data)
			{
				int temp = v[i]->data;
				v[i]->data = v[i + 1]->data;
				v[i + 1]->data = temp;
			}
		}
	}
}

/*==================================================*/
Node* List::MergeLists(Node* headA, Node* headB)
{
	vector<Node*>v;

	if (headA != 0)
	{
		v = convertListToVector(headA);
		if (headB != 0)
		{
			Node* node = headB;
			v[v.size() - 1]->next = node;

			while (node != 0)
			{
				v.push_back(node);
				node = node->next;
			}
		}
	}

	else if (headB != 0)
	{
		v = convertListToVector(headB);
		Node* node = headB;
	}

	sort(v);

	return v[0];
}

/*==================================================*/
int List::GetNode(Node* head, int positionFromTail)
{
	vector<Node*> v;
	v = convertListToVector(head);

	int pos = v.size() - positionFromTail - 1;

	return v[pos]->data;
}

/*==================================================*/
Node* List::RemoveDuplicates(Node* head)
{
	Node* node = head;
	Node* temp = 0;
	while (node != 0)
	{
		if (node->next != 0)
		{
			if (node->data == node->next->data)
			{
				if (node->next->next != 0)
				{
					temp = node->next;
					node->next = temp->next;
					delete temp;
				}
				else
				{
					temp = node->next;
					node->next = 0;
					delete temp;
				}
			}
			else
			{
				node = node->next;
			}
		}
		else
		{
			break;
		}

	}
	return head;
}


bool List::has_cycle(Node* head) 
{
	// Complete this function
	// Do not write the main method

	vector<Node*> v;

	Node* node = head;

	try {
		while (node != 0)
		{
			v.push_back(node);
			node = node->next;

			for (int i = v.size() - 2; i >= 0; --i)
			{
				if (v[i] == node)
				{
					return true;
				}
			}
		}

		return false;
	}
	catch (overflow_error e)
	{
		return true;
	}

	return false;
}

/*==================================================*/
int List::FindMergeNode(Node *headA, Node *headB)
{
	Node* na = headA;
	Node* nb = headB;

	while (na != 0)
	{
		nb = headB;

		while (nb != 0)
		{
			if (na == nb)
			{
				return na->data;
			}
			nb = nb->next;
		}

		na = na->next;

	}
}

/*==================================================*/

Node* List::ReverseDL(Node* head)
{
	// Complete this function
	// Do not write the main method. 
	// This one is for a doubly->linked list

	Node* n = head;
	Node* tempPrev;
	Node* tempNext;

	while (n != 0)
	{
		tempPrev = n->prev;
		tempNext = n->next;
		n->next = tempPrev;
		n->prev = tempNext;

		if (n->prev == 0)
		{
			return n;
		}

		n = n->prev;
	}
}

/*==================================================*/

Node* List::SortedInsert(Node *head, int data)
{
	// Complete this function
	// Do not write the main method. 

	if (head == 0)
	{
		Node* n1 = new Node();
		n1->data = data;
		n1->next = 0;
		n1->prev = 0;
		return n1;
	}

	Node* n = head;

	if (data <= head->data)
	{
		Node* n1 = new Node();
		n1->data = data;
		n1->prev = 0;
		head->prev = n1;
		n1->next = head;
		return n1;
	}

	while (n != 0)
	{
		if (n->next != 0)
		{
			if (n->data <= data && data <= n->next->data)
			{
				Node* n1 = new Node();
				n1->data = data;

				Node* temp = n->next;
				n->next = n1;

				n->next->prev = n1;
				n1->next = temp;
				n1->prev = n;

				return head;
			}
		}
		else
		{
			// n is the last guy in the list.
			Node* n1 = new Node();
			n1->next = 0;
			n1->data = data;
			n->next = n1;
			n1->prev = n;
			return head;

		}
		n = n->next;
	}
}

/*==================================================*/

bool List::findVal(TreeNode* n, int val)
{
	if (n == 0) return false;

	if (n->data == val) return true;

	bool theResult = false;
	if (n->left)
	{
		theResult = findVal(n->left, val);

		if (theResult == true) return theResult;
		else
		{
			theResult = findVal(n->right, val);
			return theResult;
		}
	}
	else if (n->right)
	{
		return findVal(n->right, val);
	}

	return false;
}

TreeNode* List::lca(TreeNode* root, int v1, int v2)
{
	if (root->data == v1 || root->data == v2) return root;

	if (root->left != 0 && root->right != 0 &&
		(findVal(root->left, v1) && findVal(root->right, v2) || findVal(root->left, v2) && findVal(root->right, v1)))
	{
		return root;
	}
	else
	{
		if (root->left)
		{
			if (findVal(root->left, v1) && findVal(root->left, v2))
			{
				return lca(root->left, v1, v2);
			}
		}

		if (root->right)
		{
			if (findVal(root->right, v1) && findVal(root->right, v2))
			{
				return lca(root->right, v1, v2);
			}
		}
	}

	return 0;
}


