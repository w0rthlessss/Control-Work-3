#include "UserInterface.h"
#include <set>
#include "GetInfo.h"

#define mtSize 6

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
	vector<vector<vector<int>>> matrices;
	int actionBottom = 1;
	if (isRandom) RandomInput(matrix);
	else ConsoleInput(matrix);
	matrices.assign(mtSize, matrix);
	vector<pair<string, pair<int, int>>> results;
	while (actionBottom != BottomMenu::back) {
		PrintMatrix(matrix, "Original", fout, TopMenu::console);

		OptionsBottom();
		actionBottom = GetInt(">>");
		
		
		switch (actionBottom)
		{
		case BottomMenu::all:
			results = SortWithAllMethods(matrices, fout);
			GetResults(results, matrices);
			fout.close();
			actionBottom = BottomMenu::back;
			Continue();
			break;

		case BottomMenu::certain:
			CertainSort(matrices, fout);
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

//чтение данных из файла и работа с ними
void WorkWithFile(vector<vector<int>>& matrix)
{
	vector<vector<vector<int>>> matrices;
	int actionBottom = 1;
	fstream fin;
	fstream fout;
	bool isCorrect = false;
	do {
		string name = OpenFile(WorkWithFiles::input, fin);
		isCorrect = FileInput(matrix, fin, false);
		fin.close();
	} while (!isCorrect);

	matrices.assign(mtSize, matrix);
	vector<pair<string, pair<int, int>>> results;

	while (actionBottom != back) {
		PrintMatrix(matrix, "Original", fout, TopMenu::console);

		OptionsBottom();
		actionBottom = GetInt(">>");
		
		switch (actionBottom)
		{
		case BottomMenu::all:
			results = SortWithAllMethods(matrices, fout);
			GetResults(results, matrices);
			fout.close();
			actionBottom = BottomMenu::back;
			Continue();
			break;

		case BottomMenu::certain:
			CertainSort(matrices, fout);
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
void CertainSort(vector<vector<vector<int>>>& matrices, fstream &fout)
{
	vector<pair<string, pair<int, int>>> res;
	int actionSubBottom = 1;
	set<int> used;
	while (actionSubBottom != SubBottomMenu::backToBottom && actionSubBottom != SubBottomMenu::compare) {
		SubOptionsBottom();
		actionSubBottom = GetInt(">>");
		switch (actionSubBottom)
		{
		case SubBottomMenu::bubble:
			if (used.find(actionSubBottom) != used.end()) {
				cout << "You have already used this sorting method!\n";
				break;
			}
			res.push_back(SortWithCertainMethod(std::make_shared<BubbleSort>(), matrices[1], fout));
			used.insert(actionSubBottom);
			break;

		case SubBottomMenu::selection:
			if (used.find(actionSubBottom) != used.end()) {
				cout << "You have already used this sorting method!\n";
				break;
			}
			res.push_back(SortWithCertainMethod(std::make_shared<SelectionSort>(), matrices[2], fout));
			used.insert(actionSubBottom);
			break;

		case SubBottomMenu::insertion:
			if (used.find(actionSubBottom) != used.end()) {
				cout << "You have already used this sorting method!\n";
				break;
			}
			res.push_back(SortWithCertainMethod(std::make_shared<InsertionSort>(), matrices[3], fout));
			used.insert(actionSubBottom);
			break;

		case SubBottomMenu::shell:
			if (used.find(actionSubBottom) != used.end()) {
				cout << "You have already used this sorting method!\n";
				break;
			}
			res.push_back(SortWithCertainMethod(std::make_shared<ShellSort>(), matrices[4], fout));
			used.insert(actionSubBottom);
			break;

		case SubBottomMenu::quick:
			if (used.find(actionSubBottom) != used.end()) {
				cout << "You have already used this sorting method!\n\n";
				break;
			}
			res.push_back(SortWithCertainMethod(std::make_shared<QuickSort>(), matrices[5], fout));
			used.insert(actionSubBottom);
			break;

		case SubBottomMenu::compare:
			GetResults(res, matrices);
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
	cout << "Print unsorted matrix (once) and sorted matrixes (for each method). Create a comparison table.\n";
	cout << "Matrix must be sorted in descending absoulute values in each line.\n";
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
pair<string, pair<int, int>> SortWithCertainMethod(shared_ptr<iSort> sort, vector<vector<int>>& matrix, fstream& fout) {
	//algorithm sort;
	sort->SortMatrix(matrix);
	PrintMatrix(matrix, sort->GetName() + "ed", fout, TopMenu::console);
	return make_pair(sort->GetName(), make_pair(sort->GetComparisons(), sort->GetPermutations()));
}

//использовать все сортировки
vector<pair<string, pair<int, int>>> SortWithAllMethods(vector<vector<vector<int>>>& matrices, fstream& fout) {
	vector<pair<string, pair<int, int>>> a;

	a.push_back(SortWithCertainMethod(make_shared<BubbleSort>(), matrices[1], fout));

	a.push_back(SortWithCertainMethod(make_shared<SelectionSort>(), matrices[2], fout));

	a.push_back(SortWithCertainMethod(make_shared<InsertionSort>(), matrices[3], fout));

	a.push_back(SortWithCertainMethod(make_shared<ShellSort>(), matrices[4], fout));

	a.push_back(SortWithCertainMethod(make_shared<QuickSort>(), matrices[5], fout));

	return a;
}
