#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>
#include <climits>

// Функция для проверки простого числа
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Задача 1: Поиск наиболее часто встречающегося простого числа в случайной матрице
void task1() {
    srand(time(0));

    int M, N;
    std::cout << "Введите размеры матрицы M и N: ";
    std::cin >> M >> N;

    std::vector<std::vector<int>> matrix(M, std::vector<int>(N));
    std::map<int, int> primeCount;

    // Заполнение матрицы случайными числами и подсчет простых чисел
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 51;
            if (isPrime(matrix[i][j])) {
                primeCount[matrix[i][j]]++;
            }
        }
    }

    // Поиск простого числа, которое встречается наибольшее количество раз
    int mostFrequentPrime = -1;
    int maxCount = 0;
    for (const auto& pair : primeCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentPrime = pair.first;
        }
    }

    // Вывод матрицы и результата
    std::cout << "Матрица:\n";
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    if (mostFrequentPrime != -1) {
        std::cout << "Простое число, которое встречается наибольшее количество раз: " << mostFrequentPrime << "\n";
        std::cout << "Количество вхождений: " << maxCount << "\n";
    } else {
        std::cout << "Простых чисел в матрице нет.\n";
    }
}

// Задача 2: Инициализация и вывод матрицы с определенными правилами
void task2() {
    int N;
    std::cout << "Enter the size of the matrix: ";
    std::cin >> N;

    int** matrix = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                matrix[i][j] = 0;
            } else if (j == 0 || j == N - 1) {
                matrix[i][j] = 100;
            } else if (i == 0) {
                matrix[i][j] = 100 + N - 1 - j;
            } else if (i == N - 1) {
                matrix[i][j] = 100 + j;
            } else if (i < j) {
                matrix[i][j] = 100 + j - i;
            } else {
                matrix[i][j] = 100 + i - j;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == 0) {
                std::cout << "000 ";
            } else {
                std::cout << std::setw(3) << std::setfill('0') << matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Задача 3: Поиск элементов, которые одновременно минимальны в строке и максимальны в столбце
void task3() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int M, N;
    std::cout << "Введите размеры матрицы M и N: ";
    std::cin >> M >> N;

    std::vector<std::vector<int>> matrix(M, std::vector<int>(N));

    // Заполнение матрицы случайными числами
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 100; // Случайные числа от 0 до 99
        }
    }

    std::vector<int> minInRow(M, INT_MAX);
    std::vector<int> maxInCol(N, INT_MIN);

    // Поиск минимальных элементов в строках и максимальных в столбцах
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] < minInRow[i]) {
                minInRow[i] = matrix[i][j];
            }
            if (matrix[i][j] > maxInCol[j]) {
                maxInCol[j] = matrix[i][j];
            }
        }
    }

    std::cout << "Матрица:\n";
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Элементы, которые одновременно являются минимальными в своей строке и максимальными в своем столбце:\n";
    bool found = false;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == minInRow[i] && matrix[i][j] == maxInCol[j]) {
                std::cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << "\n";
                found = true;
            }
        }
    }

    if (!found) {
        std::cout << "Таких элементов нет.\n";
    }
}
int main() {
    int choice;
    do {
        std::cout << "Выберите задачу:\n";
        std::cout << "1. Поиск наиболее часто встречающегося простого числа в случайной матрице\n";
        std::cout << "2. Инициализация и вывод матрицы с определенными правилами\n";
        std::cout << "3. Поиск элементов, которые одновременно минимальны в строке и максимальны в столбце\n";
        std::cout << "0. Выход\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 0:
                std::cout << "Выход...\n";
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}