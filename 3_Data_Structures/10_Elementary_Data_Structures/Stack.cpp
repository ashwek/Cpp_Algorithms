#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

template<class DataType>
class Stack{

private:
    DataType *data;
    int top, size;

public:

    Stack(int s = 10) {
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
        if( is_full() )
            return 0;
        data[++top] = value;
        return 1;
    }

    int pop(){

        if( is_empty() )
            return -1;
        return data[top--];

    }

    void display(){
        if( ! is_empty() ){
            for(int i=top; i>=0; i--)
                cout<<data[i] <<", ";
        }
    }

};


int main(){

    srand(time(NULL));

    Stack<int> S1 = Stack<int>(5);
    int temp;
    cout <<"\nPushing random values until stack is full:\n";
    while( ! S1.is_full() ) {
        temp = random() % 100 + 1;
        cout<<"Push : " <<temp <<endl;
        S1.push(temp);
    }

    cout<<"\nStack : ";
    S1.display();

    cout<<"\n\nPop: popped value = " <<S1.pop();

    cout<<"\n\nStack : ";
    S1.display();

    cout<<"\n\nPop stack until it is empty :";
    while( ! S1.is_empty() ){
        cout<<"\nPopped value : " <<S1.pop();
    }

    cout<<endl;

    return 0;
}
