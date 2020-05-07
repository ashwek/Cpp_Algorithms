#include <iostream>
#include <cstring>
#include <vector>

int knapsack(int n, int W, int *weights, int *values) {
    std::vector<std::vector<int>> count(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if ( weights[i - 1] > j ) {
                count[i][j] = count[i - 1][j];
            } else {
                count[i][j] = std::max(count[i - 1][j],
                        count[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    return count[n][W];
}

int main() {
    int n = 3, W = 50;
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};

    std::cout <<knapsack(n, W, weights, values);

    std::cout <<std::endl;
    return 0;
}
