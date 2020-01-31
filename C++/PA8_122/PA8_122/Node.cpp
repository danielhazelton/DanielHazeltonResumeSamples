#include "Node.h"

Node::Node(string str)
{
	mData = str;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{
}

void Node::printData()
{
	cout << mData << endl;
}

//setters
void Node::setmpLeft(Node *&newmpLeft)
{
	mpLeft = newmpLeft;
}

void Node::setmpRight(Node *&newmpRight)
{
	mpRight = newmpRight;
}

void Node::setmData(const string str)
{
	mData = str;
}

// getters
Node *& Node::getmpLeft()
{
	return mpLeft;
}

Node *& Node::getmpRight()
{
	return mpRight;
}

string Node::getmData()
{
	return mData;
}

