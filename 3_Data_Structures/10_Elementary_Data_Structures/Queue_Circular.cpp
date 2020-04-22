#include <iostream>
#include <stdlib.h>

using namespace std;

template<class DataType>
class Queue_Circular {
private:
    DataType *data;
    int frontPtr, rearPtr, size;

public:

    Queue_Circular(int size = 10) {
        data = new DataType[size + 1];
        frontPtr = rearPtr = 0;
        this->size = size + 1;
    }

    ~Queue_Circular(){
        free(data);
    }

    bool is_empty(){
        return frontPtr == rearPtr;
    }

    bool is_full(){
        return (rearPtr + 1) % size == frontPtr;
    }

    void enqueue(DataType value){
        data[rearPtr] = value;
        rearPtr = (rearPtr + 1) % size;
    }

    void dequeue() {
        frontPtr = (frontPtr + 1) % size;
    }

    DataType front(){
        if( is_empty() )
            return -1;
        return data[frontPtr];
    }

    DataType rear() {
        if( is_empty() )
            return -1;
        return data[(rearPtr + size - 1) % size];
    }

    void display(){
        if( ! is_empty() ){
            for(int i = frontPtr; i != rearPtr; i = (i + 1) % size)
                cout <<data[i] <<", ";
        }
    }

};


int main(){

    srand(time(NULL));

    Queue_Circular<int> Q1(5);
    int temp;
    cout <<"\nEnqueue random values until queue is full :";
    while( ! Q1.is_full() ) {
        temp = random() % 100 + 1;
        cout<<"\nEnqueue : " <<temp;
        Q1.enqueue(temp);
    }

    cout<<"\n\nQueue : ";
    Q1.display();

    cout<<"\n\nDequeue = " <<Q1.front();
    Q1.dequeue();

    temp = random() % 100 + 1;
    cout<<"\n\nEnqueue = " <<temp;
    Q1.enqueue(temp);

    cout<<"\n\nQueue : ";
    Q1.display();

    cout<<"\n\nFront = " <<Q1.front() <<" Rear = " <<Q1.rear();

    cout<<endl;
    return 0;
}
