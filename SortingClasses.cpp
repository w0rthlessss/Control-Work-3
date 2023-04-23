#pragma once
#include "iSort.h"

class BubbleSort : iSort
{
	virtual string GetName() override {
		return "Bubble Sort:";
	}

	virtual void Sort(vector<int>& arr) override {
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr.size() - 1; j++) {
				if (!Compare(abs(arr[j]), abs(arr[j + 1]), ComaparisonOptions::nonStrict)) Permutate(arr, j, j + 1);
			}
		}
	}
};


class SelectionSort : iSort
{
	virtual string GetName() override {
		return "Selection Sort:";
	}

	void FindMaxIndex(vector<int>& arr, int begin, int &maxIndex) {
		maxIndex = begin;
		begin++;
		for (begin; begin < arr.size(); begin++) {
			if (Compare(abs(arr[begin]), abs(arr[maxIndex]), ComaparisonOptions::nonStrict)) {
				maxIndex = begin;
			}
		}
	}

	virtual void Sort(vector<int>& arr) override {
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
	virtual string GetName() override {
		return "Insertion Sort:";
	}

	virtual void Sort(vector<int> &arr) {
		for (int i = 1; i < arr.size(); i++) {
			for (int j = i; j > 0; j--) {
				if (!Compare(abs(arr[j - 1]), abs(arr[j]), ComaparisonOptions::nonStrict)) {
					Permutate(arr, j-1, j);
				}
			}
		}
	}
};


class ShellSort : iSort
{
	virtual string GetName() override {
		return "Shell Sort:";
	}

	virtual void Sort(vector<int>& arr) {
		for (int gap = arr.size() / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < arr.size(); i += 1)
			{
				int tmp = arr[i];

				int j = 0;
				for (j = i; j >= gap; j -= gap) 
					if(!Compare(abs(arr[j-gap]), abs(tmp), ComaparisonOptions::nonStrict)) arr[j] = arr[j - gap];
				arr[j] = tmp;
			}
		}
	}
};


class QuickSort : iSort
{
	virtual string GetName() override {
		return "Quick Sort:";
	}

	int Partition(vector<int>& arr, int aBegin, int aEnd) {

		int pivot = arr[aEnd];
		int pivotIndex = aBegin;
		for (int i = aBegin; i < aEnd; i++) {
			if (!Compare(abs(arr[i]), abs(arr[pivotIndex]), ComaparisonOptions::strict)) {
				Permutate(arr, i, pivotIndex);
				pivotIndex++;
			}
		}
		Permutate(arr, pivotIndex, aEnd);
		return pivotIndex;
	}

	void QSort(vector<int>& arr, int aBegin, int aEnd) {

		if (aBegin >= aEnd) return;
		
		int pivotIndex = Partition(arr, aBegin, aEnd);

		QSort(arr, aBegin, pivotIndex - 1);

		QSort(arr, pivotIndex + 1, aEnd);
	}


	virtual void Sort(vector<int>& arr) override {
		QSort(arr, 0, arr.size() - 1);
	}


};