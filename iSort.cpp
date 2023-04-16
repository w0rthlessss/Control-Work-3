#include "iSort.h"

iSort::iSort()
{
	comparisons = 0;
	permutations = 0;
}


void iSort::ShowPermutations()
{
	cout << "Permutations: " << permutations << endl;
}

int iSort::GetPermutations()
{
	return permutations;
}

void iSort::ShowComparisons()
{
	cout << "Comparisons: " << comparisons << endl;
}

int iSort::GetComparisons()
{
	return comparisons;
}

bool iSort::Compare(int x, int y, int mode)
{
	comparisons++;
	switch (mode)
	{
	case ComaprisonOptions::isBigger:
		return x > y;
	case ComaprisonOptions::isSmaller:
		return x<y;
	default:
		break;
	}
}

void iSort::Permutate(vector<int>& a, int pos1, int pos2)
{
	permutations++;
	swap(a[pos1], a[pos2]);
}

bool iSort::IsSorted(vector<int>& arr)
{
	for (int i = 0; i < arr.size()-1; i++) {
		if(abs(arr[i])<abs(arr[i+1])) return true;
	}
	return false;
}


