
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void InitArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}

void ShowArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


void FillRow(int* arr, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        arr[i] = rand() % 10;
    }
}

 //Завдання 1
int** addRow(int** arr, int& rows, int cols)
{
    int** temp = new int* [rows + 1];

    temp[0] = new int[cols];
    FillRow(temp[0], cols);

    for (int i = 0; i < rows; i++)
    {
        temp[i + 1] = arr[i];
    }

    delete[] arr;

    rows++;
    return temp;
}

 //Завдання 2
int** delRow(int** arr, int& rows, int cols)
{
    int** temp = new int* [rows - 1];

    delete[] arr[0];

    for (int i = 0; i < rows - 1; i++)
    {
        temp[i] = arr[i + 1];
    }

    delete[] arr;

    rows--;
    return temp;
}

 //Завдання 3
int** delRowByPosition(int** arr, int& rows, int cols, int pos)
{
    if (pos < 0 || pos >= rows)
    {
        cout << "Wrong position!" << endl;
        return arr;
    }

    int** temp = new int* [rows - 1];

    delete[] arr[pos];

    for (int i = 0; i < pos; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = pos; i < rows - 1; i++)
    {
        temp[i] = arr[i + 1];
    }

    delete[] arr;

    rows--;
    return temp;
}

 //Завдання 4
int** addColumn(int** arr, int rows, int& cols)
{
    int** temp = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        temp[i] = new int[cols + 1];

        temp[i][0] = rand() % 10;

        for (int j = 0; j < cols; j++)
        {
            temp[i][j + 1] = arr[i][j];
        }

        delete[] arr[i];
    }

    delete[] arr;

    cols++;
    return temp;
}

int main()
{
    srand(time(0));

    int rows = 5;
    int cols = 6;

    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    InitArray(arr, rows, cols);

    cout << "Initial array:" << endl;
    ShowArray(arr, rows, cols);

    cout << "Task 1:" << endl;
    arr = addRow(arr, rows, cols);
    ShowArray(arr, rows, cols);

    cout << "Task 2" << endl;
    arr = delRow(arr, rows, cols);
    ShowArray(arr, rows, cols);

    cout << "Task 3" << endl;
    arr = delRowByPosition(arr, rows, cols, 2);
    ShowArray(arr, rows, cols);

    cout << "Task 4" << endl;
    arr = addColumn(arr, rows, cols);
    ShowArray(arr, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
