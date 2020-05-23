#include <iostream>
#include <vector>
#include <map>

struct Node {
    char value;
    int frequency;
    Node* left, *right;
};

void minheapify(std::vector<Node*> *characterNodes, int current, int limit) {
    int leftChildIndex = current * 2 + 1;
    int rightChildIndex = leftChildIndex + 1;

    Node *leftChild = (leftChildIndex < limit) ?
                                (*characterNodes)[leftChildIndex] :
                                NULL;
    Node *rightChild = (rightChildIndex < limit) ?
                                (*characterNodes)[rightChildIndex] :
                                NULL;
    Node *currentNode = (*characterNodes)[current];
    Node *smallestNode = currentNode;

    int smallest = current;

    if ( leftChildIndex < limit &&
            leftChild->frequency < smallestNode->frequency ) {
        smallest = leftChildIndex;
        smallestNode = leftChild;
    }
    if ( rightChildIndex < limit &&
            rightChild->frequency < smallestNode->frequency ) {
        smallest = rightChildIndex;
    }

    if ( smallest != current ) {
        if ( smallest == leftChildIndex ) {
            std::swap(*leftChild, *currentNode);
            minheapify(characterNodes, leftChildIndex, limit);
        } else {
            std::swap(*rightChild, *currentNode);
            minheapify(characterNodes, rightChildIndex, limit);
        }
    }
}

Node* extractMinimum(std::vector<Node*> *characterNodes) {
    Node *min = (*characterNodes)[0];
    Node *last = (*characterNodes)[characterNodes->size() - 1];
    std::swap(*min, *last);
    characterNodes->pop_back();
    minheapify(characterNodes, 0, characterNodes->size());
    return last;
}

Node* getHuffmanCodeTree(std::vector<Node*> characterNodes) {
    // build minHeap
    int limit = characterNodes.size();
    for (int i = limit / 2 - 1; i >= 0; i--) {
        minheapify(&characterNodes, i, limit);
    }

    while ( characterNodes.size() != 1 ) {
        Node *newNode = new Node();
        newNode->left = extractMinimum(&characterNodes);
        newNode->right = extractMinimum(&characterNodes);
        newNode->value = 0;
        newNode->frequency = newNode->left->frequency +
                                newNode->right->frequency;
        characterNodes.push_back(newNode);
        minheapify(&characterNodes, 0, characterNodes.size());
    }

    Node *root = characterNodes[0];
    characterNodes.pop_back();
    return root;
}

void buildEncodingMap(Node *root, std::string encoding,
                        std::map<char, std::string> *mapping) {
    if ( root->value != 0 ) {
        mapping->insert(std::make_pair(root->value, encoding));
        return;
    } else {
        buildEncodingMap(root->left, encoding + '0', mapping);
        buildEncodingMap(root->right, encoding + '1', mapping);
    }
}

int main() {
    std::map<char, int> count = {{'a', 45000}, {'b', 13000}, {'c', 12000},
                                {'d', 16000}, {'e', 9000}, {'f', 5000}};
    std::vector<Node*> characterNodes;
    Node *temp;
    for (auto it : count) {
        temp = new Node();
        temp->value = it.first;
        temp->frequency = it.second;
        temp->left = temp->right = NULL;
        characterNodes.push_back(temp);
    }

    Node* huffmanRoot = getHuffmanCodeTree(characterNodes);
    std::map<char, std::string> mapping;
    buildEncodingMap(huffmanRoot, "", &mapping);
    std::cout <<"Huffman encoding :\n";
    for (auto it : mapping) {
        std::cout <<it.first <<" : " <<it.second <<std::endl;
    }

    return 0;
}
