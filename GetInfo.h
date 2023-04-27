#pragma once

#include <iostream>
#include <limits>
#include <string>
#include <fstream>

enum WorkWithFiles { input, output };
enum TopMenu { console = 1, file, random, module, quit };
enum BottomMenu { all = 1, certain, back };
enum SubBottomMenu { bubble = 1, selection, insertion, shell, quick, compare, backToBottom };


using namespace std;

void IgnoreLine();
int GetInt(string s);
string GetString(string s, int i);
string GetLink(string s);
string GetString(string s);
char GetChar(string s);