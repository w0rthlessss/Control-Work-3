#include "DataInput.h"
#include "UserInterface.h"

void PrintCurrentMatrix(vector<vector<int>>& m, int curH, int curW, int totalW)
{
	int i = 0;
	do {

		if (i == curH) {
			for (int j = 0; j < curW; j++) {
				cout << m[i][j] << "\t";
			}
		}
		else {
			for (int j = 0; j < totalW; j++) {
				cout << m[i][j] << "\t";
			}
			cout << endl;
		}
		i++;
	} while (i <= curH);
}

void ConsoleInput(vector<vector<int>>& matrix)
{
	fstream fout;
	cout<< "Input matrix dimensions : \n";
	int h = 0, w = 0;
	do {
		h = GetInt("Height: ");
		if (h <= 0) { cout << "\nValue must be positive!\n"; continue; }

	} while (h <= 0);

	do {
		w = GetInt("Width: ");
		if (w <= 0) { cout << "\nValue must be positive!\n"; continue; }
	} while (w <= 0);
	matrix.assign(h, vector<int>(w));
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			system("cls");
			Task();
			Fio();
			InputOption(TopMenu::console);
			cout << "Input matrix values:\n";
			PrintCurrentMatrix(matrix, i, j, w);
			matrix[i][j] = GetInt("");
		}
	}
	system("cls");
	Task();
	Fio();
	InputOption(TopMenu::console);
	PrintCurrentMatrix(matrix, h - 1, w, w);
	cout << endl << endl;

	if (SaveResults("matrix data")=='y') {
		SaveConsoleData(fout, matrix);
	}
		
}

bool FileInput(vector<vector<int>>& matrix, fstream &fin)
{
	int matrixH = 0, matrixW = 0, tmp=0;

	if (!fin >> matrixH) {
		cout << "Error! Invalid data in the file! Check height value!\n";
		return false;
	}
	if (!fin >> matrixW) {
		cout << "Error! Invalid data in the file! Check width value!\n";
		return false;
	}

	matrix.assign(matrixH, vector<int>(matrixW));

	for (auto i = 0; i < matrixH; i++) {
		for (auto j = 0; j < matrixW; j++) {
			if (!fin >> tmp) {
				cout << "Error! Invalid data in the file! Check matrix values!\n";
				matrix.clear();
				return false;
			}
			matrix[i][j] = tmp;
		}
	}

	system("cls");
	Task();
	Fio();
	InputOption(TopMenu::console);
	PrintCurrentMatrix(matrix, matrixH, matrixW, matrixW);

	fin.close();
	return true;
}

void RandomInput(vector<vector<int>>& matrix)
{
	srand(static_cast<unsigned int>(time(NULL)));
	fstream fout;
	cout << "Input matrix dimensions : \n";
	int h = 0, w = 0;
	do {
		h = GetInt("Height: ");
		if (h <= 0) { cout << "\nValue must be positive!\n"; continue; }
		
	} while (h <= 0);

	do {
		w = GetInt("Width: ");
		if (w <= 0) { cout << "\nValue must be positive!\n"; continue; }
	} while (w <= 0);
	matrix.assign(h, vector<int>(w));

	int lowerRange = -99, upperRange = 99;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			matrix[i][j] = lowerRange + rand() % (upperRange + 1 - lowerRange);
		}
	}

	system("cls");
	Task();
	Fio();
	InputOption(TopMenu::console);
	PrintCurrentMatrix(matrix, h-1, w, w);
	cout << endl << endl;
	if (SaveResults("matrix data")=='y') {
		SaveConsoleData(fout, matrix);
	}
}
