#include <stdlib.h>
#include <iostream>

template<class DataType>
class Node{
 public:
    DataType value;
    Node<DataType> *next;

    Node(DataType val, Node<DataType>* ptr) {
        value = val;
        next = ptr;
    }

    ~Node(){
        free(next);
    }
};

template<class DataType>
class Stack_LL{
 private:
    Node<DataType> *top;
    int len;

 public:
    Stack_LL() {
        top = NULL;
        len = 0;
    }

    ~Stack_LL() {
        Node<DataType>* tempNode;
        while ( top != NULL ) {
            tempNode = top;
            top = top->next;
            tempNode->next = NULL;
            free(tempNode);
        }
    }

    bool is_empty() {
        return (top == NULL);
    }

    void push(DataType value) {
        top = new Node<DataType>(value, top);
        len++;
    }

    DataType pop() {
        if ( is_empty() )
            return -1;

        DataType tempValue = top->value;

        Node<DataType> *tempNode = top;
        top = top->next;
        tempNode->next = NULL;
        free(tempNode);
        len--;

        return tempValue;
    }

    int length() {
        return len;
    }

    void display() {
        if ( !is_empty() ) {
            Node<DataType> *temp = top;
            while ( temp != NULL ) {
                std::cout <<temp->value <<", ";
                temp = temp->next;
            }
        }
    }
};


int main() {
    srand(time(NULL));

    Stack_LL<int> S1;
    int temp;

    std::cout <<"Push 5 random values in stack :";
    for (int i = 0; i < 5; i++) {
        temp = random() % 100;
        std::cout <<"\nPushing : " <<temp;
        S1.push(temp);
    }

    std::cout <<"\n\nStack = ";
    S1.display();

    std::cout <<"\n\nPop: popped value = " <<S1.pop();

    std::cout <<"\n\nStack = ";
    S1.display();

    std::cout <<"\n\nPop stack until empty :";
    while ( !S1.is_empty() ) {
        std::cout <<"\nPopped : " <<S1.pop();
    }

    std::cout <<std::endl;
    return 0;
}
