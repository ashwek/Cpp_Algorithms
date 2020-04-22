#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cmath>

using namespace std;

int max(int arr[], int n){

    int m = arr[0];
    for(int i = 1; i < n; i++)
        m = (arr[i] > m) ? arr[i] : m;

    return m;

}

int get_digit(int num, int digits) {
    return int(num / pow(10, digits - 1)) % 10;
}

void radix_sort(int arr[], int n){

    int max_digits = to_string(max(arr, n)).size();
    int l;
    vector<int> Bkt[10];

    for(int i = 1; i <= max_digits; i++) {
        for(int j = 0; j < n; j++)
            Bkt[get_digit(arr[j], i)].push_back(arr[j]);

    l = 0;
    for(int k = 0; k < 10; k++) {
        for(int j = 0; j < Bkt[k].size(); j++)
            arr[l++] = Bkt[k][j];
        Bkt[k].erase(Bkt[k].begin(), Bkt[k].end());
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

    radix_sort(arr, n);

    end = clock();

    cout<<"\n\nSorted Array = ";
    for(int i = 0; i < n; i++)
        cout <<arr[i] <<", ";

    cout <<"\n\nSorted " <<n <<" elements in "
        <<((float)(end - start)) / CLOCKS_PER_SEC <<" seconds";

    cout<<endl;
    return 0;

}
