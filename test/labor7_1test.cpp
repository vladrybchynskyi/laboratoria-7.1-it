#include <gtest/gtest.h>
#include "../labor7_1.hpp"

// Функція для виділення пам'яті для двовимірного масиву
int** AllocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Функція для очищення пам'яті
void DeallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

TEST(MatrixTests, Create) {
    const int rowCount = 3;
    const int colCount = 3;
    const int Low = -21;
    const int High = 24;

    int** matrix = AllocateMatrix(rowCount, colCount);
    Create(matrix, rowCount, colCount, Low, High);

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            EXPECT_GE(matrix[i][j], Low);
            EXPECT_LE(matrix[i][j], High);
        }
    }

    DeallocateMatrix(matrix, rowCount);
}

// Тест для Change
TEST(MatrixTests, Change) {
    const int rowCount = 3;
    const int colCount = 3;

    int** matrix = AllocateMatrix(rowCount, colCount);
    
    // Встановимо значення
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
    matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

    Change(matrix, 0, 1, rowCount);

    // Перевірка на правильність зміни
    EXPECT_EQ(matrix[0][0], 2);
    EXPECT_EQ(matrix[0][1], 1);
    
    DeallocateMatrix(matrix, rowCount);
}

// Тест для Calc
TEST(MatrixTests, Calc) {
    const int rowCount = 3;
    const int colCount = 3;

    int** matrix = AllocateMatrix(rowCount, colCount);

    // Встановимо значення
    matrix[0][0] = 3; matrix[0][1] = -6; matrix[0][2] = 9;
    matrix[1][0] = 4; matrix[1][1] = 0; matrix[1][2] = 12;
    matrix[2][0] = 8; matrix[2][1] = 2; matrix[2][2] = -3;

    int S = 0;
    int k = 0;
    Calc(matrix, rowCount, colCount, S, k);

    // Перевірка на правильність обчислення
    EXPECT_EQ(S, 15); // 3 + 0 + 12
    EXPECT_EQ(k, 3);  // Кратні 3: 3, 0, 12

    DeallocateMatrix(matrix, rowCount);
}