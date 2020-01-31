#pragma once
#include "Node.h"
#include "TransactionNode.h"

class BST
{

public:
	BST();
	~BST();

	//setters
	void setMpRoot(Node *newRoot);

	//getters
	Node *& getRoot();

	void inOrderTraversal();
	TransactionNode & findSmallest(Node *root);
	TransactionNode & findLargest(Node *root);
	void insert(int mUnits, string mData);
private:	
	Node *mpRoot;
	void destroyTree(Node *root);
	void insert(Node *& root, int mUnits, string mData);
	void inOrderTraversal(Node *root);
};

ostream & operator<<(ostream &lhs, TransactionNode & rhs);







