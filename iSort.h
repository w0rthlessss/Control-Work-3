#pragma once
#include "GetInfo.h"
#include <vector>

enum ComaparisonOptions{strict, nonStrict};

class iSort
{
protected:
	int comparisons=0;
	int permutations=0;
public:
	virtual ~iSort() = default;
	iSort();
	int GetPermutations();
	int GetComparisons();
	virtual void Sort(vector<int> &arr) = 0;
	virtual string GetName() = 0;
	bool Compare(int x, int y, int mode);
	void Permutate(vector <int>& arr, int pos1, int pos2);
	//bool IsSorted(vector<int>& arr);
	void SortMatrix(vector<vector<int>>& matrix);
};

