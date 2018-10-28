#include<iostream>
using namespace std;

void Assign(int Src[], int s, int e, int Dst[]){
	for(int i=s; i<e; i++) Dst[i-s] = Src[i];
}

void Merge(int Arr[], int s, int m, int e){
	
	int L = m-s+1, R = e-m+1;
	
	int *Left = new int[L];
	Assign(Arr, s, m, Left);
	
	int *Right = new int[R];
	Assign(Arr, m, e, Right);
	
	Left[L-1] = Right[R-1] = (Left[L-2]>Right[R-2]) ? Left[L-2]+1 : Right[R-2]+1 ;
	
	L = R = 0;
	for(int i=s; i<e; i++){
		if(Left[L] < Right[R]) Arr[i] = Left[L++];
		else Arr[i] = Right[R++];
	}
}

void Merge_Sort(int Arr[], int s, int e){
	
	if(e-s > 1){
		int m = (e+s)/2;
		Merge_Sort(Arr, s, m);
		Merge_Sort(Arr, m, e);
		Merge(Arr, s, m, e);
	}
}

int main(){

	int A[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}, N = 16;
	Merge_Sort(A, 0, N);
	cout<<"\nArray = ";
	for(int i=0; i<N; i++) cout<<A[i] <<", ";
	cout<<endl;
	return 0;
}
