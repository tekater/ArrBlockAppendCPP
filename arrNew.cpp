#pragma warning(disable:4996) // Очень важно - без этого strcat не работает.

#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>

using namespace std;

void arrNew(int** &arr, int &row, int &col) {
    int** arr2 = new int* [row + 1];

    for (int i = 0; i < row; i++) {
        arr2[i] = arr[i];
    }

    arr2[row] = new int[col];

    for (int j = 0; j < col; j++) {
        arr2[row][j] = rand() % 10;
    }

    row++;
    delete[] arr;
    arr = arr2;

}

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    //system("color B5");
    int row = 3; int col = 5;
    int** arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    arrNew(arr, row, col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
