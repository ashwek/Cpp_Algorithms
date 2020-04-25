#include <stdlib.h>
#include <iostream>

template<class T>
void insertion_sort(T arr[], int n) {
    T key;
    int j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while ( j >= 0 && arr[j] > key ) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertion_sort(arr, n);

    end = clock();

    std::cout <<"\n\nSorted Array = ";
    for (int i = 0; i < n; i++)
        std::cout <<arr[i] <<", ";

    std::cout <<"\n\nSorted " <<n <<" elements in "
        <<(static_cast<float>(end - start)) / CLOCKS_PER_SEC <<" seconds";

    std::cout <<std::endl;
    return 0;
}
