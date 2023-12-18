#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>

#define ROWS 3
#define COLS 5

// Функція для виведення матриці на екран
void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr"); //Українізація
    int s[ROWS][COLS];

    // Заповнення матриці s рандомними числами від -10 до 10
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            s[i][j] = rand() % 21 - 10;
        }
    }

    printf("Матриця s:\n");
    printMatrix(s);

    int d[COLS];

    // Ініціалізація вектора d найменшими можливими значеннями
    for (int i = 0; i < COLS; i++) {
        d[i] = -11; // Враховуючи, що числа в матриці від -10 до 10
    }

    // Знаходження найбільших негативних елементів відповідних стовпчиків
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            if (s[i][j] < 0 && s[i][j] > d[j]) {  // Перевірка на найбільше негативне значення в стовпці
                d[j] = s[i][j];
            }
        }
        // Якщо стовпець має тільки невід'ємні значення, ініціалізуємо його як 0
        if (d[j] == -11) {
            d[j] = 0;
        }
    }

    printf("\nВектор d:\n");
    for (int i = 0; i < COLS; i++) {
        printf("%3d ", d[i]);
    }

    return 0;
}