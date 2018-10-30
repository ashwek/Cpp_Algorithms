#include<iostream>
using namespace std;

void Bubble_Sort(int Arr[], int N){

	int temp;
	bool Swap;
	for(int i=0; i<N; i++){
		Swap = false;
		for(int j=0; j<(N-i-1); j++){
			if(Arr[j] > Arr[j+1]){
				temp = Arr[j];
				Arr[j] = Arr[j+1];
				Arr[j+1] = temp;
				Swap = true;		//if swapping takes place, set swap to true
			}
		}
		if(not Swap) break;		//If swapping was not performed, the array is sorted, break from the loop
	}
}

void Print(int Arr[], int N){
	cout<<"\n\tArray : ";
	for(int i=0; i<N; i++) cout<<Arr[i] <<", ";
}

int main(){

	int Arr[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}, N=16;
	Print(Arr, N);		//Print Orignal Array
	Bubble_Sort(Arr, N);		//Bubble Sort
	Print(Arr, N);		//Print Sorted Array
	
	cout<<endl;
	return 0;
}
