#include <iostream>
#include <cstring>
#include <vector>

void knapsack(int n, int W, int *weights, int *values) {
    std::vector<std::vector<int>> count(n + 1, std::vector<int>(W + 1, 0));

    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= W; j++) {
            if ( weights[i - 1] > j ) {
                count[i][j] = count[i - 1][j];
            } else {
                count[i][j] = std::max(count[i - 1][j],
                        count[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    std::cout <<"Max Value : " <<count[n][W];

    std::vector<bool> selected(n, false);
    i = n, j = W;
    while ( i > 0 && j > 0 ) {
        if ( count[i][j] == count[i - 1][j] ) {
            i--;
        } else {
            selected[i - 1] = true;
            j = j - weights[i - 1];
        }
    }

    std::cout <<"\nSelected Weight(Value) : ";
    for (i = 0; i < n; i++) {
        if ( selected[i] )
            std::cout <<weights[i] <<"(" <<values[i] <<"), ";
    }
}

int main() {
    int n = 3, W = 50;
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};

    knapsack(n, W, weights, values);

    std::cout <<std::endl;
    return 0;
}
