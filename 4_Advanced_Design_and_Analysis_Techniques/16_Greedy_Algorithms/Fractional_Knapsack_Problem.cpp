#include <iostream>
#include <vector>
#include <algorithm>

bool comp(std::vector<int> a, std::vector<int> b) {
    return (static_cast<float>(a[1]) / a[0]) >
            (static_cast<float>(b[1]) / b[0]);
}


void knapsack(int W, std::vector<std::vector<int>> weightValue) {
    std::sort(weightValue.begin(), weightValue.end(), comp);

    int i = 0;
    int value = 0;
    int temp;
    std::cout <<"Elements used : weight_used(value) :\n";
    while ( i < weightValue.size() && W > 0 ) {
        if ( W >= weightValue[i][0] ) {
            W -= weightValue[i][0];
            value += weightValue[i][1];
            std::cout <<weightValue[i][0] <<"(" <<weightValue[i][1] <<"), ";
        } else {
            temp = W * (static_cast<float>(weightValue[i][1]) /
                                            weightValue[i][0]);
            value += temp;
            std::cout <<W <<"/" <<weightValue[i][0] <<"(" <<temp <<"), ";
            W = 0;
        }
        i++;
    }

    std::cout <<"\nMax value = " <<value;
}


int main() {
    std::vector<std::vector<int>> weightValue =
                                        {{10, 60}, {20, 100}, {30, 120}};
    int W = 50;

    knapsack(W, weightValue);

    std::cout <<std::endl;
    return 0;
}
