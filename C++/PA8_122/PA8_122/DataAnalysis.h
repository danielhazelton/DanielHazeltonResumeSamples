#pragma once
#include "BST.h"
#include "TransactionNode.h"
#include "Node.h"


class DataAnalysis
{
public:	
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();
	
private:	
	BST mTreeSold;
	BST mTreePurchased;
	ifstream csvStream;
	void openFile();
	void readFile();
	void insertDataFromFile(int units, string type, string transaction);
	void displayTree();
};





