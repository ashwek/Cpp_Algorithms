#include <iostream>
#include <stdlib.h>

using namespace std;

void assign(int src[], int s, int e, int dst[]) {
    for(int i = s; i < e; i++)
        dst[i - s] = src[i];
}

int max(int a, int b){
    return (a > b) ? a : b;
}

void merge(int arr[], int s, int m, int e) {

    int leftSize = m - s + 1;
    int rightSize = e - m + 1;

    int *leftArr = new int[leftSize];
    assign(arr, s, m, leftArr);

    int *rightArr = new int[rightSize];
    assign(arr, m, e, rightArr);

    leftArr[leftSize - 1] = rightArr[rightSize - 1] =
                    max(leftArr[leftSize - 2], rightArr[rightSize - 2]) + 1;

    leftSize = rightSize = 0;
    for(int i = s; i < e; i++) {

        if( leftArr[leftSize] < rightArr[rightSize] )
            arr[i] = leftArr[leftSize++];
        else
            arr[i] = rightArr[rightSize++];

    }

}

void merge_sort(int arr[], int s, int e){

    if( e - s > 1 ) {
        int m = (e + s) / 2;
        merge_sort(arr, s, m);
        merge_sort(arr, m, e);
        merge(arr, s, m, e);
    }

}

int main(){

    // seed random generator
    srandom(time(NULL));

    // get random size (between 100 - 109)
    int n = random() % 10 + 100;
    int arr[n];

    // initialize random array
    cout <<"Size : " <<n <<"\n\nOrignal Array : ";
    for(int i = 0; i < n; i++){
        arr[i] = random() % 1000;
        cout <<arr[i] <<", ";
    }

    clock_t start, end;
    start = clock();

    merge_sort(arr, 0, n);

    end = clock();

    cout<<"\n\nSorted Array : ";
    for(int i = 0; i < n; i++)
        cout<<arr[i] <<", ";

    cout <<"\n\nSiorted " <<n <<" elements in "
        <<((float)(end - start)) / CLOCKS_PER_SEC <<" second";

    cout<<endl;
    return 0;

}
