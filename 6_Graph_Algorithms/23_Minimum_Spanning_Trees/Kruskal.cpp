#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>

using std::vector;
using std::set;
using std::map;

class Vertex {
 public:
    char value;

    explicit Vertex(char value) {
        this->value = value;
    }
};

class Edge {
 public:
    Vertex* src, *dst;
    int weight;

    Edge(Vertex* src, Vertex* dst, int weight) {
        this->src = src;
        this->dst = dst;
        this->weight = weight;
    }
};

class Graph {
 public:
    vector<Vertex*> vertices;
    set<Edge*> edges;

    Graph();
    void addVertex(Vertex* src);
    void addEdge(Vertex* src, Vertex *dst, int weight);
    void kruskal();
    static bool comp(Edge*, Edge*);
    int vertexSetIndex(vector<set<Vertex*>> vertexSet, Vertex* v);
};

Graph::Graph() {}

void Graph::addVertex(Vertex* src) {
    vertices.push_back(src);
}

void Graph::addEdge(Vertex* src, Vertex *dst, int weight) {
    edges.insert(new Edge(src, dst, weight));
}

bool Graph::comp(Edge* a, Edge* b) {
    return a->weight < b->weight;
}

int Graph::vertexSetIndex(vector<set<Vertex*>> vertexSets, Vertex *v) {
    for (int i = 0; i < vertexSets.size(); i++) {
        if (vertexSets[i].count(v) != 0) {
            return i;
        }
    }
    return -1;
}

void Graph::kruskal() {
    set<Edge*> minSpanningTreeEdges;

    vector<set<Vertex*>> vertexSet(vertices.size(), set<Vertex*>());
    for (int i = 0; i < vertices.size(); i++) {
        vertexSet[i].insert(vertices[i]);
    }

    vector<Edge*> sortedEdges;
    for (Edge* e : edges) {
        sortedEdges.push_back(e);
    }
    std::sort(sortedEdges.begin(), sortedEdges.end(), comp);

    int srcIndex, dstIndex;
    for (Edge* e : sortedEdges) {
        srcIndex = vertexSetIndex(vertexSet, e->src);
        dstIndex = vertexSetIndex(vertexSet, e->dst);
        if ( srcIndex != dstIndex ) {
            minSpanningTreeEdges.insert(e);
            // vertexSetMap[e->dst] = vertexSetMap[e->src];
            vertexSet[srcIndex].insert(vertexSet[dstIndex].begin(),
                                        vertexSet[dstIndex].end());
            vertexSet.erase(vertexSet.begin() + dstIndex);
        }
    }

    std::cout <<"\nMinimum Spanning Tree Edges :\n\n";
    std::cout <<"\t  Edge  | Weight\n";
    std::cout <<"\t----------------\n";
    for (Edge* e : minSpanningTreeEdges) {
        std::cout <<"\t " <<e->src->value <<" -> " <<e->dst->value
                    <<" | " <<std::setw(3) <<e->weight <<std::endl;
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

    g.kruskal();

    return 0;
}
