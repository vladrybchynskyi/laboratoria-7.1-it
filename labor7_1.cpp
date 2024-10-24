#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** p, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** p, const int rowCount, const int colCount);
void Sort(int** p, const int rowCount, const int colCount);
void Change(int** p, const int col1, const int col2, const int rowCount);
void Calc(int** p, const int rowCount, const int colCount, int& S, int& k);

int main() {
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    int Low = -21;
    int High = 24;

    int rowCount = 9;
    int colCount = 6;

    int** p = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        p[i] = new int[colCount];
    }

    Create(p, rowCount, colCount, Low, High);
    Print(p, rowCount, colCount);

    Sort(p, rowCount, colCount);
    Print(p, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(p, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    Print(p, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] p[i];
    delete[] p;

    return 0;
}

void Create(int** p, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            p[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** p, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << p[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** p, const int rowCount, const int colCount) {
    for (int i0 = 0; i0 < colCount - 1; i0++) {
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++) {
            if ((p[0][i1] < p[0][i1 + 1])  // Сортування за першим рядком за спаданням
                || (p[0][i1] == p[0][i1 + 1] && p[1][i1] < p[1][i1 + 1])  // Якщо перший рядок однаковий, сортуємо за другим
                || (p[0][i1] == p[0][i1 + 1] && p[1][i1] == p[1][i1 + 1] && p[2][i1] > p[2][i1 + 1]))  // Якщо і перший, і другий однакові, сортуємо за третім (зростання)
            {
                Change(p, i1, i1 + 1, rowCount);
            }
        }
    }
}


void Change(int** p, const int col1, const int col2, const int rowCount) {
    int tmp;
    for (int i = 0; i < rowCount; i++) {
        tmp = p[i][col1];
        p[i][col1] = p[i][col2];
        p[i][col2] = tmp;
    }
}

void Calc(int** p, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (p[i][j] % 3 == 0 && p[i][j] >= 0) {  // Кратні 3, крім від'ємних
                S += p[i][j];
                k++;
                p[i][j] = 0;
            }
}