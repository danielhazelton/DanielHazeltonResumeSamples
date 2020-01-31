#pragma once
#include "Node.h"

class TransactionNode : public Node {

public:
TransactionNode(int newUnits = 0, string newData = "");
~TransactionNode();

void printData();

//setters
void setUnits(const int newUnits);

//getters
int getUnits() const;

private:
int mUnits;

};


