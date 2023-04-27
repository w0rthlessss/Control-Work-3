#include "UserInterface.h"
#include <set>
#include "GetInfo.h"

//функция очищающая консоль для повторной работы программы
void Continue()
{
	cout << "\nPress Enter key to continue...\n";
	if (getchar()!='\n') {
		IgnoreLine();
	}
	system("cls");
	Task();
	Fio();
}

//чтение данных с консоли и работа с ними
void WorkWithConsole(vector<vector<int>>& matrix, bool isRandom)
{
	fstream fout;
	vector<vector<int>> temporaryMatrix;
	int actionBottom = 1;
	if (isRandom) RandomInput(matrix);
	else ConsoleInput(matrix);
	bool ask = true;
	while (actionBottom != BottomMenu::back) {
		PrintMatrix(matrix, TopMenu::console, "Original", fout, ask);

		if (IsMatrixSorted(matrix)) {
			cout << "\nMatrix is already sorted!\n\n";
			break;
		}

		OptionsBottom();
		actionBottom = GetInt(">>");
		
		
		switch (actionBottom)
		{
		case BottomMenu::all:
			temporaryMatrix = matrix;
			if (SaveResults("future sort results") == 'y') 
				GetResults(TopMenu::file, SortWithAllMethods(temporaryMatrix, TopMenu::file, fout), fout, false);

			else GetResults(TopMenu::console, SortWithAllMethods(temporaryMatrix, TopMenu::console, fout), fout, false);
			fout.close();
			actionBottom = BottomMenu::back;
			Continue();
			break;

		case BottomMenu::certain:
			CertainSort(matrix, TopMenu::console, fout);
			fout.close();
			actionBottom = BottomMenu::back;
			Continue();
			break;

		case BottomMenu::back:
			system("cls");
			Task();
			Fio();
			break;
		default:
			IncorrectOption();
			break;
		}
		ask = false;
	}
}

//чтение данных из файла и работа с ними
void WorkWithFile(vector<vector<int>>& matrix)
{
	vector<vector<int>> temporaryMatrix;
	int actionBottom = 1;
	fstream fin;
	fstream fout;
	bool isCorrect = false;
	do {
		string name = OpenFile(WorkWithFiles::input, fin);
		isCorrect = FileInput(matrix, fin, false);
		fin.close();
	} while (!isCorrect);

	while (actionBottom != back) {
		PrintMatrix(matrix, TopMenu::file, "Original", fout, false);
		if (IsMatrixSorted(matrix)) {
			cout << "\nMatrix is already sorted!\n\n";
			break;
		}
		OptionsBottom();
		actionBottom = GetInt(">>");
		
		switch (actionBottom)
		{
		case BottomMenu::all:
			temporaryMatrix = matrix;
			GetResults(TopMenu::file, SortWithAllMethods(temporaryMatrix, TopMenu::file, fout), fout, false);
			fout.close();
			actionBottom = BottomMenu::back;
			Continue();
			break;

		case BottomMenu::certain:
			CertainSort(matrix, TopMenu::file, fout);
			fout.close();
			actionBottom = BottomMenu::back;
			Continue();
			break;

		case BottomMenu::back:
			system("cls");
			Task();
			Fio();
			break;
		default:
			IncorrectOption();
			break;
		}
	}
}

//выбор метода сортировки
void CertainSort(vector<vector<int>>& matrix, int mode, fstream &fout)
{
	vector<vector<int>> temporaryMatrix = matrix;
	vector<pair<string, pair<int, int>>> res;
	int actionSubBottom = 1;
	set<int> used;
	bool isOnly = true;
	while (actionSubBottom != SubBottomMenu::backToBottom && actionSubBottom != SubBottomMenu::compare) {
		SubOptionsBottom();
		actionSubBottom = GetInt(">>");
		switch (actionSubBottom)
		{
		case SubBottomMenu::bubble:
			temporaryMatrix = matrix;
			if (used.find(actionSubBottom) != used.end()) {
				cout << "You have already used this sorting method!\n";
				break;
			}
			res.push_back(SortWithCertainMethod<BubbleSort>(temporaryMatrix, mode, fout, isOnly));
			used.insert(actionSubBottom);
			break;

		case SubBottomMenu::selection:
			temporaryMatrix = matrix;
			if (used.find(actionSubBottom) != used.end()) {
				cout << "You have already used this sorting method!\n";
				break;
			}
			res.push_back(SortWithCertainMethod<SelectionSort>(temporaryMatrix, mode, fout, isOnly));
			used.insert(actionSubBottom);
			break;

		case SubBottomMenu::insertion:
			temporaryMatrix = matrix;
			if (used.find(actionSubBottom) != used.end()) {
				cout << "You have already used this sorting method!\n";
				break;
			}
			res.push_back(SortWithCertainMethod<InsertionSort>(temporaryMatrix, mode, fout, isOnly));
			used.insert(actionSubBottom);
			break;

		case SubBottomMenu::shell:
			temporaryMatrix = matrix;
			if (used.find(actionSubBottom) != used.end()) {
				cout << "You have already used this sorting method!\n";
				break;
			}
			res.push_back(SortWithCertainMethod<ShellSort>(temporaryMatrix, mode, fout, isOnly));
			used.insert(actionSubBottom);
			break;

		case SubBottomMenu::quick:
			temporaryMatrix = matrix;
			if (used.find(actionSubBottom) != used.end()) {
				cout << "You have already used this sorting method!\n\n";
				break;
			}
			res.push_back(SortWithCertainMethod<QuickSort>(temporaryMatrix, mode, fout, isOnly));
			used.insert(actionSubBottom);
			break;

		case SubBottomMenu::compare:
			GetResults(mode, res, fout, isOnly);
			res.clear();
			used.clear();
			break;

		case SubBottomMenu::backToBottom:
			system("cls");
			Task();
			Fio();
			break;

		default:
			IncorrectOption();
			break;
		}
	}
}

//формулировка задания
void Task()
{
	cout << "Make a program for sorting data using methods of: \"Bubble Sort\", \"Selection Sort\", \"Insertion Sort\", \"Shell Sort\" and \"Quick Sort\".\n";
	cout << "Print unsorted matrix (once) and sorted matrixes (for each method). And create a comparison table.\n";
	cout << "Matrix must be sorted in descending absoulute values in each line\n";
	cout << "Matrix may be filled from console, file or using random values.\n";
	cout << "Create abstract class \"iSort\" containing pure virtual method Sort, wich will be inherited by subclasses of sorting methods.\n\n";
}

//вывод данных о выполнившем
void Fio()
{
	cout << "Control work #3\nEfremov Ivan Andreevich\nGroup #423\nVariant #8\n\n";
}

//меню верхнего уровня
void OptionsTop()
{
	cout << "\n1 - Console input\n2 - File input\n3 - Random input\n4 - Run module tests\n5 - Exit\n\n";
}

//вывод метода заполнения матрицы
void InputOption(int option)
{
	if (option == TopMenu::console) {
		cout << "\n<<Console Input>>\n\n";
	}
	else if (option == TopMenu::file) {
		cout << "\n<<File Input>>\n\n";
	}
	else if(option == TopMenu::random){
		cout << "\n<<Random Input>>\n\n";
	}
}

//меню нижнего уровня
void OptionsBottom()
{
	cout << "\n\n1 - Sort with all methods\n";
	cout << "2 - Sort with certain methods\n";
	cout << "3 - Back\n\n";
}

//меню с алгоритмами сортировки
void SubOptionsBottom()
{
	cout << "\n\n1 - Bubble Sort\n";
	cout << "2 - Selection Sort\n";
	cout << "3 - Insertion Sort\n";
	cout << "4 - Shell Sort\n";
	cout << "5 - Quick Sort\n";
	cout << "6 - Compare\n";
	cout << "7 - Back\n\n";
}

//пользователь выбрал несуществующий пункт меню
void IncorrectOption()
{
	cout << "\nThere is no such option in menu!\n\n";
}

//использовать определённую сортировку
template<class algorithm>
pair<string, pair<int, int>> SortWithCertainMethod(vector<vector<int>>& matrix, int mode, fstream& fout, bool isOnly) {
	algorithm sort;
	PrintMatrix(matrix, mode, sort.GetName() + "ed", fout, isOnly);
	return make_pair(sort.GetName(), make_pair(sort.GetComparisons(), sort.GetPermutations()));
}

//использовать все сортировки
vector<pair<string, pair<int, int>>> SortWithAllMethods(vector<vector<int>>& matrix, int mode, fstream& fout) {
	vector<pair<string, pair<int, int>>> a;
	vector<vector<int>> tmpMatrix;

	if (mode == TopMenu::file && !fout.is_open()) {
		string name = OpenFile(WorkWithFiles::output, fout);
	}

	tmpMatrix = matrix;
	a.push_back(SortWithCertainMethod<BubbleSort>(tmpMatrix, mode, fout, false));

	tmpMatrix = matrix;
	a.push_back(SortWithCertainMethod<SelectionSort>(tmpMatrix, mode, fout, false));

	tmpMatrix = matrix;
	a.push_back(SortWithCertainMethod<InsertionSort>(tmpMatrix, mode, fout, false));

	tmpMatrix = matrix;
	a.push_back(SortWithCertainMethod<ShellSort>(tmpMatrix, mode, fout, false));

	tmpMatrix = matrix;
	a.push_back(SortWithCertainMethod<QuickSort>(tmpMatrix, mode, fout, false));

	return a;
}

//проверка на отсортированность матрицы
bool IsMatrixSorted(vector<vector<int>>& matrix) {
	BubbleSort tmp;
	bool isSorted = true;
	for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
		if (!tmp.IsSorted(matrix[i])) return false;
	}
	return isSorted;
}