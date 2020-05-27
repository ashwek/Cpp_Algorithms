#include <iostream>
#include <vector>
#include <map>

enum colors {WHITE, GRAY, BLACK};

class Vertex {
 public:
    int value;
    colors vertexColor;
    Vertex* parent;
    int discoverTimestamp;
    int finishedTimestamp;

    explicit Vertex(int value) {
        this->value = value;
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
    int print_path(Vertex *src, Vertex *dst);
};

Graph::Graph() {
}

void Graph::add_edge(Vertex *src, Vertex *dst) {
    if ( edges.count(src) == 0 )
        edges[src] = std::vector<Vertex*>();
    edges[src].push_back(dst);
}

void Graph::print_adj() {
    for (auto it : edges) {
        std::cout <<it.first->value <<" -> ";
        for (Vertex *temp : it.second) {
            std::cout <<temp->value <<", ";
        }
        std::cout <<std::endl;
    }
}

void Graph::dfs_visit(Vertex *src) {
    time++;
    src->discoverTimestamp = time;
    src->vertexColor = GRAY;

    for (Vertex *temp : edges[src]) {
        if (temp->vertexColor == WHITE) {
            temp->parent = src;
            std::cout <<temp->value <<" -> ";
            dfs_visit(temp);
        }
    }

    time++;
    src->finishedTimestamp = time;
    src->vertexColor = BLACK;
}

void Graph::dfs() {
    for (auto it : edges) {
        it.first->vertexColor = WHITE;
        it.first->parent = NULL;
    }
    time = 0;

    for (auto it : edges) {
        if (it.first->vertexColor == WHITE) {
            std::cout <<it.first->value <<" -> ";
            dfs_visit(it.first);
            std::cout <<std::endl;
        }
    }
}

int main() {
    Graph g;
    std::vector<Vertex*> vertices(6);

    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] = new Vertex(i);
    }

    g.add_edge(vertices[0], vertices[1]);
    g.add_edge(vertices[0], vertices[3]);
    g.add_edge(vertices[1], vertices[4]);
    g.add_edge(vertices[2], vertices[5]);
    g.add_edge(vertices[2], vertices[4]);
    g.add_edge(vertices[3], vertices[1]);
    g.add_edge(vertices[4], vertices[3]);
    g.add_edge(vertices[5], vertices[5]);


    std::cout <<"\nAdjacency list :\n";
    g.print_adj();

    std::cout <<"\nDFS traversal :\n";
    g.dfs();

    std::cout <<std::endl;
    return 0;
}
