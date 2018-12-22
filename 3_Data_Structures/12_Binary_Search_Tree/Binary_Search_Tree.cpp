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

        void preorder(Node *current = NULL){
            if( current == NULL ) current = root;

            // Pre-Order = (Root, Left, Right)
            if(current != NULL){
                cout<<current->value <<", ";
                if( current->left != NULL ) preorder(current->left);
                if( current->right != NULL ) preorder(current->right);
            }
        }

        void inorder(Node *current = NULL){
            if( current == NULL ) current = root;

            // In-Order = (Left, Root, Right)
            if( current != NULL ){
                if( current->left != NULL ) inorder(current->left);
                cout<<current->value <<", ";
                if( current->right != NULL ) inorder(current->right);
            }
        }

        void postorder(Node *current = NULL){
            if( current == NULL ) current = root;

            // Post-Order = (Left, Right, Root)
            if( current != NULL ){
                if( current->left != NULL ) postorder(current->left);
                if( current->right != NULL ) postorder(current->right);
                cout<<current->value <<", ";
            }
        }

        Node *search(int find){
            Node *current = root;

            while( current != NULL and current->value != find )
                current = (current->value < find) ? current->right : current->left;

            return current;
        }
};

int main(){

    int ins_values[] = {28, 33, 21, 37, 21, 47, 40, 22, 1, 16};
    BST a;

    for(int i=0; i<10; i++)
        a.insert(ins_values[i]);

    cout<<"BST  Preorder: ";
    a.preorder();
    cout<<"\nBST   Inorder: ";
    a.inorder();
    cout<<"\nBST Postorder: ";
    a.postorder();

    int search = 33;
    Node *srh = a.search(search);
    if( ! srh )
        cout <<"\n\n" <<search <<" not found in tree";
    else
        cout <<"\n\n" <<search <<" found in tree";

    cout<<endl;
    return 0;
}
