#include<iostream>
using namespace std;

void Print(int Arr[], int n){
	for(int i=0; i<n; i++) cout<<Arr[i] <<", ";
}

void Quick_Sort(int Arr[], int s, int e){

	if(e-s > 1){
		int key = e-1;
		int pivot = s-1;
		int temp;
		
		for(int i=s; i<(e-1); i++){
			if(Arr[i] < Arr[key]){
				pivot++;
				temp = Arr[pivot];
				Arr[pivot] = Arr[i];
				Arr[i] = temp;
			}
		}
		
		pivot++;
		temp = Arr[pivot];
		Arr[pivot] = Arr[key];
		Arr[key] = temp;
		
		Quick_Sort(Arr, s, pivot);
		Quick_Sort(Arr, pivot+1, e);
	}
}

int main(){

	int Arr[] = {7, 32, -66, 60, -93, 25, -66, -34, 79, -21, -24, -97, -34, 38, -73, -74, 5, 11, 64, 49}, N = 20;
	
	cout<<"\n\tOrignal Array = ";Print(Arr, N);
	Quick_Sort(Arr, 0, N);
	cout<<"\n\t Sorted Array = ";Print(Arr, N);
	cout<<endl;
	
	return 0;
}
