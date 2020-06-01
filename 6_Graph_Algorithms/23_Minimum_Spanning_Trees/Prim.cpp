#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iomanip>

using std::vector;
using std::map;
using std::priority_queue;
using std::set;

class Vertex {
 public:
    char value;
    int key;
    Vertex* parent;

    explicit Vertex(char value) {
        this->value = value;
    }
};


class Edge {
 public:
    Vertex *src, *dst;
    int weight;

    Edge(Vertex *src, Vertex *dst, int weight) {
        this->src = src;
        this->dst = dst;
        this->weight = weight;
    }
};


template<class T>
class min_queue {
 public:
    vector<T> elements;

    void push(T e);
    T pop();
    int size();
    void min_heapify(int pos = 0);
    void build_min_heap();
};

template<class  T>
int min_queue<T>::size() {
    return elements.size();
}

template<class T>
void min_queue<T>::push(T e) {
    elements.push_back(e);
}

template<class T>
T min_queue<T>::pop() {
    T smallest = elements[0];
    elements.erase(elements.begin());
    return smallest;
}

template<class T>
void min_queue<T>::build_min_heap() {
    for (int i = (elements.size()) / 2 - 1; i >= 0; i--) {
        min_heapify(i);
    }
}

template<class  T>
void min_queue<T>::min_heapify(int pos) {
    int leftChild = pos * 2 + 1;
    int rightChild = leftChild + 1;

    if (leftChild >= elements.size()) {
        leftChild = pos;
    }

    if (rightChild >= elements.size()) {
        rightChild = pos;
    }

    int smallest = pos;
    if ( elements[leftChild]->key < elements[smallest]->key ) {
        smallest = leftChild;
    }

    if ( elements[rightChild]->key < elements[smallest]->key ) {
        smallest = rightChild;
    }

    if ( smallest != pos ) {
        std::swap(elements[pos], elements[smallest]);
        min_heapify(smallest);
    }
}


class Graph {
 public:
    vector<Vertex*> vertices;
    map<Vertex*, vector<Edge*>> edges;

    Graph();
    void addVertex(Vertex *v);
    void addEdge(Vertex *src, Vertex *dst, int weight);
    void prim(Vertex *r = NULL);
};

Graph::Graph() {}

void Graph::addVertex(Vertex *v) {
    vertices.push_back(v);
}

void Graph::addEdge(Vertex *src, Vertex *dst, int weight) {
    edges[src].push_back(new Edge(src, dst, weight));
}

void Graph::prim(Vertex *r) {
    if ( r == NULL )
        r = vertices[0];

    min_queue<Vertex *> pendingVertices;
    for (Vertex *v : vertices) {
        v->parent = NULL;
        v->key = INT32_MAX;

        pendingVertices.push(v);
    }

    r->key = 0;
    pendingVertices.build_min_heap();

    set<Vertex*> completedVertices;
    while (pendingVertices.size() != 0) {
        Vertex *u = pendingVertices.pop();
        for (Edge *e : edges[u]) {
            if ( completedVertices.count(e->dst) == 0 &&
                    e->weight < e->dst->key ) {
                e->dst->parent = u;
                e->dst->key = e->weight;
            }
        }
        pendingVertices.build_min_heap();
        completedVertices.insert(u);
    }

    std::cout <<"\nMinimum Spanning Tree Edges :\n\n";
    std::cout <<"\t  Edge  | Weight\n";
    std::cout <<"\t----------------\n";
    for (Vertex* v : completedVertices) {
        if ( v->parent == NULL )
            continue;

        std::cout <<"\t " <<v->parent->value <<" -> " <<v->value
                    <<" | " <<std::setw(3) <<v->key <<std::endl;
    }
}


int main() {
    Graph g;
    vector<Vertex*> vertices(9);

    for (int i = 0; i < 9; i++) {
        vertices[i] = new Vertex(97 + i);
        g.addVertex(vertices[i]);
    }

    // edges from 'a'
    g.addEdge(vertices[0], vertices[1], 4);
    g.addEdge(vertices[0], vertices[7], 8);

    // edges from 'b'
    g.addEdge(vertices[1], vertices[0], 4);
    g.addEdge(vertices[1], vertices[7], 11);
    g.addEdge(vertices[1], vertices[2], 8);

    // edges from 'c'
    g.addEdge(vertices[2], vertices[1], 8);
    g.addEdge(vertices[2], vertices[8], 2);
    g.addEdge(vertices[2], vertices[5], 4);
    g.addEdge(vertices[2], vertices[3], 7);

    // edges from 'd'
    g.addEdge(vertices[3], vertices[2], 7);
    g.addEdge(vertices[3], vertices[5], 14);
    g.addEdge(vertices[3], vertices[4], 9);

    // edges from 'e'
    g.addEdge(vertices[4], vertices[3], 9);
    g.addEdge(vertices[4], vertices[5], 10);

    // edges from 'f'
    g.addEdge(vertices[5], vertices[6], 2);
    g.addEdge(vertices[5], vertices[2], 4);
    g.addEdge(vertices[5], vertices[3], 14);
    g.addEdge(vertices[5], vertices[5], 10);

    // edges from 'g'
    g.addEdge(vertices[6], vertices[7], 1);
    g.addEdge(vertices[6], vertices[8], 6);
    g.addEdge(vertices[6], vertices[5], 2);

    // edges from 'h'
    g.addEdge(vertices[7], vertices[0], 8);
    g.addEdge(vertices[7], vertices[1], 11);
    g.addEdge(vertices[7], vertices[8], 7);
    g.addEdge(vertices[7], vertices[6], 1);

    // edges from 'i'
    g.addEdge(vertices[8], vertices[7], 7);
    g.addEdge(vertices[8], vertices[2], 2);
    g.addEdge(vertices[8], vertices[6], 6);

    g.prim();

    return 0;
}
