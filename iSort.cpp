#include "iSort.h"

iSort::iSort()
{
	comparisons = 0;
	permutations = 0;
}

int iSort::GetPermutations()
{
	return permutations;
}


int iSort::GetComparisons()
{
	return comparisons;
}

bool iSort::Compare(int x, int y, int mode)
{
	comparisons++;
	if (mode == ComaparisonOptions::strict) return x >= y;
	else return x > y;
}

void iSort::Permutate(vector<int>& a, int pos1, int pos2)
{
	permutations++;
	swap(a[pos1], a[pos2]);
}

bool iSort::IsSorted(vector<int>& arr)
{
	if (arr.size() == 1) return true;
	for (int i = 0; i < arr.size()-1; i++) {
		if (abs(arr[i]) < abs(arr[i + 1])) return false;
	}
	return true;
}

bool iSort::SortMatrix(vector<vector<int>>& matrix)
{
	bool isSorted = true;
	for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
		if (!IsSorted(matrix[i])) {
			Sort(matrix[i]);
			isSorted = false;
		}
	}
	return isSorted;
}


