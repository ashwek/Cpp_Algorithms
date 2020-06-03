#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using std::vector;
using std::set;

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

class Graph {
 public:
    vector<Vertex*> vertices;
    set<Edge*> edges;

    void addVertex(Vertex *v);
    void addEdge(Vertex *src, Vertex *dst, int weight);
    void relax(Vertex *src, Vertex *dst, int weight);
    void bellmanFord(Vertex *src = NULL);
};

void Graph::addVertex(Vertex *v) {
    vertices.push_back(v);
}

void Graph::addEdge(Vertex *src, Vertex *dst, int weight) {
    edges.insert(new Edge(src, dst, weight));
}

void Graph::relax(Vertex *src, Vertex *dst, int weight) {
    if ( dst->distance > src->distance + weight ) {
        dst->distance = src->distance + weight;
        dst->parent = src;
    }
}

void Graph::bellmanFord(Vertex *src) {
    if ( src == NULL )
        src = vertices[0];

    // initialize
    for (Vertex *v : vertices) {
        v->distance = INT32_MAX;
        v->parent = NULL;
    }

    src->distance = 0;

    for (int i = 0; i < vertices.size() - 1; i++) {
        for (Edge *e : edges) {
            relax(e->src, e->dst, e->weight);
        }
    }

    for (Edge *e : edges) {
        if ( e->dst->distance > (e->src->distance + e->weight) ) {
            std::cout <<"Graph contains negative weighted cycle\n";
            return;
        }
    }

    std::cout <<"Vertex | Distance from source (" <<src->value <<")\n";
    std::cout <<"---------------------------------\n";
    for (Vertex *v : vertices) {
        std::cout <<std::setw(5) <<v->value <<"  | "
                    <<v->distance <<std::endl;
    }
}

int main() {
    Graph g;

    Vertex s('s'), t('t'), x('x'), y('y'), z('z');
    g.addVertex(&s);
    g.addVertex(&t);
    g.addVertex(&x);
    g.addVertex(&y);
    g.addVertex(&z);

    g.addEdge(&s, &t, 6);
    g.addEdge(&s, &y, 7);

    g.addEdge(&t, &x, 5);
    g.addEdge(&t, &z, -4);
    g.addEdge(&t, &y, 8);

    g.addEdge(&x, &t, -2);

    g.addEdge(&y, &x, -3);
    g.addEdge(&y, &z, 9);

    g.addEdge(&z, &s, 2);
    g.addEdge(&z, &x, 7);

    g.bellmanFord();

    return 0;
}
