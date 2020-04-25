#include <stdlib.h>
#include <iostream>

template<class T>
void quick_sort(T arr[], int s, int e) {
    if ( e - s <= 1 )
        return;

    int key = e - 1;
    int pivot = s - 1;
    T temp;

    for (int i = s; i < (e - 1); i++) {
        if (arr[i] < arr[key]) {
            pivot++;
            temp = arr[pivot];
            arr[pivot] = arr[i];
            arr[i] = temp;
        }
    }

    pivot++;
    temp = arr[pivot];
    arr[pivot] = arr[key];
    arr[key] = temp;

    quick_sort(arr, s, pivot);
    quick_sort(arr, pivot + 1, e);
}

int main() {
    // seed random
    srand(time(NULL));

    // get random size (bettwen 1 & 10000)
    int n = random() % 10000 + 1;
    float *arr = new float[n];

    // initialize random array
    std::cout <<"Size = " <<n <<"\n\nOrignal Array : ";
    for (int i = 0; i < n; i++) {
        arr[i] = (random() % 1000) / (random() % 1000 + 1.0);
        std::cout <<arr[i] <<", ";
    }

    clock_t start, end;
    start = clock();

    quick_sort(arr, 0, n);

    end = clock();

    std::cout <<"\n\nSorted Array = ";
    for (int i = 0; i < n; i++)
        std::cout <<arr[i] <<", ";

    std::cout <<"\n\nSorted " <<n <<" elements in "
        <<(static_cast<float>(end - start)) / CLOCKS_PER_SEC <<" seconds";

    std::cout <<std::endl;
    return 0;
}
