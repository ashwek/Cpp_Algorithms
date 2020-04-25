#include<iostream>

void max_min(int arr[], int n, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];

    for (int i = 1; i < n; i++) {
        if ( arr[i] > *max )
            *max = arr[i];
        if ( arr[i] < *min )
            *min = arr[i];
    }
}

int* counting_sort(int arr[], int n) {
    int max, min;
    max_min(arr, n, &max, &min);

    int *sorted_arr = new int[n];

    int *count = new int[max - min + 1];

    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;

    for (int i = 1; i < (max - min + 1); i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        sorted_arr[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    return sorted_arr;
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

    int *sorted_arr = counting_sort(arr, n);

    end = clock();

    std::cout <<"\n\nSorted Array = ";
    for (int i = 0; i < n; i++)
        std::cout <<sorted_arr[i] <<", ";

    std::cout <<"\n\nSorted " <<n <<" elements in "
        <<(static_cast<float>(end - start)) / CLOCKS_PER_SEC <<" seconds";

    std::cout <<std::endl;
    return 0;
}
