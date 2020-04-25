#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int max(int arr[], int n) {
    int m = arr[0];
    for (int i = 1; i < n; i++)
        m = (arr[i] > m) ? arr[i] : m;

    return m;
}

int get_digit(int num, int digits) {
    return static_cast<int>(num / pow(10, digits - 1)) % 10;
}

void radix_sort(int arr[], int n) {
    int max_digits = std::to_string(max(arr, n)).size();
    int l;
    std::vector<int> Bkt[10];

    for (int i = 1; i <= max_digits; i++) {
        for (int j = 0; j < n; j++)
            Bkt[get_digit(arr[j], i)].push_back(arr[j]);

    l = 0;
    for (int k = 0; k < 10; k++) {
        for (int j = 0; j < Bkt[k].size(); j++)
            arr[l++] = Bkt[k][j];
        Bkt[k].erase(Bkt[k].begin(), Bkt[k].end());
        }
    }
}


int main() {
    // seed random
    srand(time(NULL));

    // get random size (bettwen 1 & 10000)
    int n = random() % 10000 + 1;
    int *arr = new int[n];

    // initialize random array
    std::cout <<"Size = " <<n <<"\n\nOrignal Array : ";
    for (int i = 0; i < n; i++) {
        arr[i] = random() % 1000;
        std::cout <<arr[i] <<", ";
    }

    clock_t start, end;
    start = clock();

    radix_sort(arr, n);

    end = clock();

    std::cout <<"\n\nSorted Array = ";
    for (int i = 0; i < n; i++)
        std::cout <<arr[i] <<", ";

    std::cout <<"\n\nSorted " <<n <<" elements in "
        <<(static_cast<float>(end - start)) / CLOCKS_PER_SEC <<" seconds";

    std::cout <<std::endl;
    return 0;
}
