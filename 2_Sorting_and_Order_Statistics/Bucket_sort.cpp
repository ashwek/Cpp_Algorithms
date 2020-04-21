#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>

using namespace std;

int get_first_digit(int num, int len){

    return num / pow(10, len);
}

int max(int arr[], int n){

    int m = arr[0];
    for(int i = 1; i < n; i++){
        if( arr[i] > m )
            m = arr[i];
    }
    return m;

}

void bucket_sort(int arr[], int n){

    vector<int> bucket[10];

    int len = to_string(max(arr, n)).size();

    for(int i = 0; i < n; i++) {
        bucket[get_first_digit(arr[i], len)].push_back(arr[i]);
    }

    int k = 0;
    for(int i = 0; i < 10; i++){
        sort(bucket[i].begin(), bucket[i].end());
        for(int j = 0; j < bucket[i].size(); j++) {
            arr[k++] = bucket[i][j];
        }
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

    bucket_sort(arr, n);

    end = clock();

    cout<<"\n\nSorted Array = ";
    for(int i = 0; i < n; i++)
        cout <<arr[i] <<", ";

    cout <<"\n\nSorted " <<n <<" elements in "
        <<((float)(end - start)) / CLOCKS_PER_SEC <<" seconds";

    cout<<endl;
    return 0;

}
