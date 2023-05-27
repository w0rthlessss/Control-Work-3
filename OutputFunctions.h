#pragma once
#include <fstream>
#include "SortingMethods.h"
#include <filesystem>


using namespace filesystem;

string OpenFile(int option, fstream& file);

void GetResults(vector<pair<string, pair<int, int>>> results, vector<vector<vector<int>>> matrices);

void PrintMatrix(vector<vector<int>>& matrix, string msg, fstream &fout, int mode);

char SaveResults(string msg);

void SaveConsoleData(fstream &fout, vector<vector<int>> matrix);

