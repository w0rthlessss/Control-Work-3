#include "OutputFunctions.h"
#include <io.h>
#include <cerrno>
//вывод таблицы сравнения
void GetResults(vector<pair<string, pair<int, int>>> results, vector<vector<vector<int>>> matrices) {
	if (results.empty()) {
		cout << "\nThere isn't anything to comare!\n\n";
		return;
	}

	cout << "\n\nSorting efficiency comparison:\n\n";
	cout << "\t\tComparisons\tPermutations\n";
	for (int i = 0; i < static_cast<int>(results.size()); i++) {
		cout << results[i].first << '\t' << results[i].second.first << '\t' << '\t' << results[i].second.second << endl;
	}
	cout << endl;

	if (SaveResults("Do you want to save sorting results in the file?") == 'y') {
		fstream fout;
		string names[6] = { "Original", "Bubble sorted", "Selection sorted", "Insertion sorted", "Shell sorted", "Quick sorted" };
		string name = OpenFile(WorkWithFiles::output, fout);
		
		for (int i = 1; i < 6; i++) {
			if (matrices[i] != matrices[0]) {
				PrintMatrix(matrices[i], names[i], fout, TopMenu::file);
			}
		}

		fout << "\n\nSorting efficiency comparison:\n\n";
		fout << "\tComparisons\tPermutations\n";
		for (int i = 0; i < static_cast<int>(results.size()); i++) {
			fout << results[i].first << '\t' << results[i].second.first << '\t' << results[i].second.second << endl;
		}
		fout << endl;
	}

}

//вывод исходной либо отсортированной матрицы
void PrintMatrix(vector<vector<int>>& matrix, string msg, fstream &fout, int mode)
{
	if (mode == TopMenu::console) {
		cout << endl << msg << " matrix:\n\n";
		for (auto i = 0; i < matrix.size(); i++) {
			for (auto j = 0; j < matrix[i].size(); j++) {
				cout << matrix[i][j] << '\t';
			}
			cout << "\n";
		}
	}
	
	//cout << '\n';

	if (mode==TopMenu::file) {
		if (!fout.is_open()) {
			string name = OpenFile(WorkWithFiles::output, fout);
		}

		fout << endl << msg << " matrix:\n\n";
		for (auto i = 0; i < matrix.size(); i++) {
			for (auto j = 0; j < matrix[i].size(); j++) {
				fout << matrix[i][j] << ' ';
			}
			fout << "\n";
		}
		//fout << '\n';
	}

}

//предложить пользователю сохранить результат в файл
char SaveResults(string msg)
{
	cout << "\n" << msg << " (y / n)\n\n";
	char res = 'n';
	do {
		res = GetChar(">>");
		if (res != 'y' && res != 'n') {
			cout << "Incorrect input. Type 'y' or 'n' only!\n\n";
		}
	} while (res != 'y' && res != 'n');

	return res;
}

//сохранить данные матрицы в файл
void SaveConsoleData(fstream& fout, vector<vector<int>> matrix)
{
	string name = OpenFile(WorkWithFiles::output, fout);
	fout << matrix.size() << ' ' << matrix[0].size()<<endl;
	for (auto i = 0; i < matrix.size(); i++) {
		for (auto j = 0; j < matrix[i].size(); j++) {
			fout << matrix[i][j] << ' ';
		}
		fout << '\n';
	}
	fout.close();
}


//открытие файла для чтения или записи
string OpenFile(int option, fstream& file)
{
	string name = "";

	if (option == WorkWithFiles::input) {
		do {
			name = GetLink("\nEnter the name of file with data. Example: students.txt\n");
			
			if (_access(name.c_str(), 0) == 0) {
				file.open(name.c_str(), ios::in);
			}
			else {
				if (errno == ENOENT) {
					cout << "\nError opening file. Make sure, that file exists!\n";
					continue;
				}
				else {
					cout << "\nAdress contains forbidden value!\n";
					continue;
				}
			}
			

			return name;
		} while (true);


	}
	else {
		do {
			name = GetLink("\nEnter the name of file where results will be stored.\nExample: results.txt\n\n");
			
			if (_access(name.c_str(), 0) == 0) {

				if (exists(name)) {
					if (SaveResults("\nFile exists. Do you want to overwrite current data in the file") == 'n') continue;
				}

				file.open(name.c_str(), ios::out);
			}
			else {
				if (errno == ENOENT) {
					file.open(name.c_str(), ios::out);
				}
				else {
					cout << "\nAdress contains forbidden value!\n";
					continue;
				}
			}

			return name;
		} while (true);

	}
		
}