#include <iostream>  // Подключение библиотеки для ввода-вывода
#include <vector>    // Подключение библиотеки для работы с векторами
#include <cmath>     // Подключение библиотеки для математических функций
#include <iomanip>   // Подключение библиотеки для форматирования вывода

using namespace std; // Использование стандартного пространства имен

// Функция для решения системы линейных уравнений методом Гаусса с выбором главного элемента
void gaussElimination(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size(); // Получение размера матрицы A

    // Прямой ход
    for (int i = 0; i < n; i++) { // Цикл по строкам матрицы
        // Поиск главного элемента в текущем столбце
        double maxEl = abs(A[i][i]); // Инициализация максимального элемента текущим диагональным элементом
        int maxRow = i; // Инициализация индекса строки с максимальным элементом

        for (int k = i + 1; k < n; k++) { // Цикл по строкам ниже текущей
            if (abs(A[k][i]) > maxEl) { // Если текущий элемент больше текущего максимального
                maxEl = abs(A[k][i]); // Обновление максимального элемента
                maxRow = k; // Обновление индекса строки с максимальным элементом
            }
        }

        // Поменять местами текущую строку и строку с главным элементом
        for (int k = i; k < n; k++) { // Цикл по столбцам текущей строки
            swap(A[maxRow][k], A[i][k]); // Обмен элементов в строках maxRow и i
        }
        swap(b[maxRow], b[i]); // Обмен элементов в векторе свободных членов

        // Обнуление элементов ниже главного элемента
        for (int k = i + 1; k < n; k++) { // Цикл по строкам ниже текущей
            double c = -A[k][i] / A[i][i]; // Вычисление коэффициента для обнуления элемента
            for (int j = i; j < n; j++) { // Цикл по столбцам
                if (i == j) { // Если диагональный элемент
                    A[k][j] = 0; // Обнуление элемента
                } else {
                    A[k][j] += c * A[i][j]; // Обновление элемента
                }
            }
            b[k] += c * b[i]; // Обновление элемента вектора свободных членов
        }
    }

    // Обратный ход
    vector<double> x(n); // Вектор для хранения решения
    for (int i = n - 1; i >= 0; i--) { // Цикл по строкам матрицы снизу вверх
        x[i] = b[i] / A[i][i]; // Нахождение значения переменной
        for (int k = i - 1; k >= 0; k--) { // Цикл по строкам выше текущей
            b[k] -= A[k][i] * x[i]; // Подстановка найденного значения в верхнюю строку
        }
    }

    // Вывод решения
    cout << "Solution using Gauss Elimination:" << endl; // Вывод заголовка
    for (int i = 0; i < n; i++) { // Цикл по найденным значениям переменных
        cout << "x" << i + 1 << " = " << x[i] << endl; // Вывод значения переменной
    }
}

int main() {
    // Матрица коэффициентов и вектор свободных членов
    vector<vector<double>> A = { // Инициализация матрицы коэффициентов
        {-0.77, -0.04, 0.21, -18},
        {0.25, -1.23, 0.16, -0.09},
        {-0.21, 0.16, 0.8, -0.13},
        {0.15, -1.31, 0.06, 1.12}
    };
    vector<double> b = {-1.24, 1.12, 2.56, -0.77}; // Инициализация вектора свободных членов

    gaussElimination(A, b); // Вызов функции для решения системы уравнений

    return 0; // Завершение программы
}