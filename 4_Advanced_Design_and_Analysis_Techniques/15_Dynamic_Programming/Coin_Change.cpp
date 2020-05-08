#include <iostream>
#include <vector>

void min_coins(int n, int *denomination, int amount) {
    std::vector<int> count(amount + 1, 0);
    std::vector<int> coinUsed(amount + 1, -1);

    int temp, temp2;
    for (int i = 1; i <= amount; i++) {
        temp = INT32_MAX;
        temp2 = -1;
        for (int j = 0; j < n; j++) {
            if ( denomination[j] <= i ) {
                if ( count[i - denomination[j]] + 1 < temp ) {
                    temp = count[i - denomination[j]] + 1;
                    temp2 = j;
                }
            }
        }
        count[i] = (temp != INT32_MAX) ? temp : 0;
        coinUsed[i] = temp2;
    }

    std::cout <<"Minimum Coins needed : " <<count[amount];

    std::cout <<"\nCoins Used : ";
    temp = amount;
    while ( temp > 0 ) {
        std::cout <<denomination[coinUsed[temp]] <<", ";
        temp = temp - denomination[coinUsed[temp]];
    }
}

int main() {
    int n = 3, amount = 40;
    int denomination[] = {1, 20, 25};

    min_coins(n, denomination, amount);

    std::cout <<std::endl;
    return 0;
}
