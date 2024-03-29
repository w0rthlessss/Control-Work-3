#include "ModuleTests.h"
#include <sstream>

//�������� �� ������������ ������
template<typename T = vector<vector<int>>>
bool Check(T a, T b, int h, int w, string msg) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] != b[i][j]) {
                cout << msg;
                return false;
            }
        }
    }
    return true;
}

const string fileName = "test_info.txt";

bool Test1()
{
    //�������� ����� �������� ������� � �����
    //cout << "\tTEST#1\n\tTesting file input...\n\n";

    fstream fin;
    const int h = 3, w = 3;
    
    fin.open(fileName, ios::in);

    if (!fin) {
        cout << "Test#1: FAILURE!\nError opening file!\n\n";
        return false;
    }

    vector<vector<int>> checkMatrix = { {-21, 79, -80}, {89, -75, -72}, {69, 10, 48} };
    vector<vector<int>> fileMatrix;

    if (!FileInput(fileMatrix, fin, true)) {
        cout << "Test#1: FAILURE!\nValues from inside the program and values from the test file do not match!\n\n";
        return false;
    }

    if (fileMatrix.size() != h || fileMatrix[0].size() != w) {
        cout << "Test#1: FAILURE!\nMatrix sizes do not match!\n\n";
        return false;
    }
    fin.close();
    return true;
}

bool Test2()
{
    //�������� ����� ������� � �����
    //cout << "\tTEST#2\n\tTesting file input...\n\n";

    fstream fin;
    const int h = 3, w = 3;
    fin.open(fileName, ios::in);

    if (!fin) {
        cout << "Test#2: FAILURE!\nError opening file!\n\n";
        return false;
    }

    vector<vector<int>> checkMatrix = { {-21, 79, -80}, {89, -75, -72}, {69, 10, 48} };
    vector<vector<int>> fileMatrix;

    if (!FileInput(fileMatrix, fin, true)) {
        cout << "Test#2: FAILURE!\nValues from inside the program and values from the test file do not match!\n\n";
        return false;
    }

    return Check(checkMatrix, fileMatrix, h, w, "Test#2: FAILURE!\nValues from inside the program and values from the test file do not match!\n\n");
}

bool Test3()
{
    //���� ������������ ����������
    //cout << "\tTEST#3\n\tTesting sorting methods...\n\n";
    const int h = 3, w = 3;
    vector<vector<int>> originalMatrix = { {-21, 79, -80}, {89, -75, -72}, {69, 10, 48} };
    vector<vector<int>> sortedMatrix = { {-80, 79, -21}, {89, -75, -72}, {69, 48, 10} };
    vector<vector<int>> testMatrix = originalMatrix;

    BubbleSort tmp;
    tmp.SortMatrix(testMatrix);

    return Check(sortedMatrix, testMatrix, h, w, "Test#3: FAILURE!\nTest matrix and sorted matrix do not match!\n\n");
}

bool Test4()
{
    //���� ������������ ����������� ��������������� �������
    //cout<< "\tTEST#4\n\tTesting correctness of checking if the matrix is sorted function...\n\n";
    vector<vector<int>> sortedMatrix = { {-80, 79, -21}, {89, -75, -72}, {69, 48, 10} };

    ShellSort tmp;
    tmp.SortMatrix(sortedMatrix);
    if (tmp.GetPermutations() != 0) {
        cout << "Test#4: FAILURE!\n Matrix values permutated while it is already sorted!\n\n";
        return false;
    }
    return true;
}

bool Test5()
{
    //���� �� ������������ ����� � �������
    //cout << "\tTEST#5\n\tTesting console input...\n\n";
    {
        istringstream test("576\n\n");
        streambuf* cinbuf = cin.rdbuf(test.rdbuf());

        bool res = (GetInt("") == 576);

        if (!res) {
            cout << "Test#5: FAILURE!\nIncorrect console input!\n\n";
            return false;
        }

        cin.rdbuf(cinbuf);
    }
    return true;
}

void LaunchAllTests()
{
    fstream fout;
    fout.open(fileName, ios::out);
    fout << "3 3" << endl;
    fout << "-21 79 -80\n89 -75 -72\n69 10 48";
    fout.close();

    bool tests[5] = { Test1(), Test2(), Test3(), Test4(), Test5() };

    if (tests[0] && tests[1] && tests[2] && tests[3] && tests[4]) cout << "\nAll tests SUCCEDED!\n\n";
}
