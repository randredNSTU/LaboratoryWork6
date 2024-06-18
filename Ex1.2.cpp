#include <iostream>
#include <vector>

void printMatrix(int N) {
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 100));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                std::cout << "000 ";
            } else {
                matrix[i][j] += (i > j) ? i - j : j - i;
                std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    int N;
    std::cout << "Введите размерность матрицы N: ";
    std::cin >> N;

    printMatrix(N);

    return 0;
}
