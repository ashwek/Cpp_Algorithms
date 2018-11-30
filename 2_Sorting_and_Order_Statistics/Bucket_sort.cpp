#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Print(int Arr[], int n){
	for(int i=0; i<n; i++) cout<<Arr[i] <<", ";
}

int get_digit(int num, int digit){
	int temp;
	while(num > 0){
		temp = num%10;
		num /= 10;
		digit--;
	}
	return (digit == 0) ? temp : 0;
}

void bucket_sort(int Arr[], int n){

	vector<int> bucket[10];

	for(int i=0; i<n; i++){
		bucket[get_digit(Arr[i], 3)].push_back(Arr[i]);
	}

	int k = 0;
	for(int i=0; i<10; i++){
		sort(bucket[i].begin(), bucket[i].end());
		for(int j=0; j<bucket[i].size(); j++){
			Arr[k++] = bucket[i][j];
		}
	}
}

int main(){

	int Arr[] = {352, 154, 242, 427, 174, 323, 66, 90, 289, 4}, n = 10;

	cout<<"Orignal Array = ";
	Print(Arr, n);

	bucket_sort(Arr, n);

	cout<<"\n Sorted Array = ";
	Print(Arr, n);

	cout<<endl;
	return 0;
}
