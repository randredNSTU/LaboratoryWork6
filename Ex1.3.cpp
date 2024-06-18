#include <iostream>
#include <vector>
#include <climits> // Для INT_MAX и INT_MIN

int main() {
    int M, N;
    std::cout << "Введите размеры матрицы M и N: ";
    std::cin >> M >> N;

    std::vector<std::vector<int>> matrix(M, std::vector<int>(N));

    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
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

    return 0;
}
