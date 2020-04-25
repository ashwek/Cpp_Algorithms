#include <stdlib.h>
#include <iostream>
#include <vector>

template<class DataType>
class Stack{
 private:
    DataType *data;
    int top, size;

 public:
    explicit Stack(int s = 10) {
        data = new DataType[s];
        top = -1;
        size = s;
    }

    ~Stack() {
        free(data);
    }

    int is_empty() {
        return (top == -1);
    }

    int is_full() {
        return (top == size-1);
    }

    int push(DataType value) {
        if ( is_full() )
            return 0;
        data[++top] = value;
        return 1;
    }

    int pop() {
        if ( is_empty() )
            return -1;
        return data[top--];
    }

    void display() {
        if ( !is_empty() ) {
            for (int i = top; i >= 0; i--)
                std::cout <<data[i] <<", ";
        }
    }
};


int main() {
    srand(time(NULL));

    Stack<int> S1 = Stack<int>(5);
    int temp;

    std::cout <<"\nPushing random values until stack is full:\n";
    while ( !S1.is_full() ) {
        temp = random() % 100 + 1;
        std::cout <<"Push : " <<temp <<std::endl;
        S1.push(temp);
    }

    std::cout <<"\nStack : ";
    S1.display();

    std::cout <<"\n\nPop: popped value = " <<S1.pop();

    std::cout <<"\n\nStack : ";
    S1.display();

    std::cout <<"\n\nPop stack until it is empty :";
    while ( !S1.is_empty() ) {
        std::cout <<"\nPopped value : " <<S1.pop();
    }

    std::cout <<std::endl;
    return 0;
}
