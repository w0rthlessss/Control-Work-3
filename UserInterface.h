#pragma once
#include "SortingMethods.h"
#include "DataInput.h"
#include "OutputFunctions.h"

void Continue();

void WorkWithConsole(vector<vector<int>>& matrix, bool isRandom);

void WorkWithFile(vector<vector<int>>& matrix);

void CertainSort(vector<vector<int>>& matrix, fstream &fout, char ans);

void Task();

void Fio();

void OptionsTop();

void InputOption(int option);

void OptionsBottom();

void SubOptionsBottom();

void IncorrectOption();

pair<string, pair<int, int>> SortWithCertainMethod(std::shared_ptr<iSort> sort, vector<vector<int>>& matrix, fstream& fout, char ans);

vector<pair<string, pair<int, int>>> SortWithAllMethods(vector<vector<int>>& matrix, fstream& fout, char ans);

