#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
void bubble_sort(T arr[], int n){

    T temp;
    bool swapped;

    for(int i = 0; i < n; i++) {

        swapped = false;
        for(int j = 0; j < (n - i - 1); j++) {
            if( arr[j] > arr[j + 1] ) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;

                swapped = true;
            }
        }

        if( ! swapped)
            break;

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

    bubble_sort(arr, n);

    end = clock();

    cout<<"\n\nSorted Array = ";
    for(int i = 0; i < n; i++)
        cout <<arr[i] <<", ";

    cout <<"\n\nSorted " <<n <<" elements in "
        <<((float)(end - start)) / CLOCKS_PER_SEC <<" seconds";

    cout<<endl;
    return 0;

}
