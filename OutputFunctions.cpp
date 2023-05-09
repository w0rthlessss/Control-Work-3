#include "OutputFunctions.h"

//вывод таблицы сравнения
void GetResults(vector<pair<string, pair<int, int>>> results, fstream &fout, char ans) {
	if (results.empty()) {
		cout << "\nThere isn't anything to comare!\n\n";
		return;
	}

	cout << "Sorting efficiency comparison:\n\n";
	cout << "\tComparisons\tPermutations\n";
	for (int i = 0; i < static_cast<int>(results.size()); i++) {
		cout << results[i].first << '\t' << results[i].second.first << '\t' << results[i].second.second << endl;
	}
	cout << endl;

	if (ans  == 'y') {
		if (!fout.is_open()) {
			string name = OpenFile(WorkWithFiles::output, fout);
		}
		
		fout << "\nSorting efficiency comparison:\n\n";
		fout << "\tComparisons\tPermutations\n";
		for (int i = 0; i < static_cast<int>(results.size()); i++) {
			fout << results[i].first << '\t' << results[i].second.first << '\t' << results[i].second.second << endl;
		}
		fout << endl;
	}

}

//вывод исходной либо отсортированной матрицы
void PrintMatrix(vector<vector<int>>& matrix, string msg, fstream &fout, char ans)
{
	cout << endl << msg << " matrix:\n\n";
	for (auto i = 0; i < matrix.size(); i++) {
		for (auto j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << '\t';
		}
		cout << "\n";
	}
	cout << '\n';

	if (ans=='y') {
		if (!fout.is_open()) {
			string name = OpenFile(WorkWithFiles::output, fout);
		}

		fout << msg << " matrix:\n\n";
		for (auto i = 0; i < matrix.size(); i++) {
			for (auto j = 0; j < matrix[i].size(); j++) {
				fout << matrix[i][j] << ' ';
			}
			fout << "\n";
		}
		fout << '\n';
	}

}

//предложить пользователю сохранить результат в файл
char SaveResults(string msg)
{
	cout << "Do you want to save " << msg << " in the file ? (y / n)\n\n";
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
	error_code ec;
	if (option == WorkWithFiles::input) {
		do {
			name = GetLink("\nEnter the name of file with data.\nExample: matrix.txt\n");
			file.open(name, ios::in);
			if (!file.is_open()) {
				cout << "\nError opening file. Make sure, that file exists!\n";
				continue;
			}

			else if (!is_regular_file(name, ec)) {
				cout << "\nAdress contains forbidden value. Try another file path!\n";
				continue;
			}
			else return name;

		} while (true);
		

	}
	else {
			do {
				name = GetLink("\nEnter the name of file where results will be stored.\nIf there is data in the file it will be overwritten.\nExample: filtered.txt\n");

				file.open(name, ios::out, ios::trunc);

				if (!file.is_open()) {
					cout << "\nError opening file. Make sure, that file exists!\n";
					continue;
				}

				else if (!is_regular_file(name, ec)) {
					cout << "\nAdress contains forbidden value. Try another file path!\n";
					continue;
				}

				else return name;

			} while (true);
	}
		
}