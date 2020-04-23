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
#include <stdlib.h>

using namespace std;

enum colors{RED, BLACK};

class Node{
public:
    Node *parent, *left, *right;
    int value;
    colors node_color;
    //Colour : 0-Black, 1-Red

    Node(Node *parent, int value, Node *left, Node *right, colors node_color = RED){
        this->parent = parent;
        this->value = value;
        this->left = left;
        this->right = right;
        this->node_color = node_color;
    }
};

class RBT{
public:
    Node *nill = new Node(NULL, 0, NULL, NULL, BLACK);    // NULL Node
    Node *root = NULL;

    RBT(){
        root = NULL;
    }

    void inorder(Node *current = NULL){
        if( current == NULL ) current = root;

        // In-Order = (Left, Root, Right)
        if( current != nill ){
            if( current->left != nill ) inorder(current->left);
            cout<<"(" <<current->value <<" " <<((current->node_color == RED) ? "R" : "B") <<"), ";
            if( current->right != nill ) inorder(current->right);
        }
    }

    void left_rotate(Node *node) {

        Node *childNode = node->right;
        Node *parentNode = node->parent;

        node->right = childNode->left;
        if( node->right != nill ){
            node->right->parent = node;
        }
        childNode->left = node;
        node->parent = childNode;

        if( node == root ){
            root = childNode;
            childNode->parent = nill;
        }
        else {
            if( node == parentNode->left) parentNode->left = childNode;
            else parentNode->right = childNode;
            childNode->parent = parentNode;
        }

    }

    void right_rotate(Node *node) {

        Node *childNode = node->left;
        Node *parentNode = node->parent;

        node->left = childNode->right;
        if( node->left != nill ){
            node->left->parent = node;
        }
        childNode->right = node;
        node->parent = childNode;

        if( root == node ) {
            root = childNode;
            childNode->parent = nill;
        }
        else {
            if( parentNode->left == node ) parentNode->left = childNode;
            else parentNode->right = childNode;
            childNode->parent = parentNode;
        }

    }

    void insert_fixup(Node *node) {

        while( node->parent->node_color == RED ){

            if( node->parent == node->parent->parent->left ){
                Node *uncleNode = node->parent->parent->right;
                if( uncleNode->node_color == RED ){
                    node->parent->node_color = uncleNode->node_color = BLACK;
                    node->parent->parent->node_color = RED;
                    node = node->parent->parent;
                }
                else {
                    if( node == node->parent->right ) {
                        node = node->parent;
                        left_rotate(node);
                    }
                    node->parent->node_color = BLACK;
                    node->parent->parent->node_color = RED;
                    right_rotate(node->parent->parent);
                }
            }
            else if( node->parent == node->parent->parent->right ){
                Node *uncleNode = node->parent->parent->left;
                if( uncleNode->node_color == RED ){
                    node->parent->node_color = uncleNode->node_color = BLACK;
                    node->parent->parent->node_color = RED;
                    node = node->parent->parent;
                }
                else {
                    if( node == node->parent->left ) {
                        node = node->parent;
                        right_rotate(node);
                    }
                    node->parent->node_color = BLACK;
                    node->parent->parent->node_color = RED;
                    left_rotate(node->parent->parent);
                }
            }
        }

        root->node_color = BLACK;

    }

    void insert(int value){
        if( root == NULL ) root = new Node(nill, value, nill, nill, BLACK);
        else{
            Node *temp_parent = root, *temp = root;
            while( temp != nill ){
                temp_parent = temp;
                temp = ( value <= temp->value ) ? temp->left : temp->right;
            }

            Node *new_node = new Node(temp_parent, value, nill, nill, RED);
            if( value <= temp_parent->value ) temp_parent->left = new_node;
            else temp_parent->right = new_node;

            insert_fixup(new_node);
        }
    }

};

int main(){

    srand(0);
    int temp;
    RBT a;

    for(int i = 0; i < 10; i++) {
        temp = random() % 200 + 1;
        cout <<"\nInserting " <<temp;
        a.insert(temp);
    }

    cout <<"\n\nInorder : ";
    a.inorder();

    cout<<endl;
    return 0;

}
