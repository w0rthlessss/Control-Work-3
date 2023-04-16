#pragma once
#include "GetInfo.h"
#include <vector>
enum ComaprisonOptions{isGreater, isLesser};

class iSort
{
protected:
	int comparisons=0;
	int permutations=0;
public:
	iSort();
	void ShowPermutations();
	int GetPermutations();
	void ShowComparisons();
	int GetComparisons();
	virtual bool Sort(vector<vector<int>>& matrix) = 0;
	virtual void SortSubArray(vector<int> &arr) = 0;
	virtual string GetName() = 0;
	bool Compare(int x, int y, int mode);
	void Permutate(vector <int>& arr, int pos1, int pos2);
	bool IsSorted(vector<int>& arr);
};

