#include "DataInput.h"
#include "UserInterface.h"

//вывод на консоль текущей матрицы (по ходу ее заполнения)
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

//ввод матрицы с консоли
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

	cout << "Matrix " << h << "x" << w << endl << endl;
	PrintCurrentMatrix(matrix, h - 1, w, w);
	cout << endl << endl;

	if (SaveResults("matrix data")=='y') {
		SaveConsoleData(fout, matrix);
	}
		
}

//ввод матрицы с файла
bool FileInput(vector<vector<int>>& matrix, fstream &fin, bool isForTest)
{
	int matrixH = 0, matrixW = 0, tmp=0;
	fin >> matrixH;
	if (fin.fail()) {
		cout << "\nError! Invalid data in the file! Check height value!\n";
		return false;
	}

	fin >> matrixW;
	if (fin.fail()) {
		cout << "\nError! Invalid data in the file! Check width value!\n";
		return false;
	}

	if (matrixH <= 0 || matrixW <= 0) {
		cout << "\nError! Matrix dimensions could not be lesser than 1!\n";
		return false;
	}

	matrix.assign(matrixH, vector<int>(matrixW));

	for (auto i = 0; i < matrixH; i++) {
		for (auto j = 0; j < matrixW; j++) {
			fin >> tmp;
			if (fin.fail()) {
				cout << "\nError! Invalid data in the file! Check matrix values!\n";
				matrix.clear();
				return false;
			}
			matrix[i][j] = tmp;
		}
	}

	if (!isForTest) {
		system("cls");
		Task();
		Fio();
		InputOption(TopMenu::file);
	}
	
	//PrintCurrentMatrix(matrix, matrixH-1, matrixW, matrixW);

	fin.close();
	return true;
}

//рандомное заполнение матрицы
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
	InputOption(TopMenu::random);
	cout << "Matrix " << h << "x" << w << endl << endl;
	PrintCurrentMatrix(matrix, h-1, w, w);
	cout << endl << endl;
	if (SaveResults("matrix data")=='y') {
		SaveConsoleData(fout, matrix);
	}
}
