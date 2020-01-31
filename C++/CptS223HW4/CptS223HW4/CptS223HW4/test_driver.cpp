#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <string>
using namespace std;

/**
* Cubic maximum contiguous subsequence sum algorithm.
*/
int maxSubSum1(const vector<int> & a)
{
	int maxSum = 0;

	for (int i = 0; i < a.size(); ++i)
		for (int j = i; j < a.size(); ++j)
		{
			int thisSum = 0;

			for (int k = i; k <= j; ++k)
				thisSum += a[k];

			if (thisSum > maxSum)
				maxSum = thisSum;
		}

	return maxSum;
}


/**
* Quadratic maximum contiguous subsequence sum algorithm.
*/
int maxSubSum2(const vector<int> & a)
{
	int maxSum = 0;

	for (int i = 0; i < a.size(); ++i)
	{
		int thisSum = 0;
		for (int j = i; j < a.size(); ++j)
		{
			thisSum += a[j];

			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}

	return maxSum;
}

/**
* Return maximum of three integers.
*/
int max3(int a, int b, int c)
{
	return a > b ? a > c ? a : c : b > c ? b : c;
}

/**
* Recursive maximum contiguous subsequence sum algorithm.
* Finds maximum sum in subarray spanning a[left..right].
* Does not attempt to maintain actual best sequence.
*/
int maxSumRec(const vector<int> & a, int left, int right)
{
	if (left == right)  // Base case
		if (a[left] > 0)
			return a[left];
		else
			return 0;

	int center = (left + right) / 2;
	int maxLeftSum = maxSumRec(a, left, center);
	int maxRightSum = maxSumRec(a, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = center; i >= left; --i)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (int j = center + 1; j <= right; ++j)
	{
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max3(maxLeftSum, maxRightSum,
		maxLeftBorderSum + maxRightBorderSum);
}

/**
* Driver for divide-and-conquer maximum contiguous
* subsequence sum algorithm.
*/
int maxSubSum3(const vector<int> & a)
{
	return maxSumRec(a, 0, a.size() - 1);
}

/**
* Linear-time maximum contiguous subsequence sum algorithm.
*/
int maxSubSum4(const vector<int> & a)
{
	int maxSum = 0, thisSum = 0;

	for (int j = 0; j < a.size(); ++j)
	{
		thisSum += a[j];

		if (thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}

	return maxSum;
}


int main()
{
	//Create an input file stream
	ifstream in("arrayfile.txt",ios::in);
	//Create a dynamic array to hold the values
	vector<int> a;
	
	int number;  //Variable to hold each number as it is read
	
	//Read number using the extraction (>>) operator
	while (in >> number) {
		//Add the number to the end of the array
		a.push_back(number);
	}

	//Close the file stream
	in.close();
	int size = a.size();
	int maxSum;
	cout << "input size is: " << size << endl;
	clock_t t1, t2;
	t1 = clock();
	maxSum = maxSubSum1(a);
	t2 = clock();
	cout << "Max sum is " << maxSum << endl;
	float diff((float)t2 - (float)t1);
	cout << "Time taken (milliseconds):" << diff << endl;
	system("pause");
	t1 = clock();
	maxSum = maxSubSum2(a);
	t2 = clock();
	cout << "Max sum is " << maxSum << endl;
	diff = t2 - t1;
	cout << "Time taken (milliseconds):" << diff << endl;
	system("pause");
	t1 = clock();
	maxSum = maxSubSum3(a);
	t2 = clock();
	cout << "Max sum is " << maxSum << endl;
	diff = t2 - t1;
	cout << "Time taken (milliseconds):" << diff << endl;
	system("pause");
	t1 = clock();
	maxSum = maxSubSum4(a);
	t2 = clock();
	cout << "Max sum is " << maxSum << endl;
	diff = t2 - t1;
	cout << "Time taken (milliseconds):" << diff << endl;

	
	return 0;
}