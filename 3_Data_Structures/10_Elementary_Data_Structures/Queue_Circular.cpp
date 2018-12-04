#include <iostream>

using namespace std;

class Queue_Circular{

	private:
		int *data, f, r, size;
	public:
		Queue_Circular(int s = 10){
			data = new int[s+1];
			f = r = 0;
			size = s+1;
		}

		~Queue_Circular(){
			free(data);
		}

		int is_empty(){
			return f == r;
		}

		int is_full(){
			return (r+1)%size == f;
		}

		int enqueue(int value){
			if( is_full() ) return -1;
			data[r] = value;
			r = (r+1)%size;
		}

		int dequeue(){
			if( is_empty() ) return -1;
			int temp = data[f];
			f = (f+1)%size;
			return temp;
		}

		int front(){
			if( is_empty() ) return -1;
			return data[f];
		}

		int rear(){
			if( is_empty() ) return -1;
			return data[(r+size-1)%size];
		}

		void display(){
			if( ! is_empty() ){
				for(int i=f; i!=r; i = (i+1)%size) cout<<data[i] <<", ";
			}
		}
};


int main(){

	Queue_Circular Q1(5);

	for(int i=1; ! Q1.is_full(); i++){
		cout<<"\nEnqueue " <<(i*10);
		Q1.enqueue(i*10);
	}

	cout<<"\n\nQueue : ";
	Q1.display();

	cout<<"\n\nDequeue = " <<Q1.dequeue();

	cout<<"\nEnqueue " <<(100);
	Q1.enqueue(100);

	cout<<"\n\nQueue : ";
	Q1.display();

	cout<<"\n\nFront = " <<Q1.front() <<" Rear = " <<Q1.rear();

	cout<<endl;
	return 0;
}
