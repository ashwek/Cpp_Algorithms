#include <iostream>

using namespace std;

class Queue{

	private:
		int *data, f, r, size;
	public:
		Queue(int s = 10){
			data = new int[s];
			size = s;
			f = r = 0;
		}

		~Queue(){
			free(data);
		}

		int is_empty(){
			return f == r;
		}

		int is_full(){
			return r == size;
		}

		void enqueue(int value){
			if( ! is_full() ) data[r++] = value;
		}

		int dequeue(){
			if( is_empty() ) return -1;
			else return data[f++];
		}

		int front(){
			if( is_empty() ) return -1;
			else return data[f];
		}

		int rear(){
			if( is_empty() ) return -1;
			else return data[r-1];
		}

		void display(){
			if( ! is_empty() ){
				for(int i=f; i<r; i++) cout<<data[i] <<", ";
			}
		}
};

int main() {

	Queue Q1(5);

	for(int i=1; ! Q1.is_full(); i++){
		cout<<"\nEnqueue " <<(i*10);
		Q1.enqueue(i*10);
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
