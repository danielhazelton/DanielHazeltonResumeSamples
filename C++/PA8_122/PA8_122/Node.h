#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

class Node {
public:
	Node(string str);
	~Node();
	void setmData(const string str);
	void setmpLeft(Node *&newMpLeft);
	void setmpRight(Node *&newMpRight);
	string getmData();
	Node*& getmpRight();
	Node*& getmpLeft();
	virtual void printData();


protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;

};

