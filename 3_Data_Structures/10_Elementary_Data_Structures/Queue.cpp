#include <stdlib.h>
#include <iostream>

template<class DataType>
class Queue{
 private:
    DataType *data;
    int frontPtr, rearPtr, size;

 public:
    explicit Queue(int size = 10) {
        data = new DataType[size];
        this->size = size;
        frontPtr = rearPtr = 0;
    }

    ~Queue() {
        free(data);
    }

    bool is_empty() {
        return frontPtr == rearPtr;
    }

    bool is_full() {
        return rearPtr == size;
    }

    void enqueue(DataType value) {
        if ( !is_full() )
            data[rearPtr++] = value;
    }

    DataType dequeue() {
        if ( is_empty() )
            return -1;
        else
            return data[frontPtr++];
    }

    DataType front() {
        if ( is_empty() )
            return -1;
        else
            return data[frontPtr];
    }

    DataType rear() {
        if ( is_empty() )
            return -1;
        else
            return data[rearPtr - 1];
    }

    void display(){
        if ( !is_empty() ) {
            for (int i = frontPtr; i < rearPtr; i++)
                std::cout <<data[i] <<", ";
        }
    }
};


int main() {
    srand(time(NULL));

    Queue<int> Q1(5);
    int temp;

    std::cout <<"Enque random values until queue is full :";
    while ( !Q1.is_full() ) {
        temp = random() % 100;
        std::cout <<"\nEnqueue : " <<temp;
        Q1.enqueue(temp);
    }

    std::cout <<"\n\nQueue : ";
    Q1.display();

    std::cout <<"\n\nDequeue = " <<Q1.dequeue();

    std::cout <<"\n\nQueue : ";
    Q1.display();

    std::cout <<"\n\nFront = " <<Q1.front() <<" Rear = " <<Q1.rear();

    std::cout <<std::endl;
    return 0;
}
