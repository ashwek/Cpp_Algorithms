/*
A red–black tree is a kind of self-balancing binary search tree in computer science.
Each node of the binary tree has an extra bit, and that bit is often interpreted as
the color (red or black) of the node. These color bits are used to ensure the tree
remains approximately balanced during insertions and deletions.

https://en.wikipedia.org/wiki/Red%E2%80%93black_tree

https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
*/

#include <iostream>
#include <vector>

using namespace std;

class Node{

    public:
        Node *parent, *left, *right;
        int value, colour;
        //Colour : 0-Black, 1-Red

        Node(Node *parent, int value, Node *left, Node *right, int colour = 1){
            this->parent = parent;
            this->value = value;
            this->left = left;
            this->right = right;
            this->colour = colour;
        }
};

int main(){

    cout<<endl;
    return 0;
}
