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
    Vertex *parent;
    int distance;
    int discoverTime;
    int finishTime;

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
    map<Vertex*, vector<Edge*>> edges;
    int time;

    static bool compFinishTime(Vertex *a, Vertex *b);

    void addVertex(Vertex *v);
    void addEdge(Vertex *src, Vertex *dst, int weight);
    void print_adj();
    void dfs();
    void dfs_visit(Vertex *v);
    void relax(Vertex *u, Vertex *v, int weight);
    void dag_shortest_path(Vertex *src);
};

bool Graph::compFinishTime(Vertex *a, Vertex *b) {
    return a->finishTime > b->finishTime;
}


void Graph::addVertex(Vertex *v) {
    vertices.push_back(v);
}

void Graph::addEdge(Vertex *src, Vertex *dst, int weight) {
    edges[src].push_back(new Edge(src, dst, weight));
}

void Graph::print_adj() {
    std::cout <<"\nAdjacency list dst(weight):\n";
    for (Vertex *v : vertices) {
        std::cout <<v->value <<" : ";
        for (Edge *e : edges[v]) {
            std::cout <<e->dst->value <<"(" <<e->weight <<"), ";
        }
        std::cout <<std::endl;
    }
}

void Graph::dfs() {
    time = 0;
    for (Vertex *v : vertices) {
        v->discoverTime = v->finishTime = -1;
        v->parent = NULL;
        v->distance = -1;
    }

    for (Vertex *v : vertices) {
        if ( v->discoverTime == -1 ) {
            dfs_visit(v);
        }
    }
}

void Graph::dfs_visit(Vertex *v) {
    time++;
    v->discoverTime = time;

    for (Edge *e : edges[v]) {
        if ( e->dst->discoverTime == - 1 ) {
            dfs_visit(e->dst);
        }
    }

    time++;
    v->finishTime = time;
}

void Graph::relax(Vertex *u, Vertex *v, int weight) {
    if ( v->distance == - 1 || v->distance > (u->distance + weight) ) {
        v->distance = (u->distance + weight);
        v->parent = u;
    }
}

void Graph::dag_shortest_path(Vertex *src) {
    dfs();
    std::sort(vertices.begin(), vertices.end(), Graph::compFinishTime);

    src->distance = 0;

    for (Vertex *u : vertices) {
        for (Edge *e : edges[u]) {
            relax(e->src, e->dst, e->weight);
        }
    }

    std::cout <<" Vertex | Distance from (" <<src->value <<")\n";
    std::cout <<"-----------------------------\n";
    for (Vertex *v : vertices) {
        if ( src == v )
            continue;

        std::cout <<std::setw(7) <<v->value <<" | ";
        (v->distance == -1) ?
                std::cout <<"INF" :
                std::cout <<v->distance;
        std::cout <<std::endl;
    }
}


int main() {
    Graph g;

    Vertex *r = new Vertex('r');
    Vertex *s = new Vertex('s');
    Vertex *t = new Vertex('t');
    Vertex *x = new Vertex('x');
    Vertex *y = new Vertex('y');
    Vertex *z = new Vertex('z');

    g.addVertex(r);
    g.addVertex(s);
    g.addVertex(t);
    g.addVertex(x);
    g.addVertex(y);
    g.addVertex(z);

    g.addEdge(r, s, 5);
    g.addEdge(r, t, 3);

    g.addEdge(s, x, 6);
    g.addEdge(s, t, 2);

    g.addEdge(t, x, 7);
    g.addEdge(t, y, 4);
    g.addEdge(t, z, 2);

    g.addEdge(x, z, 1);
    g.addEdge(x, y, -1);

    g.addEdge(y, z, -2);

    g.print_adj();
    std::cout <<std::endl;

    g.dag_shortest_path(s);

    return 0;
}
