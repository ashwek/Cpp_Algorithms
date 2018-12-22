/*
A binary search tree is a rooted binary tree, whose internal nodes each
store a key (and optionally, an associated value) and each have two
distinguished sub-trees, commonly denoted left and right.

The tree additionally satisfies the binary search property, which states that
the key in each node must be greater than or equal to any key stored in the
left sub-tree, and less than or equal to any key stored in the right sub-tree.

https://en.wikipedia.org/wiki/Binary_search_tree

*/

#include <iostream>

using namespace std;

class Node{
    public:
        Node *parent, *left, *right;
        int value;

        Node(Node *Parent = NULL, int Value = 0, Node *Left = NULL, Node *Right = NULL){
            parent = Parent;
            value = Value;
            left = Left;
            right = Right;
        }
};

class BST{
    private:
        Node *root;
    public:
        BST(){
            root = NULL;
        }
        bool is_empty(){
            return root == NULL;
        }
        void insert(int val){
            if( is_empty() )
                root = new Node(NULL, val);
            else{
                Node *current = root, *parent;
                while( current != NULL ){
                    parent = current;
                    current = ( val <= current->value ) ? current->left : current->right;
                }

                if( val <= parent->value )
                    parent->left = new Node(parent, val);
                else
                    parent->right = new Node(parent, val);
            }
        }
};

int main(){

    BST a;
    a.insert(28);

    cout<<endl;
    return 0;
}
