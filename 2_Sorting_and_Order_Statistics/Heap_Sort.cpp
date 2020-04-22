#include <iostream>
#include <stdlib.h>

using namespace std;

#define child(i, pos)  2 * i + pos

template<class T>
void max_heapify(T arr[], int i, int len){

    int left_child = child(i, 1);		//1 to indicate Left Child
    int right_child = child(i, 2);		//2 to indicate Right Child
    int largest = i;
    T temp;

    //Find the largest element among the Root, Left child and Right child
    if(left_child < len && arr[left_child] > arr[i])
        largest = left_child;
    if(right_child < len && arr[right_child] > arr[largest])
        largest = right_child;

    //if root is not the largest, Swap root with largest and Heapify again
    if(largest != i) {
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        max_heapify(arr, largest, len);
    }

}

template<class T>
void build_max_heap(T arr[], int n) {

    for(int i = (n / 2) - 1; i >= 0; i--)
        max_heapify(arr, i, n);

}

template<class T>
void heap_sort(T arr[], int n) {

    T temp;

    build_max_heap(arr, n);		//Build Heap
    for(int i = 0; i < n; i++) {
        temp = arr[0];		//Swap Root Of Heap with the last element
        arr[0] = arr[n - i - 1];
        arr[n - i - 1] = temp;
        max_heapify(arr, 0, n - i - 1);  //Heapify again from root, reduce length to ignore the last (sorted) elements in array
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

    heap_sort(arr, n);

    end = clock();

    cout<<"\n\nSorted Array = ";
    for(int i = 0; i < n; i++)
        cout <<arr[i] <<", ";

    cout <<"\n\nSorted " <<n <<" elements in "
        <<((float)(end - start)) / CLOCKS_PER_SEC <<" seconds";

    cout<<endl;
    return 0;

}
