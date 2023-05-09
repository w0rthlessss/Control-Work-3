#pragma once
#include <fstream>
#include "SortingMethods.h"
#include <filesystem>


using namespace filesystem;

string OpenFile(int option, fstream& file);

void GetResults(vector<pair<string, pair<int, int>>> results, fstream& fout, char ans);

void PrintMatrix(vector<vector<int>>& matrix, string msg, fstream &fout, char ans);

char SaveResults(string msg);

void SaveConsoleData(fstream &fout, vector<vector<int>> matrix);

