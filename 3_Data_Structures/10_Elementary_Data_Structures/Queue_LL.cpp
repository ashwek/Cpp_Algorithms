#include <iostream>

using namespace std;

class Node{
	public:
		int value;
		Node *next;

		Node(int value, Node *next){
			this->value = value;
			this->next = next;
		}
};

class Queue_LL{
	public:
		Node *f, *r;

		Queue_LL(){
			f = r = NULL;
		}

		int is_empty(){
			return f == NULL;
		}

		int enqueue(int value){
			if( r == NULL ) f = r = new Node(value, NULL);
			else{
				r->next = new Node(value, NULL);
				r = r->next;
			}
			return 0;
		}

		int dequeue(){
			if( is_empty() ) return -1;
			else{
				Node *temp = f;

				if( f == r ) f = r = NULL;
				else f = f->next;

				int val = temp->value;
				free(temp);
				return val;
			}
		}

		void display(){
			if( ! is_empty() ){
				Node *temp = f;
				while( temp != NULL){
					cout<<temp->value <<", ";
					temp = temp->next;
				}
			}
		}

		int front(){
			if( ! is_empty() ) return f->value;
			return -1;
		}

		int rear(){
			if( ! is_empty() ) return r->value;
			return -1;
		}

};

int main(){

	Queue_LL Q1;

	for(int i=1; i<5; i++){
		cout<<"\nEnqueue " <<(i*15);
		Q1.enqueue(i*15);
	}

	cout<<"\n\nQueue : ";
	Q1.display();

	cout<<"\n\nDequeue = " <<Q1.dequeue();

	cout<<"\n\nQueue : ";
	Q1.display();

	cout<<"\n\nFront = " <<Q1.front() <<" Rear = " <<Q1.rear();

	cout<<endl;
	return 0;
}
