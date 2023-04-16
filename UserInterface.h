#pragma once
#include "Student.h"
#include <fstream>
#include <vector>

enum WorkWithFiles { input, output };
enum TopMenu { console = 1, file, module, quit };
enum BottomMenu { all = 1, university, course, group, back };

void WorkWithConsole(vector<Student>& students, int& actionBottom);

void WorkWithFile(vector<Student>& students, int& actionBottom);

void Fio();

void OptionsTop();

void InputOption(int option);

void OptionsBottom();

void IncorrectOption();

char SaveResults(fstream& fout);

string OpenFile(int option, fstream& file);

void StartProgram();