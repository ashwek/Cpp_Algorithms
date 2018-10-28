#include<iostream>
using namespace std;

void Max_Across(int Arr[], int s, int m, int e, int &temp_s, int &temp_e, int &temp_sum){
	
	temp_s = m-1, temp_e = m;
	int L_Sum = Arr[temp_s], R_Sum = Arr[temp_e];
	int Sum = 0;
	
	for(int i=m-1; i>=s; i--){
		Sum+=Arr[i];
		if(Sum > L_Sum){
			L_Sum = Sum;
			temp_s = i;
		}
	}
	Sum = 0;
	for(int i=m; i<e; i++){
		Sum+=Arr[i];
		if(Sum > R_Sum){
			R_Sum = Sum;
			temp_e = i;
		}
	}
	temp_sum = L_Sum + R_Sum;
}

void Max_Sub_Array(int Arr[], int s, int e, int &Left_Index, int &Right_Index, int &Sum){
	
	if(e-s == 1){
		Left_Index = s;
		Right_Index = e;
		Sum = Arr[s];
		return ;
	}
	
	int m = (e+s)/2;
	int temp_s, temp_e, temp_sum;
	
	Max_Sub_Array(Arr, s, m, Left_Index, Right_Index, Sum);
	Max_Sub_Array(Arr, m, e, temp_s, temp_e, temp_sum);
	
	if(temp_sum > Sum){
		Left_Index = temp_s;
		Right_Index = temp_e;
		Sum = temp_sum;
	}
	
	Max_Across(Arr, s, m, e, temp_s, temp_e, temp_sum);
	
	if(temp_sum > Sum){
		Left_Index = temp_s;
		Right_Index = temp_e;
		Sum = temp_sum;
	}
	
}

int main(){

	int Arr[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}, n = 16;
	
	int Left_Index, Right_Index, Sum;
	Max_Sub_Array(Arr, 0, n, Left_Index, Right_Index, Sum);
	cout<<Left_Index <<" " <<Right_Index <<" " <<Sum <<endl;
	
	return 0;
}
