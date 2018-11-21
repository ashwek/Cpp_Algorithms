#include<iostream>

using namespace std;

int Rod_Cut(int Cost[], int Len, int Prev[], int Ratio[]){

	if(Prev[Len] != -1) return Prev[Len];
	
	int Max = -1, temp, Max_I;
	for(int i=1; i<=Len; i++){
		Prev[Len-i] = Rod_Cut(Cost, Len-i, Prev, Ratio);
		temp = Cost[i-1] + Prev[Len-i];
		if(temp > Max){
			Max = temp;
			Max_I = i;
		}
	}
	Ratio[Len] = Max_I;
	return Max;
}

void Print(int Price[], int Ratio[]){
	int n = 10;
	for(int i=0; i<n; i++)
		cout<<(i+1)<<" => " <<Price[i+1] <<", " <<Ratio[i+1] <<endl;
}

int main(){

	int Cost[] = {1,5,8,9,10,17,17,20,24,30};
	int Prev[] = {0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int Ratio[] = {0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	
	Prev[10] = Rod_Cut(Cost, 10, Prev, Ratio); 
	Print(Prev, Ratio);
	cout<<endl;
	return 0;
}
