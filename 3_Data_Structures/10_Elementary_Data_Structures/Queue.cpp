#include <iostream>
#include <stdlib.h>

using namespace std;

template<class DataType>
class Queue{
private:
    DataType *data;
    int frontPtr, rearPtr, size;

public:

    Queue(int size = 10){
        data = new DataType[size];
        this->size = size;
        frontPtr = rearPtr = 0;
    }

    ~Queue(){
        free(data);
    }

    bool is_empty(){
        return frontPtr == rearPtr;
    }

    bool is_full(){
        return rearPtr == size;
    }

    void enqueue(DataType value){
        if( ! is_full() )
            data[rearPtr++] = value;
    }

    DataType dequeue(){
        if( is_empty() )
            return -1;
        else
            return data[frontPtr++];
    }

    DataType front(){
        if( is_empty() )
            return -1;
        else
            return data[frontPtr];
    }

    DataType rear(){
        if( is_empty() )
            return -1;
        else
            return data[rearPtr - 1];
    }

    void display(){
        if( ! is_empty() ){
            for(int i = frontPtr; i < rearPtr; i++)
                cout <<data[i] <<", ";
        }
    }

};


int main() {

    srand(time(NULL));

    Queue<int> Q1(5);
    int temp;
    cout <<"Enque random values until queue is full :";
    while( ! Q1.is_full() ){
        temp = random() % 100;
        cout <<"\nEnqueue : " <<temp;
        Q1.enqueue(temp);
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
