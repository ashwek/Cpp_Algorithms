#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
void coinChange(int n, std::vector<int> coins) {
    std::sort(coins.begin(), coins.end());

    int minCoins = 0;
    std::map<int, int> coinsUsed;
    while ( n != 0 ) {
        for (int i = coins.size() - 1; i >= 0; i--) {
            if ( coins[i] <= n ) {
                coinsUsed[coins[i]]++;
                n -= coins[i];
                minCoins++;
                break;
            }
        }
    }

    std::cout <<"Minimum coins needed : " <<minCoins;
    std::cout <<"\nCoins used (value x count) : ";
    for (auto it : coinsUsed) {
        std::cout <<it.first <<"x" <<it.second <<", ";
    }
}

int main() {
    int n = 28;
    std::vector<int> coins = {5, 1, 10};
    coinChange(n, coins);

    std::cout <<std::endl;
    return 0;
}
