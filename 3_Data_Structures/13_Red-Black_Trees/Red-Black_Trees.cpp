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

class RBT{

    public:
        Node *nill = new Node(NULL, 0, NULL, NULL, 0);    // NULL Node
        Node *root = NULL;

        RBT(){
            root = NULL;
        }

        void insert(int value){
            if( root == NULL ) root = new Node(nill, value, nill, nill, 0);
            else{
                Node *temp_parent = root, *temp = root;
                while( temp != nill ){
                    temp_parent = temp;
                    temp = ( value <= temp->value ) ? temp->left : temp->right;
                }

                Node *new_node = new Node(temp_parent, value, nill, nill);
                if( value <= temp_parent->value ) temp_parent->left = new_node;
                else temp_parent->right = new_node;

                //Call fixup method
            }
        }
};

int main(){

    int ins_values[] ={33, 65, 50, 55, 42, 31, 15, 65, 22, 87};
    RBT a;

    for(int i=0; i<10; i++)
        a.insert(ins_values[i]);

    cout<<endl;
    return 0;
}
