#include "TransactionNode.h"

TransactionNode::TransactionNode(int newUnits, string newData) : Node(newData)
{
	mUnits = newUnits;
}

TransactionNode::~TransactionNode()
{
}

void TransactionNode::setUnits(const int newUnits)
{
	mUnits = newUnits;
}

int TransactionNode::getUnits() const
{
	return mUnits;
}

void TransactionNode::printData()
{
	cout << "Type: " << mData << endl << "Units: " << mUnits << endl;
}