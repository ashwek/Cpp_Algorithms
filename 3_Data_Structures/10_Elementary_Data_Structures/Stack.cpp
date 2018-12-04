#include <iostream>
#include <vector>

using namespace std;

class Stack{

	private:
		int *data, top, size;

	public:

		Stack(int s = 10){
			data = new int[s];
			top = -1;
			size = s;
		}

		~Stack(){
			free(data);
		}

		int is_empty(){
			return (top == -1);
		}

		int is_full(){
			return (top == size-1);
		}

		int push(int value){
			if( is_full() )
				return 0;
			data[++top] = value;
			return 1;
		}

		int pop(){
			if( is_empty() )
				return -1;
			return data[top--];
		}

		void display(){
			if( ! is_empty() ){
				for(int i=top; i>=0; i--) cout<<data[i] <<", ";
			}
		}
};


int main(){

	Stack S1 = Stack(5);
	int i = 1;
	while( ! S1.is_full() ){
		cout<<"Push " <<i <<endl;
		S1.push(i);
		i += 5;
	}

	cout<<"\n\nStack : ";
	S1.display();

	cout<<"\n\nPop, popped value = " <<S1.pop();

	cout<<"\n\nStack : ";
	S1.display();
	cout<<endl;

	while( ! S1.is_empty() ){
		cout<<"Popped value " <<S1.pop() <<endl;
	}

	cout<<endl;

	return 0;
}
