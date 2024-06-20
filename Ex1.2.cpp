#include <iostream>
#include <iomanip>

void initializeMatrix(int** matrix, int N) {
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
}

void printMatrix(int** matrix, int N) {
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
}

int main() {
    int N;
    std::cout << "Enter the size of the matrix: ";
    std::cin >> N;

    int** matrix = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[N];
    }

    initializeMatrix(matrix, N);
    printMatrix(matrix, N);

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
