#pragma once
#include "SortingMethods.h"
#include "DataInput.h"
#include "OutputFunctions.h"

void Continue();

void WorkWithConsole(vector<vector<int>>& matrix, bool isRandom);

void WorkWithFile(vector<vector<int>>& matrix);

void CertainSort(vector<vector<vector<int>>>& matrices, fstream &fout);

void Task();

void Fio();

void OptionsTop();

void InputOption(int option);

void OptionsBottom();

void SubOptionsBottom();

void IncorrectOption();

pair<string, pair<int, int>> SortWithCertainMethod(shared_ptr<iSort> sort, vector<vector<int>>& matrix, fstream& fout);

vector<pair<string, pair<int, int>>> SortWithAllMethods(vector<vector<vector<int>>>& matrices, fstream& fout);

