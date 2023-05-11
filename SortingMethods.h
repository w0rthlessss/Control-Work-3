#pragma once
#include "iSort.h"

//сортировка пузырьком
class BubbleSort : public iSort
{
public:
	virtual ~BubbleSort() = default;
	virtual string GetName() override {
		return "Bubble Sort";
	}

	virtual void Sort(vector<int>& arr) override {
		for (int i = 0; i < static_cast<int>(arr.size()); i++) {
			for (int j = 0; j < static_cast<int>(arr.size()) - 1; j++) {
				if (!Compare(abs(arr[j]), abs(arr[j + 1]), ComaparisonOptions::nonStrict)) Permutate(arr, j, j + 1);
			}
		}
	}
};

//сортировка выбором
class SelectionSort : public iSort
{
public:
	virtual ~SelectionSort() = default;
	virtual string GetName() override {
		return "Selection Sort";
	}

	void FindMaxIndex(vector<int>& arr, int begin, int& maxIndex) {
		maxIndex = begin;
		begin++;
		for (begin; begin < arr.size(); begin++) {
			if (Compare(abs(arr[begin]), abs(arr[maxIndex]), ComaparisonOptions::strict)) {
				maxIndex = begin;
			}
		}
	}

	virtual void Sort(vector<int>& arr) override {
		int maxIndex = 0;
		for (int i = 0; i < static_cast<int>(arr.size()); i++) {
			FindMaxIndex(arr, i, maxIndex);
			if (i != maxIndex) {
				//comparisons++;
				Permutate(arr, i, maxIndex);
			}
		}
	}
};

//сортировка вставками
class InsertionSort : public iSort
{
public:
	virtual ~InsertionSort() = default;
	virtual string GetName() override {
		return "Insertion Sort";
	}

	virtual void Sort(vector<int>& arr) {
		for (int i = 1; i < static_cast<int>(arr.size()); i++) {
			for (int j = i; j > 0; j--) {
				if (!Compare(abs(arr[j - 1]), abs(arr[j]), ComaparisonOptions::nonStrict)) {
					Permutate(arr, j - 1, j);
				}
			}
		}
	}
};

//сортировка шелла
class ShellSort : public iSort
{
public:
	virtual ~ShellSort() = default;
	virtual string GetName() override {
		return "Shell Sort";
	}

	virtual void Sort(vector<int>& arr) {

		int gap = static_cast<int>(arr.size())/2;
		while (gap > 0) {
			for (int i = 0; i < static_cast<int>(arr.size()) - gap; i++) {
				int j = i;
				while (j >= 0 && !Compare(abs(arr[j]), abs(arr[j + gap]), ComaparisonOptions::nonStrict)) {
					Permutate(arr, j, j + gap);
					j--;
				}
			}
			gap /= 2;
		}
	}
};

//быстрая сортировка
class QuickSort : public iSort
{
public:
	virtual ~QuickSort() = default;
	virtual string GetName() override {
		return "Quick Sort";
	}

	int Partition(vector<int> &arr, int start, int end)
	{
		int pivot = arr[end];
		int pIndex = start;

		for (int i = start; i < end; i++)
		{
			if (Compare(abs(arr[i]), abs(pivot), ComaparisonOptions::strict))
			{
				Permutate(arr, i, pIndex);;
				pIndex++;
			}
		}

		//swap(arr[pIndex], arr[end]);
		Permutate(arr, pIndex, end);

		return pIndex;
	}

	void QSort(vector<int>& arr, int start, int end) {

		if (start >= end) {
			return;
		}

		int pivot = Partition(arr, start, end);

		
		QSort(arr, start, pivot - 1);


		QSort(arr, pivot + 1, end);

	}


	virtual void Sort(vector<int>& arr) override {
		QSort(arr, 0, static_cast<int>(arr.size()) - 1);
	}
};