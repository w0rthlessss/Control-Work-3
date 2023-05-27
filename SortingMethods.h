#pragma once
#include "iSort.h"

//���������� ���������
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

//���������� �������
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

//���������� ���������
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

//���������� �����
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

//������� ����������
class QuickSort : public iSort
{
public:
	virtual ~QuickSort() = default;
	virtual string GetName() override {
		return "Quick Sort";
	}

	void QSort(vector<int>& arr, int start, int end) {
		int i = start, j = end, pivot = arr[(start + end)/2];
		while (i <= j) {
			while (Compare(abs(arr[i]), abs(pivot), ComaparisonOptions::strict)) i++;
			while (Compare(abs(pivot), abs(arr[j]), ComaparisonOptions::strict)) j--;
			if (i <= j) {
				Permutate(arr, i, j);
				i++;
				j--;
			}
		}

		if (start < j) QSort(arr, start, j);

		if (i < end) QSort(arr, i, end);
	}


	virtual void Sort(vector<int>& arr) override {
		QSort(arr, 0, static_cast<int>(arr.size()) - 1);
	}
};