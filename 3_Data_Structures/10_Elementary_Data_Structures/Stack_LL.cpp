#include <iostream>

using namespace std;

class Node{
	public:
		int value;
		Node *next;

		Node(int val, Node* ptr){
			value = val;
			next = ptr;
		}

		~Node(){
			free(next);
		}
};

class Stack_LL{

	private:
		Node *top;
		int len;

	public:
		Stack_LL(){
			top = NULL;
			len = 0;
		}

		~Stack_LL(){
			free(top);
		}
		
		int is_empty(){
			return (top == NULL);
		}

		void push(int value){
			top = new Node(value, top);
			len++;
		}

		int pop(){
			if( is_empty() )
				return -1;
			Node *temp = top;
			top = top->next;
			len--;
			return temp->value;
		}

		int length(){
			return len;
		}

		void display(){
			if( ! is_empty() ){
				Node *temp = top;
				while( temp != NULL){
					cout<<temp->value <<", ";
					temp = temp->next;
				}
			}
		}
};

int main(){

	Stack_LL S1;

	for(int i=1; i<5; i++){
		cout<<"\nPush " <<(i*10);
		S1.push(i*10);
	}

	cout<<"\n\nStack = ";
	S1.display();

	cout<<"\n\nPop, popped value = " <<S1.pop();

	cout<<"\n\nStack = ";
	S1.display();

	cout<<endl;
	return 0;
}
