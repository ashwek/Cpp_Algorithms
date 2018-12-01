#include <iostream>
#include <vector>

using namespace std;

void Print(int Arr[], int n){
	for(int i=0; i<n; i++) cout<<Arr[i] <<", ";
}

int max(int Arr[], int n){
	int m=Arr[0];
	for(int i=1; i<n; i++)
		m = (Arr[i]>m) ? Arr[i] : m;
	return m;
}

int get_digit(int num, int digits=-1){
	int count = 0, temp;

	while(num > 0){
		count++;
		temp = num%10;
		num /= 10;
		if(digits != -1) digits--;
		if(digits == 0) break;
	}

	return (digits == -1) ? count : (digits == 0) ? temp : 0 ;
}

void radix_sort(int Arr[], int n){
	int max_digits = get_digit(max(Arr, n));
	int l;
	vector<int> Bkt[10];

	for(int i=1; i<=max_digits; i++){
		for(int j=0; j<n; j++)
			Bkt[get_digit(Arr[j], i)].push_back(Arr[j]);

		l = 0;
		for(int k=0; k<10; k++){
			for(int j=0; j<Bkt[k].size(); j++)
				Arr[l++] = Bkt[k][j];
			Bkt[k].erase(Bkt[k].begin(), Bkt[k].end());
		}
	}
}

int main(){

	int Arr[] = {176, 8, 78, 75, 3, 7, 129, 168, 43, 100}, n = 10;

	cout<<"Orignal Array = ";
	Print(Arr, n);

	radix_sort(Arr, n);

	cout<<"\n Sorted Array = ";
	Print(Arr, n);

	cout<<endl;
	return 0;
}
