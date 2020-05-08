#include <iostream>
#include <cstring>
#include <vector>
#include <map>

void knapsack(int n, int W, int *weights, int *values) {
    std::vector<int> count(W + 1, 0);

    int i, j;
    for (i = 1; i <= W; i++) {
        for (j = 0; j < n; j++) {
            if ( weights[j] <= i ) {
                count[i] = std::max(count[i],
                    count[i - weights[j]] + values[j]);
            }
        }
    }

    std::cout <<"Max Value : " <<count[W];
}

int main() {
    int n = 3, W = 100;
    int weights[] = {5, 10, 15};
    int values[] = {10, 30, 20};

    knapsack(n, W, weights, values);

    std::cout <<std::endl;
    return 0;
}
