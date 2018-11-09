#include<iostream>
using namespace std;


class Stack{

	public:
		Stack(int s = 10){
			data = new int[s];
			top = -1;
			size = s;
		}
		int is_empty(){
			return (top == -1);
		}
		int is_full(){
			return (top == size-1);
		}
		void push(){
			if(is_full())
				cout<<"\n\tSatck Overflow";
			else{
				cout<<"\tEnter Value = ";
				cin>>data[++top];
			}
		}
		void pop(){
			if(is_empty())
				cout<<"\n\tSatck Underflow";
			else
				cout<<"\n\tDeleted Value = " <<data[top--];
		}
		void display(){
			if(is_empty())
				cout<<"\n\tSatck is empty";
			else
				cout<<"\n\tStack : ";
				for(int i=top; i>=0; i--) cout<<data[i] <<", ";
		}
	private:
		int *data, top, size;
};


int main(){

	Stack one = Stack(3);
	cout<<"\n\tPush 4 Elements : \n";
	one.push();
	one.push();
	one.push();
	one.push();
	one.display();
	
	cout<<"\n\n\tPop 1 Elements : ";
	one.pop();
	one.display();
	
	cout<<"\n\n\tPop 3 Elements : ";
	one.pop();
	one.pop();
	one.pop();
	
	cout<<endl;
	
	return 0;
}
