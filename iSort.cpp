#include "iSort.h"

//конструктор по умолчанию
iSort::iSort()
{
	comparisons = 0;
	permutations = 0;
}

//получить количество перестановок
int iSort::GetPermutations()
{
	return permutations;
}

//получить количество сравнений
int iSort::GetComparisons()
{
	return comparisons;
}

//функция для сравнения двух значений
bool iSort::Compare(int x, int y, int mode)
{
	comparisons++;
	if (mode == ComaparisonOptions::strict) return x > y;
	else return x >= y;
}

//функция для перестановки двух элементов в векторе
void iSort::Permutate(vector<int>& a, int pos1, int pos2)
{
	permutations++;
	swap(a[pos1], a[pos2]);
}

//проверка на отсортированность строки матрицы
//bool iSort::IsSorted(vector<int>& arr)
//{
//	if (arr.size() == 1) return true;
//	for (int i = 0; i < arr.size()-1; i++) {
//		if (abs(arr[i]) < abs(arr[i + 1])) return false;
//	}
//	return true;
//}

//отсортировать все строки матрицы
void iSort::SortMatrix(vector<vector<int>>& matrix)
{
	for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
		Sort(matrix[i]);
	}
}


