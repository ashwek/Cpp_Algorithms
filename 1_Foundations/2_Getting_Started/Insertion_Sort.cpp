#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
void insertion_sort(T arr[], int n){

    T key;
    int j;
    for(int i = 1; i < n; i++){

        key = arr[i];
        j = i - 1;
        while( j >= 0 && arr[j] > key ){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

    }

}

int main(){

    // seed random
    srand(time(NULL));

    // get random size (bettwen 1 & 10000)
    int n = random() % 10000 + 1;
    int arr[n];

    // initialize random array
    cout <<"Size = " <<n <<"\n\nOrignal Array : ";
    for(int i = 0; i < n; i++){
        arr[i] = random() % 1000;
        cout <<arr[i] <<", ";
    }

    clock_t start, end;
    start = clock();

    insertion_sort(arr, n);

    end = clock();

    cout<<"\n\nSorted Array = ";
    for(int i = 0; i < n; i++)
        cout <<arr[i] <<", ";

    cout <<"\n\nSorted " <<n <<" elements in "
        <<((float)(end - start)) / CLOCKS_PER_SEC <<" seconds";

    cout<<endl;
    return 0;

}
