#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{

	destroyTree(mpRoot);
}

void BST::setMpRoot(Node *newRoot)
{
	mpRoot = newRoot;
}

Node *& BST::getRoot()
{
	return mpRoot;
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

void BST::insert(int mUnits, string mData)
{
	insert(mpRoot, mUnits, mData);
}

TransactionNode & BST::findSmallest(Node *root)
{
	TransactionNode *pMem = dynamic_cast<TransactionNode *>(root);

	//traverse tree to as far left as possible
	if (pMem->getmpLeft() != nullptr)
	{
		return findSmallest(pMem->getmpLeft());
	}
	cout << *(pMem);
	return *(pMem);
}

TransactionNode & BST::findLargest(Node *root)
{
	TransactionNode *pMem = dynamic_cast<TransactionNode *>(root);

	//traverse tree to as far right as possible
	if (pMem->getmpRight() != nullptr)
	{
		return findLargest(pMem->getmpRight());
	}
	cout << *(pMem);
	return *(pMem);
}

//PRIVATE FUNCTIONS
void BST::destroyTree(Node *root)
{
	if (root != nullptr)
	{
		destroyTree(root->getmpLeft()); //go as far left as possible
		destroyTree(root->getmpRight()); //go as far right as possible
		delete root; //delete
	}
}

void BST::insert(Node *& root, int mUnits, string mData)
{
	TransactionNode *pMem = dynamic_cast<TransactionNode *>(root); //cast Node *root to TransactionNode which is now pMem

																   //check for empty list
	if (root == nullptr)
	{
		//set root to first insert
		pMem = new TransactionNode(mUnits, mData);
		root = pMem;
	}
	else //tree is not empty
	{
		if (mUnits < pMem->getUnits())
		{
			//go left
			insert(pMem->getmpLeft(), mUnits, mData);
		}
		else if (mUnits > pMem->getUnits())
		{
			//go right
			insert(pMem->getmpRight(), mUnits, mData);
		}
	}
}

void BST::inOrderTraversal(Node *root)
{
	TransactionNode *pMem = dynamic_cast<TransactionNode *>(root);

	if (pMem != nullptr)
	{
		inOrderTraversal(pMem->getmpLeft());
		cout << "Item: " << pMem->getmData() << endl;
		cout << "Units: " << pMem->getUnits() << endl;
		inOrderTraversal(pMem->getmpRight());
	}
}

ostream & operator<<(ostream &lhs, TransactionNode & rhs)
{
	lhs << rhs.getmData() << endl << rhs.getUnits() << endl;
	return lhs;
}



