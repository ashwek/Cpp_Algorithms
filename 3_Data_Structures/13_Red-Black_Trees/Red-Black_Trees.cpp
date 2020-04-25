/*
A red–black tree is a kind of self-balancing binary search tree in computer science.
Each node of the binary tree has an extra bit, and that bit is often interpreted as
the color (red or black) of the node. These color bits are used to ensure the tree
remains approximately balanced during insertions and deletions.

https://en.wikipedia.org/wiki/Red%E2%80%93black_tree

https://www.cs.usfca.edu/~galles/visualization/RedBlack.html

http://www.cs.armstrong.edu/liang/animation/web/RBTree.html
*/

#include <stdlib.h>
#include <iostream>
#include <vector>

enum colors{RED, BLACK};

class Node{
 public:
    Node *parent, *left, *right;
    int value;
    colors node_color;

    Node(Node *parent, int value, Node *left, Node *right,
        colors node_color = RED) {
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

    RBT() {
        root = NULL;
    }

    void inorder(Node *current = NULL) {
        if ( current == NULL ) current = root;

        // In-Order = (Left, Root, Right)
        if ( current != nill ) {
            if ( current->left != nill ) inorder(current->left);
            std::cout <<"(" <<current->value <<" "
                    <<((current->node_color == RED) ? "R" : "B") <<"), ";
            if ( current->right != nill ) inorder(current->right);
        }
    }

    void left_rotate(Node *node) {
        Node *childNode = node->right;
        Node *parentNode = node->parent;

        node->right = childNode->left;
        if ( node->right != nill ) {
            node->right->parent = node;
        }
        childNode->left = node;
        node->parent = childNode;

        if ( node == root ) {
            root = childNode;
            childNode->parent = nill;
        } else {
            if ( node == parentNode->left)
                parentNode->left = childNode;
            else
                parentNode->right = childNode;
            childNode->parent = parentNode;
        }
    }

    void right_rotate(Node *node) {
        Node *childNode = node->left;
        Node *parentNode = node->parent;

        node->left = childNode->right;
        if ( node->left != nill ) {
            node->left->parent = node;
        }
        childNode->right = node;
        node->parent = childNode;

        if ( root == node ) {
            root = childNode;
            childNode->parent = nill;
        } else {
            if ( parentNode->left == node )
                parentNode->left = childNode;
            else
                parentNode->right = childNode;
            childNode->parent = parentNode;
        }
    }

    void insert_fixup(Node *node) {
        while ( node->parent->node_color == RED ) {
            if ( node->parent == node->parent->parent->left ) {
                Node *uncleNode = node->parent->parent->right;
                if ( uncleNode->node_color == RED ) {
                    node->parent->node_color = uncleNode->node_color = BLACK;
                    node->parent->parent->node_color = RED;
                    node = node->parent->parent;
                } else {
                    if ( node == node->parent->right ) {
                        node = node->parent;
                        left_rotate(node);
                    }
                    node->parent->node_color = BLACK;
                    node->parent->parent->node_color = RED;
                    right_rotate(node->parent->parent);
                }
            } else if ( node->parent == node->parent->parent->right ) {
                Node *uncleNode = node->parent->parent->left;
                if ( uncleNode->node_color == RED ) {
                    node->parent->node_color = uncleNode->node_color = BLACK;
                    node->parent->parent->node_color = RED;
                    node = node->parent->parent;
                } else {
                    if ( node == node->parent->left ) {
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

    void insert(int value) {
        if ( root == NULL ) {
            root = new Node(nill, value, nill, nill, BLACK);
        } else {
            Node *temp_parent = root, *temp = root;
            while ( temp != nill ) {
                temp_parent = temp;
                temp = (value <= temp->value) ? temp->left : temp->right;
            }

            Node *new_node = new Node(temp_parent, value, nill, nill, RED);
            if ( value <= temp_parent->value )
                temp_parent->left = new_node;
            else
                temp_parent->right = new_node;

            insert_fixup(new_node);
        }
    }

    Node *search(int value) {
        Node *tempNode = root;
        while ( tempNode != nill ) {
            if ( tempNode->value == value ) return tempNode;
            tempNode = (value <= tempNode->value) ?
                        tempNode->left :
                        tempNode->right;
        }
        return NULL;
    }

    void transplant(Node *node, Node *replacement) {
        if ( node == root )
            root = replacement;
        else if ( node->parent->left == node )
            node->parent->left = replacement;
        else
            node->parent->right = replacement;
        replacement->parent = node->parent;
    }

    Node *successor(Node *node) {
        if ( node == NULL ) node = root;
        if ( node == NULL || node == nill ) return NULL;

        if ( node->right == nill ) {
            while ( node->parent != nill && node->parent->right == node )
                node = node->parent;
            return node->parent;
        }

        Node *tempNode = node->right;
        while ( tempNode->left != nill )
            tempNode = tempNode->left;

        return tempNode;
    }

    void delete_fix_up(Node *node) {
        Node *sibling;
        while ( node != root && node->node_color == BLACK ) {
            if ( node == node->parent->left ) {
                sibling = node->parent->right;
                if ( sibling->node_color == RED ) {
                    sibling->node_color = BLACK;
                    node->parent->node_color = RED;
                    left_rotate(node->parent);
                    sibling = node->parent->right;
                }

                if ( sibling->left->node_color == BLACK &&
                    sibling->right->node_color == BLACK ) {
                    sibling->node_color = RED;
                    node = node->parent;
                } else {
                    if ( sibling->right->node_color == BLACK ) {
                        sibling->left->node_color = BLACK;
                        sibling->node_color = RED;
                        right_rotate(sibling);
                        sibling = node->parent->right;
                    }
                    sibling->node_color = node->parent->node_color;
                    sibling->right->node_color = BLACK;
                    node->parent->node_color = BLACK;
                    left_rotate(node->parent);
                    node = root;
                }
            } else {
                sibling = node->parent->left;
                if ( sibling->node_color == RED ) {
                    sibling->node_color = BLACK;
                    node->parent->node_color = RED;
                    right_rotate(node->parent);
                    sibling = node->parent->left;
                }

                if ( sibling->left->node_color == BLACK &&
                    sibling->right->node_color == BLACK ) {
                    sibling->node_color = RED;
                    node = node->parent;
                } else {
                    if ( sibling->left->node_color == BLACK ) {
                        sibling->right->node_color = BLACK;
                        sibling->node_color = RED;
                        left_rotate(sibling);
                        sibling = node->parent->left;
                    }
                    sibling->node_color = node->parent->node_color;
                    sibling->left->node_color = BLACK;
                    node->parent->node_color = BLACK;
                    right_rotate(node->parent);
                    node = root;
                }
            }
        }
        node->node_color = BLACK;
    }

    void remove(Node *node){
        if ( node == NULL || node == nill )
            return;

        colors delete_node_color = node->node_color;
        Node *replacement;

        if ( node->left == nill ) {
            replacement = node->right;
            transplant(node, replacement);
        } else if ( node->right == nill ) {
            replacement = node->left;
            transplant(node, replacement);
        } else {
            Node *replacement = successor(node);
            node->value = replacement->value;
            remove(replacement);
            return;
        }

        if ( delete_node_color == BLACK ) {
            delete_fix_up(replacement);
        }
    }
};

int main() {
    srand(0);

    int temp;
    RBT a;

    std::vector<int> nodes;

    std::cout <<"\nInserting 10 nodes :";
    for (int i = 0; i < 10; i++) {
        temp = random() % 200 + 1;
        std::cout <<"\n\tInserting " <<temp;
        a.insert(temp);
        nodes.push_back(temp);
    }

    std::cout <<"\n\nInorder : ";
    a.inorder();

    std::cout <<"\n\nDeleting 5 nodes :";
    while ( nodes.size() > 5 ) {
        temp = random() % nodes.size();
        std::cout << "\n\tDeleting : " <<nodes[temp];
        a.remove(a.search(nodes[temp]));
        nodes.erase(nodes.begin() + temp);
    }

    std::cout <<"\n\nInorder : ";
    a.inorder();

    std::cout <<std::endl;
    return 0;
}
