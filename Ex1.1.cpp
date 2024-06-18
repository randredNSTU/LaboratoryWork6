#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>

// Функция для проверки простого числа
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
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

    return 0;
}
