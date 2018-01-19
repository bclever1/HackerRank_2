#pragma once

#include "DataStructures.h"
#include <vector>

using namespace std;

/*==================================================*/
struct Node
{
	int data;
	Node *next;
	Node *prev;
};

/*==================================================*/
struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
};

/*==================================================*/
class nodeWrapper
{
public:
	Node* myNode;
	int myCount;
};

/*==================================================*/
class List : public DataStructures
{
public:
	List();
	~List();

	
	int CompareLists(Node* headA, Node* headB);
	Node* InsertNth(Node *head, int data, int position);
	void displayList(Node* head);
	Node* Delete(Node* head, int position);
	int FindMergeNode(Node *headA, Node *headB);
	bool findVal(TreeNode* n, int val);
	TreeNode* lca(TreeNode* root, int v1, int v2);
	vector<Node*> convertListToVector(Node* head);
	Node* MergeLists(Node* headA, Node* headB);
	int GetNode(Node* head, int positionFromTail);
	bool has_cycle(Node* head);
	bool isSorted(vector<Node*>& v);
	Node* RemoveDuplicates(Node* head);
	void sort(vector<Node*>& v);
	void ReversePrint(Node* head);
	Node* ReverseDL(Node* head);
	Node* Reverse(Node* head);
	Node* SortedInsert(Node *head, int data);

};

