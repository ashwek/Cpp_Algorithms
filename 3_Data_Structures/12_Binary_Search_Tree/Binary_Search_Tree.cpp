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
#include <vector>

template<class DataType>
class Node{
 public:
    Node<DataType> *parent, *left, *right;
    DataType value;

    Node(Node<DataType> *parent, DataType value,
        Node<DataType> *left = NULL, Node<DataType> *right = NULL) {
        this->parent = parent;
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

template<class DataType>
class BST{
 private:
    Node<DataType> *root;

 public:
    BST() {
        root = NULL;
    }

    bool is_empty() {
        return root == NULL;
    }

    void insert(DataType val) {
        if ( is_empty() ) {
            root = new Node<DataType>(NULL, val);
        } else {
            Node<DataType> *current = root, *parent;
            while ( current != NULL ) {
                parent = current;
                current = (val <= current->value) ? current->left
                                                : current->right;
            }

            if ( val <= parent->value )
                parent->left = new Node<DataType>(parent, val);
            else
                parent->right = new Node<DataType>(parent, val);
        }
    }

    void preorder(Node<DataType> *current = NULL) {
        if ( current == NULL ) current = root;

        // Pre-Order = (Root, Left, Right)
        if (current != NULL) {
            std::cout <<current->value <<", ";
            if ( current->left != NULL ) preorder(current->left);
            if ( current->right != NULL ) preorder(current->right);
        }
    }

    void inorder(Node<DataType> *current = NULL) {
        if ( current == NULL ) current = root;

        // In-Order = (Left, Root, Right)
        if ( current != NULL ) {
            if ( current->left != NULL ) inorder(current->left);
            std::cout <<current->value <<", ";
            if ( current->right != NULL ) inorder(current->right);
        }
    }

    void postorder(Node<DataType> *current = NULL) {
        if ( current == NULL ) current = root;

        // Post-Order = (Left, Right, Root)
        if ( current != NULL ) {
            if ( current->left != NULL ) postorder(current->left);
            if ( current->right != NULL ) postorder(current->right);
            std::cout <<current->value <<", ";
        }
    }

    void levelorder(Node<DataType> *current = NULL) {
        std::vector<Node<DataType>*> next_level;

        if ( current == NULL && root != NULL ) {
            next_level.push_back(root);
        }

        while ( next_level.size() > 0 ) {
            std::cout <<next_level[0]->value <<", ";

            if ( next_level[0]->left != NULL ) {
                next_level.push_back(next_level[0]->left);
            }
            if ( next_level[0]->right != NULL ) {
                next_level.push_back(next_level[0]->right);
            }

            next_level.erase(next_level.begin());
        }
    }

    Node<DataType> *search(DataType find) {
        Node<DataType> *current = root;

        while ( current != NULL && current->value != find )
            current = (current->value < find) ? current->right : current->left;

        return current;
    }

    Node<DataType> *maximum(Node<DataType> *current = NULL) {
        if ( current == NULL ) current = root;

        while ( current != NULL && current->right != NULL )
            current = current->right;

        return current;
    }

    Node<DataType> *minimum(Node<DataType> *current = NULL) {
        if ( current == NULL ) current = root;

        while ( current != NULL && current->left != NULL )
            current = current->left;

        return current;
    }

    Node<DataType> *successor(Node<DataType> *current) {
        if ( current == NULL ) return NULL;

        if ( current->right == NULL ) {
            while ( current->parent != NULL &&
                current->parent->right == current )
                current = current->parent;
            return current->parent;
        } else {
            return minimum(current->right);
        }
    }

    Node<DataType> *predecessor(Node<DataType> *current){
        if ( current == NULL ) return NULL;

        if ( current->left == NULL ) {
            while ( current->parent != NULL &&
                current->parent->left == current )
                current = current->parent;
            return current->parent;
        } else {
            return maximum(current->left);
        }
    }
};

int main() {
    int ins_values[] = {28, 33, 21, 37, 21, 47, 40, 22, 1, 16};
    BST<int> a;

    for (int i = 0; i < 10; i++)
        a.insert(ins_values[i]);

    std::cout <<"  BST Preorder: ";
    a.preorder();

    std::cout <<"\n   BST Inorder: ";
    a.inorder();

    std::cout <<"\n BST Postorder: ";
    a.postorder();

    std::cout <<"\nBST Levelorder: ";
    a.levelorder();

    int search = 33;
    Node<int> *srh = a.search(search);
    if ( !srh )
        std::cout <<"\n\n" <<search <<" not found in tree";
    else
        std::cout <<"\n\n" <<search <<" found in tree";

    std::cout <<"\n\nMax node = " <<a.maximum()->value;
    std::cout <<"\nMin node = " <<a.minimum()->value;

    Node<int> *temp = a.successor(a.search(22));
    if ( temp != NULL )
        std::cout <<"\n\nSuccessor of 47 = " <<temp->value;
    temp = a.predecessor(a.search(22));
    if ( temp != NULL )
        std::cout <<"\nPredecessor of 47 = " <<temp->value;

    std::cout <<std::endl;
    return 0;
}
