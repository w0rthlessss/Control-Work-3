#pragma once
#include <fstream>
#include "SortingMethods.h"
#include <filesystem>


using namespace filesystem;

string OpenFile(int option, fstream& file);

void GetResults(int mode, vector<pair<string, pair<int, int>>> results, fstream &fout, bool ask);

void PrintMatrix(vector<vector<int>>& matrix, int mode, string msg, fstream &fout, bool ask);

char SaveResults(string msg);

void SaveConsoleData(fstream &fout, vector<vector<int>> matrix);

