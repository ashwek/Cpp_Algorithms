#include <iostream>
#include <vector>
#include <map>
#include <queue>

enum colors {WHITE, GRAY, BLACK};

class Vertex {
 public:
    int value;
    colors vertexColor;
    Vertex *parent;
    int distance;

    explicit Vertex(int value) {
        this->value = value;
    }

    Vertex(int value, colors vertexColor, Vertex *parent, int distance) {
        this->value = value;
        this->vertexColor = vertexColor;
        this->parent = parent;
        this->distance = distance;
    }
};

class Graph {
 public:
    std::map<Vertex*, std::vector<Vertex*>> edges;
    Graph();
    void add_edge(Vertex *src, Vertex *dst);
    void print_adj();
    void bfs(Vertex *src);
    void print_path(Vertex *src, Vertex *dst);
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
        for (Vertex* adj : it.second)
            std::cout <<adj->value <<", ";
        std::cout << std::endl;
    }
}

void Graph::bfs(Vertex *src) {
    std::queue<Vertex*> queue;

    for (auto it : edges) {
        it.first->vertexColor = WHITE;
        it.first->parent = NULL;
        it.first->distance = -1;
    }

    src->vertexColor = WHITE;
    src->parent = NULL;
    src->distance = 0;

    queue.push(src);

    Vertex* temp;
    while ( queue.size() != 0 ) {
        temp = queue.front();
        queue.pop();

        std::cout <<temp->value <<" -> ";
        for (Vertex* adj : edges[temp]) {
            if ( adj->vertexColor == WHITE ) {
                adj->vertexColor = GRAY;
                queue.push(adj);
                adj->distance = temp->distance + 1;
                adj->parent = temp;
            }
        }

        temp->vertexColor = BLACK;
    }
}

void Graph::print_path(Vertex *src, Vertex *dst) {
    if ( src == dst ) {
        std::cout <<src->value;
        return;
    } else if ( dst->parent == NULL ) {
        std::cout <<"No path from src to dst";
    } else {
        print_path(src, dst->parent);
        std::cout <<" -> " <<dst->value;
    }
}


int main() {
    Graph g;

    std::vector<Vertex*> vertices(8);
    for (int i = 0; i < 8; i++) {
        vertices[i] = new Vertex(i);
    }

    g.add_edge(vertices[0], vertices[1]);
    g.add_edge(vertices[0], vertices[2]);
    g.add_edge(vertices[1], vertices[0]);
    g.add_edge(vertices[2], vertices[0]);
    g.add_edge(vertices[2], vertices[3]);
    g.add_edge(vertices[3], vertices[2]);
    g.add_edge(vertices[3], vertices[4]);
    g.add_edge(vertices[3], vertices[5]);
    g.add_edge(vertices[4], vertices[3]);
    g.add_edge(vertices[4], vertices[5]);
    g.add_edge(vertices[4], vertices[6]);
    g.add_edge(vertices[5], vertices[3]);
    g.add_edge(vertices[5], vertices[4]);
    g.add_edge(vertices[5], vertices[6]);
    g.add_edge(vertices[5], vertices[7]);
    g.add_edge(vertices[6], vertices[4]);
    g.add_edge(vertices[6], vertices[5]);
    g.add_edge(vertices[6], vertices[7]);
    g.add_edge(vertices[7], vertices[5]);
    g.add_edge(vertices[7], vertices[6]);

    std::cout <<"\nAdjacency list :\n";
    g.print_adj();

    std::cout <<"\nBFS traversal : ";
    g.bfs(vertices[1]);

    std::cout <<"\n\nPath from 2 to 7:\n"
        <<"(Shortest path in terms of \"Number of edges\"):\n";
    g.print_path(vertices[2], vertices[7]);

    std::cout <<std::endl;
    return 0;
}
