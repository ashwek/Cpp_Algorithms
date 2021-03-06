#include <stdlib.h>
#include <iostream>

template<class DataType>
class Node{
 public:
    DataType value;
    Node<DataType> *next;

    Node(DataType value, Node<DataType> *next) {
        this->value = value;
        this->next = next;
    }
};

template<class DataType>
class Queue_LL{
 public:
    Node<DataType> *frontNode, *rearNode;

    Queue_LL() {
        frontNode = rearNode = NULL;
    }

    bool is_empty() {
        return frontNode == NULL;
    }

    void enqueue(DataType value) {
        if ( rearNode == NULL ) {
            frontNode = rearNode = new Node<DataType>(value, NULL);
        } else {
            rearNode->next = new Node<DataType>(value, NULL);
            rearNode = rearNode->next;
        }
    }

    void dequeue() {
        Node<DataType> *tempNode = frontNode;

        if ( frontNode == rearNode )
            frontNode = rearNode = NULL;
        else
            frontNode = frontNode->next;

        tempNode->next = NULL;
        free(tempNode);
    }

    void display() {
        if ( !is_empty() ) {
            Node<DataType> *tempNode = frontNode;
            while ( tempNode != NULL ) {
                std::cout <<tempNode->value <<", ";
                tempNode = tempNode->next;
            }
        }
    }

    DataType front() {
        if ( !is_empty() )
            return frontNode->value;
        return -1;
    }

    DataType rear(){
        if ( !is_empty() )
            return rearNode->value;
        return -1;
    }
};


int main() {
    srand(time(NULL));

    Queue_LL<int> Q1;
    int temp;

    std::cout <<"\nEmqueue 5 random values in queue :";
    for (int i = 0; i < 5; i++) {
        temp = random() % 100 + 1;
        std::cout <<"\nEnqueue : " <<temp;
        Q1.enqueue(temp);
    }

    std::cout <<"\n\nQueue : ";
    Q1.display();

    std::cout <<"\n\nDequeue = " <<Q1.front();
    Q1.dequeue();

    std::cout <<"\n\nQueue : ";
    Q1.display();

    std::cout <<"\n\nFront = " <<Q1.front() <<" Rear = " <<Q1.rear();

    std::cout <<std::endl;
    return 0;
}
