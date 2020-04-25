#include <stdlib.h>
#include <iostream>

template<class T>
void multiply(T *a, T *b, T *c, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i * n + j] = 0;
            for (int k = 0; k < n; k++) {
                c[i * n + j] += (a[i * n + k] * b[k * n + j]);
            }
        }
    }
}

int main() {
    // seed random
    srand(time(NULL));

    // get random size of matrix (between 1 - 100)
    int n = random() % 100 + 1;
    int mat1[n][n], mat2[n][n], mat3[n][n];

    // random initialize mat1
    std::cout <<"Matrix 1 (" <<n <<"x" <<n <<"):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat1[i][j] = random() % 100;
            std::cout <<mat1[i][j] <<", ";
        }
        std::cout <<std::endl;
    }

    // random initialize mat2
    std::cout <<"\nMatrix 2 (" <<n <<"x" <<n <<"):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat2[i][j] = random() % 100;
            std::cout <<mat2[i][j] <<", ";
        }
        std::cout <<std::endl;
    }

    clock_t start, end;
    start = clock();

    multiply(reinterpret_cast<int *>(mat1), reinterpret_cast<int *>(mat2),
        reinterpret_cast<int *>(mat3), n);

    end = clock();

    std::cout <<"\n(Matrix 1 x Matrix 2) : Matrix 3 (" <<n <<"x" <<n <<"):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout <<mat3[i][j] <<", ";
        }
        std::cout <<std::endl;
    }

    std::cout <<"\nTwo " <<n <<"x" <<n <<" matrices multiplied in "
        <<(static_cast<float>(end - start)) / CLOCKS_PER_SEC <<" seconds\n\n";
    return 0;
}
