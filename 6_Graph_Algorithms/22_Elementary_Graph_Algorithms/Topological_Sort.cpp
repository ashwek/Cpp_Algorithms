#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

enum colors {WHITE, GRAY, BLACK};

class Vertex {
 public:
    std::string garment;
    Vertex *parent;
    int discoverTimestamp;
    int finishTimestamp;
    colors vertexColor;

    explicit Vertex(std::string garment) {
        this->garment = garment;
    }
};

class Graph {
 public:
    int time;
    std::map<Vertex*, std::vector<Vertex*>> edges;

    Graph();
    void add_edge(Vertex *src, Vertex *dst);
    void print_adj();
    void dfs();
    void dfs_visit(Vertex *src);
    void topological_sort();
    bool comp(Vertex *a, Vertex *b);
};

Graph::Graph() {
}

void Graph::add_edge(Vertex *src, Vertex *dst) {
    if ( edges.count(src) == 0 )
        edges[src] = std::vector<Vertex*>();
    if ( dst != NULL )
        edges[src].push_back(dst);
}

void Graph::print_adj() {
    for (auto it : edges) {
        std::cout <<it.first->garment <<" -> ";
        for (Vertex *temp : it.second)
            std::cout <<temp->garment <<", ";
        std::cout <<std::endl;
    }
}

void Graph::dfs() {
    time = 0;
    for (auto it : edges) {
        it.first->parent = NULL;
        it.first->vertexColor = WHITE;
        it.first->discoverTimestamp = it.first->finishTimestamp = -1;
    }

    for (auto it : edges) {
        if ( it.first->vertexColor == WHITE ) {
            dfs_visit(it.first);
        }
    }
}

void Graph::dfs_visit(Vertex *src) {
    time++;
    src->discoverTimestamp = time;
    src->vertexColor = GRAY;

    for (Vertex *temp : edges[src]) {
        if (temp->vertexColor == WHITE) {
            dfs_visit(temp);
        }
    }

    time++;
    src->finishTimestamp = time;
    src->vertexColor = BLACK;
}

bool comp(Vertex *a, Vertex *b) {
    return a->finishTimestamp > b->finishTimestamp;
}

void Graph::topological_sort() {
    dfs();

    std::vector<Vertex*> vertices;
    for (auto it : edges) {
        vertices.push_back(it.first);
    }

    std::sort(vertices.begin(), vertices.end(), ::comp);
    std::cout <<"\nTopological sort :\n";
    for (Vertex *temp : vertices) {
        std::cout <<temp->garment <<" -> ";
    }
    std::cout <<std::endl;
}

int main() {
    Graph g;
    std::vector<Vertex*> vertices(9);
    vertices[0] = new Vertex("Undershorts");
    vertices[1] = new Vertex("Pants");
    vertices[2] = new Vertex("Belt");
    vertices[3] = new Vertex("Shirt");
    vertices[4] = new Vertex("Tie");
    vertices[5] = new Vertex("Jacket");
    vertices[6] = new Vertex("Socks");
    vertices[7] = new Vertex("Shoes");
    vertices[8] = new Vertex("Watch");

    g.add_edge(vertices[0], vertices[1]);
    g.add_edge(vertices[0], vertices[7]);
    g.add_edge(vertices[1], vertices[2]);
    g.add_edge(vertices[1], vertices[7]);
    g.add_edge(vertices[2], vertices[5]);
    g.add_edge(vertices[3], vertices[2]);
    g.add_edge(vertices[3], vertices[4]);
    g.add_edge(vertices[4], vertices[5]);
    g.add_edge(vertices[6], vertices[7]);
    g.add_edge(vertices[7], NULL);
    g.add_edge(vertices[8], NULL);

    std::cout <<"\nAdjacency List :\n";
    g.print_adj();

    g.topological_sort();

    std::cout <<std::endl;
    return 0;
}
