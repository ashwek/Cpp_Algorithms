#include <stdlib.h>
#include <iostream>

template<class DataType>
class Queue_Circular {
 private:
    DataType *data;
    int frontPtr, rearPtr, size;

 public:
    explicit Queue_Circular(int size = 10) {
        data = new DataType[size + 1];
        frontPtr = rearPtr = 0;
        this->size = size + 1;
    }

    ~Queue_Circular() {
        free(data);
    }

    bool is_empty() {
        return frontPtr == rearPtr;
    }

    bool is_full() {
        return (rearPtr + 1) % size == frontPtr;
    }

    void enqueue(DataType value) {
        data[rearPtr] = value;
        rearPtr = (rearPtr + 1) % size;
    }

    void dequeue() {
        frontPtr = (frontPtr + 1) % size;
    }

    DataType front() {
        if ( is_empty() )
            return -1;
        return data[frontPtr];
    }

    DataType rear() {
        if ( is_empty() )
            return -1;
        return data[(rearPtr + size - 1) % size];
    }

    void display(){
        if ( !is_empty() ) {
            for (int i = frontPtr; i != rearPtr; i = (i + 1) % size)
                std::cout <<data[i] <<", ";
        }
    }
};


int main() {
    srand(time(NULL));

    Queue_Circular<int> Q1(5);
    int temp;

    std::cout <<"\nEnqueue random values until queue is full :";
    while ( !Q1.is_full() ) {
        temp = random() % 100 + 1;
        std::cout <<"\nEnqueue : " <<temp;
        Q1.enqueue(temp);
    }

    std::cout <<"\n\nQueue : ";
    Q1.display();

    std::cout <<"\n\nDequeue = " <<Q1.front();
    Q1.dequeue();

    temp = random() % 100 + 1;
    std::cout <<"\n\nEnqueue = " <<temp;
    Q1.enqueue(temp);

    std::cout <<"\n\nQueue : ";
    Q1.display();

    std::cout <<"\n\nFront = " <<Q1.front() <<" Rear = " <<Q1.rear();

    std::cout <<std::endl;
    return 0;
}
