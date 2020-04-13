#include <iostream>
#include <stdlib.h>

using namespace std;

void multiply(int *a, int *b, int *c, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i * n + j] = 0;
            for(int k = 0; k < n; k++){
                c[i * n + j] += (a[i * n + k] * b[k * n + j]);
            }
        }
    }

}

int main(){

    // seed random
    srand(time(NULL));

    // get random size of matrix
    int n = random() % 5 + 5;
    int mat1[n][n], mat2[n][n], mat3[n][n];

    // random initialize mat1
    cout <<"Matrix 1 (" <<n <<"x" <<n <<"):\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat1[i][j] = random() % 100;
            cout <<mat1[i][j] <<", ";
        }
        cout<<endl;
    }

    // random initialize mat2
    cout <<"\nMatrix 2 (" <<n <<"x" <<n <<"):\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat2[i][j] = random() % 100;
            cout <<mat2[i][j] <<", ";
        }
        cout<<endl;
    }

    clock_t start, end;
    start = clock();

    multiply((int *)mat1, (int *)mat2, (int *)mat3, n);

    end = clock();

    cout <<"\n(Matrix 1 x Matrix 2) : Matrix 3 (" <<n <<"x" <<n <<"):\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout <<mat3[i][j] <<", ";
        }
        cout<<endl;
    }

    cout <<"\nTwo " <<n <<"x" <<n <<" matrices multiplied in " <<((float)(end - start)) / CLOCKS_PER_SEC <<" seconds\n\n";
    return 0;
}
