#include "UserInterface.h"
#include "ModuleTests.h"
int main() {
	vector<vector<int>> matrix;
	int actionTop = 1;
	Task();
	Fio();
	while (actionTop != TopMenu::quit) {
		OptionsTop();
		actionTop = GetInt(">>");
		InputOption(actionTop);
		switch (actionTop)
		{
		case TopMenu::console:
			WorkWithConsole(matrix, false);
			break;
		case TopMenu::random:
			WorkWithConsole(matrix, true);
			break;
		case TopMenu::file:
			WorkWithFile(matrix);
			break;
		case TopMenu::module:
			LaunchAllTests();
			break;
		case TopMenu::quit:
			cout << "Program finished its work!\n";
			exit(EXIT_SUCCESS);
		default:
			IncorrectOption();
			break;
		}
	}
}