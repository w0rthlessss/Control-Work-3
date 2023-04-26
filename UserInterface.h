#pragma once
#include "SortingMethods.h"
#include "DataInput.h"
#include "OutputFunctions.h"

void Continue();

void WorkWithConsole(vector<vector<int>>& matrix, bool isRandom);

void WorkWithFile(vector<vector<int>>& matrix);

void CertainSort(vector<vector<int>>& matrix, int mode, fstream &fout);

void Task();

void Fio();

void OptionsTop();

void InputOption(int option);

void OptionsBottom();

void SubOptionsBottom();

void IncorrectOption();

template<class algorithm>
pair<string, pair<int, int>> SortWithCertainMethod(vector<vector<int>>& matrix, int mode, fstream& fout, bool isOnly);

vector<pair<string, pair<int, int>>> SortWithAllMethods(vector<vector<int>>& matrix, int mode, fstream& fout);

bool isMatrixSorted(vector<vector<int>>& matrix);