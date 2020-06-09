#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using std::vector;
using std::map;

class Vertex {
 public:
    char value;
    int distance;
    Vertex *parent;

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


class priority_queue {
 public:
    vector<Vertex*> data;

    void push(Vertex *v);
    Vertex *pop();
    void build_min_heap();
    void min_heapify(int pos);
    int size();
};

void priority_queue::push(Vertex *v) {
    data.push_back(v);
}

Vertex *priority_queue::pop() {
    Vertex *top = data[0];
    data.erase(data.begin());
    return top;
}

void priority_queue::build_min_heap() {
    for (int i = (data.size() / 2) - 1; i >= 0; i--) {
        min_heapify(i);
    }
}

void priority_queue::min_heapify(int pos) {
    unsigned int leftChild = pos * 2 + 1;
    unsigned int rightChild = leftChild + 1;

    leftChild = (leftChild >= data.size()) ? pos : leftChild;
    rightChild = (rightChild >= data.size()) ? pos : rightChild;

    int smallest = pos;
    if ( data[leftChild]->distance < data[smallest]->distance ) {
        smallest = leftChild;
    }
    if ( data[rightChild]->distance < data[smallest]->distance ) {
        smallest = rightChild;
    }

    if ( smallest != pos ) {
        std::swap(data[smallest], data[pos]);
        min_heapify(smallest);
    }
}

int priority_queue::size() {
    return data.size();
}


class Graph {
 public:
    vector<Vertex*> vertices;
    map<Vertex*, vector<Edge*>> edges;

    void addVertex(Vertex *v);
    void addEdge(Vertex *src, Vertex *dst, int weight);
    void printAdj();
    void relax(Vertex *src, Vertex *dst, int weight);
    void djkstra(Vertex *src = NULL);
};

void Graph::addVertex(Vertex *v) {
    vertices.push_back(v);
}

void Graph::addEdge(Vertex *src, Vertex *dst, int weight) {
    edges[src].push_back(new Edge(src, dst, weight));
}

void Graph::printAdj() {
    std::cout <<"\nAdjacency list Dst(Weight) :\n";
    for (Vertex *v : vertices) {
        std::cout <<v->value <<" : ";
        for (Edge *e : edges[v]) {
            std::cout <<e->dst->value <<"(" <<e->weight <<"), ";
        }
        std::cout <<std::endl;
    }
}

void Graph::relax(Vertex *src, Vertex *dst, int weight) {
    if ( dst->distance > (src->distance + weight) ) {
        dst->distance = src->distance + weight;
        dst->parent = src;
    }
}

void Graph::djkstra(Vertex *src) {
    if ( src == NULL ) {
        src = vertices[0];
    }

    priority_queue pq;

    for (Vertex *v : vertices) {
        v->distance = INT32_MAX;
        v->parent = NULL;
        pq.push(v);
    }

    src->distance = 0;
    pq.build_min_heap();

    Vertex *v;
    while (pq.size() != 0) {
        v = pq.pop();
        for (Edge *e : edges[v]) {
            relax(e->src, e->dst, e->weight);
        }
        pq.build_min_heap();
    }

    std::cout <<"\n Vertex | Distance from (" <<src->value <<")\n";
    std::cout <<"----------------------------\n";
    for (Vertex *v : vertices) {
        if ( v == src )
            continue;

        std::cout <<std::setw(7) <<v->value <<" | ";
        (v->distance == INT32_MAX) ?
                std::cout <<"INF" :
                std::cout <<v->distance;
        std::cout <<std::endl;
    }
}


int main() {
    Graph g;

    Vertex *s = new Vertex('s');
    Vertex *t = new Vertex('t');
    Vertex *x = new Vertex('x');
    Vertex *y = new Vertex('y');
    Vertex *z = new Vertex('z');

    g.addVertex(s);
    g.addVertex(t);
    g.addVertex(x);
    g.addVertex(y);
    g.addVertex(z);

    g.addEdge(s, t, 10);
    g.addEdge(s, y, 5);

    g.addEdge(t, x, 1);
    g.addEdge(t, y, 2);

    g.addEdge(x, z, 4);

    g.addEdge(y, t, 3);
    g.addEdge(y, x, 9);
    g.addEdge(y, z, 2);

    g.addEdge(z, s, 7);
    g.addEdge(z, x, 6);

    g.printAdj();

    g.djkstra();

    return 0;
}
