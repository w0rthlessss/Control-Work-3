#pragma once
#include "SortingMethods.h"

void PrintCurrentMatrix(vector<vector<int>>& m, int curH, int curW, int totalW);

void ConsoleInput(vector<vector<int>> &matrix);

bool FileInput(vector<vector<int>>& matrix, fstream& fin, bool isForTest);

void RandomInput(vector<vector<int>>& matrix);