#pragma once
#include "iSort.h"

class BubbleSort : iSort
{
	virtual string GetName() override {
		return "Bubble Sort:";
	}

	virtual bool Sort(vector<vector<int>>& matrix) override {
		bool isSorted = true;
		for (int i = 0; i < matrix.size(); i++) {
			if (!IsSorted(matrix[i])) {
				SortSubArray(matrix[i]);
				isSorted = false;
			}
		}
		return isSorted;
	}

	virtual void SortSubArray(vector<int>& arr) override {
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr.size() - 1; j++) {
				if (!Compare(abs(arr[j]), abs(arr[j + 1]), isGreater)) Permutate(arr, j, j + 1);
			}
		}
	}
};


class SelectionSort : iSort
{
	virtual string GetName() override {
		return "Bubble Sort:";
	}

	virtual bool Sort(vector<vector<int>>& matrix) override {
		bool isSorted = true;
		for (int i = 0; i < matrix.size(); i++) {
			if (!IsSorted(matrix[i])) {
				SortSubArray(matrix[i]);
				isSorted = false;
			}
		}
		return isSorted;
	}

	void FindMaxIndex(vector<int>& arr, int begin, int &maxIndex) {
		maxIndex = begin;
		begin++;
		for (begin; begin < arr.size(); begin++) {
			if (Compare(arr[begin], arr[maxIndex], isGreater)) {
				maxIndex = begin;
			}
		}
	}

	virtual void SortSubArray(vector<int>& arr) override {
		int maxIndex = 0;
		for (int i = 0; i < arr.size(); i++) {
			FindMaxIndex(arr, i, maxIndex);
			if (i != maxIndex) {
				comparisons++;
				Permutate(arr, i, maxIndex);
			}
		}
	}
};


class InsertionSort : iSort
{

};


class ShellSort : iSort
{

};


class QuickSort : iSort
{

};