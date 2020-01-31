#include "DataAnalysis.h"

#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{
}

DataAnalysis::~DataAnalysis()
{
}

//opens the .csv file to read from
void DataAnalysis::openFile()
{
	csvStream.open("data.csv", ios::in);
	if (csvStream.is_open())

	{
		readFile();
	}
	else
		cout << "Unable to open your file";
}

//reads the file one line at a time until EOF
void DataAnalysis::readFile()
{
	string header; //read in the header
	std::getline(csvStream, header);
	while (!csvStream.eof())
	{
		string units; 
		std::getline(csvStream, units, ',');
		int numUnits = 0;
		numUnits = atoi(units.c_str()); //convert the string units to an int amount of units
		string type;
		std::getline(csvStream, type, ',');
		string transaction; 
		std::getline(csvStream, transaction, '\n');
		insertDataFromFile(numUnits, type, transaction);
	}
}

//analyzes transaction type and inserts the units and type into the proper tree
void DataAnalysis::insertDataFromFile(int units, string type, string transaction)
{
	if (transaction == "Purchased") 
	{
		mTreePurchased.insert(units, type);
	}
	else if (transaction == "Sold")
	{
		mTreeSold.insert(units, type);
	}
}

//displays the trees, least purchased and sold, most purchased and sold
void DataAnalysis::displayTree()
{
	cout << "Purchased information: " << endl;
	cout << "--------------------" << endl;
	cout << "Largest: " << endl;
	mTreePurchased.findLargest(mTreePurchased.getRoot());
	cout << "Smallest: " << endl;
	mTreePurchased.findSmallest(mTreePurchased.getRoot());
	cout << "All purchased units: " << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl;
	cout << "Sold information: " << endl;
	cout << "--------------------" << endl;
	cout << "Largest: " << endl;
	mTreeSold.findLargest(mTreeSold.getRoot());
	cout << "Smallest: " << endl;
	mTreeSold.findSmallest(mTreeSold.getRoot());
	cout << "All sold units: " << endl;
	mTreeSold.inOrderTraversal();
}

//runs entire program
void DataAnalysis::runAnalysis()
{
	openFile(); //opens the file for reading
	readFile(); //reads from file, inserts into proper tree
	displayTree(); //displays the smallest units/type and largest units/type
	csvStream.close(); //close the file
}










