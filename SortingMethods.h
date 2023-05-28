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
		bool isSwaped = true;
		int i = 0;
		while(isSwaped){
			isSwaped = false;
			for (int j = 0; j < arr.size() - 1 - i; j++) {
				if (Compare(abs(arr[j + 1]), abs(arr[j]), ComaparisonOptions::strict)) {
					Permutate(arr, j, j + 1);
					isSwaped = true;
				}
			}
			i++;
		}
		/*for (int i = 0; i < static_cast<int>(arr.size()); i++) {
			for (int j = 0; j < static_cast<int>(arr.size()) - 1 - i; j++) {
				if (!Compare(abs(arr[j]), abs(arr[j + 1]), ComaparisonOptions::nonStrict)) Permutate(arr, j, j + 1);
			}
		}*/
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
			int j = i - 1;
			int elem = arr[i];
			int comps = GetComparisons();
			int loc = [&comps](vector<int> arr, int elem, int low, int high) {
				while (low <= high) {
					int mid = low + (high - low) / 2;
					comps++;
					if (abs(elem) == abs(arr[mid])) return mid + 1;
					else if (abs(elem) > abs(arr[mid])) high = mid - 1;
					else low = mid + 1;
				}
			return low; }(arr, elem, 0, j);
			comparisons = comps;

			if(abs(elem) >= abs(arr[j])) continue;

			while (j >= loc) {
				arr[j + 1] = arr[j];
				j--;
				permutations++;
			}
			arr[j + 1] = elem;
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

	/*int Partition(vector<int>& arr, int low, int high) {
		int pivot = abs(arr[high]);
		int i = low - 1;

		for (int j = low; j < high; j++) {
			if (Compare(abs(arr[j]), pivot, ComaparisonOptions::nonStrict)) {
				i++;
				Permutate(arr, i, j);
			}
		}

		Permutate(arr, i + 1, high);
		return i + 1;
	}*/

	void QSort(vector<int>& arr, int low, int high) {
		/*if (low < high) {
			int pIndex = Partition(arr, low, high);

			QSort(arr, low, pIndex - 1);

			QSort(arr, pIndex + 1, high);
		}*/
		int i = low, j = high, pivot = arr[(low + high)/2];
		while (i <= j) {
			while (Compare(abs(arr[i]), abs(pivot), ComaparisonOptions::strict)) i++;
			while (Compare(abs(pivot), abs(arr[j]), ComaparisonOptions::strict)) j--;
			if (i <= j) {
				Permutate(arr, i, j);
				i++;
				j--;
			}
		}

		if (low < j) QSort(arr, low, j);

		if (i < high) QSort(arr, i, high);
	}


	virtual void Sort(vector<int>& arr) override {
		QSort(arr, 0, static_cast<int>(arr.size()) - 1);
	}
};