#include "iSort.h"

//����������� �� ���������
iSort::iSort()
{
	comparisons = 0;
	permutations = 0;
}

//�������� ���������� ������������
int iSort::GetPermutations()
{
	return permutations;
}

//�������� ���������� ���������
int iSort::GetComparisons()
{
	return comparisons;
}

//������� ��� ��������� ���� ��������
bool iSort::Compare(int x, int y, int mode)
{
	comparisons++;
	if (mode == ComaparisonOptions::strict) return x > y;
	else return x >= y;
}

//������� ��� ������������ ���� ��������� � �������
void iSort::Permutate(vector<int>& a, int pos1, int pos2)
{
	permutations++;
	swap(a[pos1], a[pos2]);
}

//������������� ��� ������ �������
void iSort::SortMatrix(vector<vector<int>>& matrix)
{
	for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
		Sort(matrix[i]);
	}
}


