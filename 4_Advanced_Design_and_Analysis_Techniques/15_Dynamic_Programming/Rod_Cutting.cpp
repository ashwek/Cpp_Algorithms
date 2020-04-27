#include <iostream>

int rod_cut(int price[], int len, int bestPrice[], int firstCut[]) {
    if ( bestPrice[len] != -1 )
        return bestPrice[len];

    int maxPrice = -1, temp, cut;

    for (int i = 1; i <= len; i++) {
        bestPrice[len - i] = rod_cut(price, len - i, bestPrice, firstCut);
        temp = price[i - 1] + bestPrice[len - i];
        if ( temp > maxPrice ) {
            maxPrice = temp;
            cut = i;
        }
    }

    firstCut[len] = cut;

    return maxPrice;
}

void print(int bestPrice[], int firstCut[]) {
    int n = 10;
    for (int i = 0; i < n; i++)
        std::cout <<(i + 1) <<" => " <<bestPrice[i + 1]
                    <<", " <<firstCut[i + 1] <<std::endl;
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int bestPrice[] = {0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int firstCut[] = {0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    bestPrice[10] = rod_cut(price, 10, bestPrice, firstCut);

    print(bestPrice, firstCut);

    std::cout <<std::endl;
    return 0;
}
