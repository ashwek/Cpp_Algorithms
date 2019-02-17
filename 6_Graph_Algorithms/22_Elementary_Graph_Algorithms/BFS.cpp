#include <iostream>
#include <vector>

using namespace std;

class graph{
public:
    int v;
    vector<vector<int>> adj;
    vector<int> distance;
    vector<int> parent;
    vector<int> color;
    graph(int nodes);
    void add_edge(int src, int dst);
    void print_adj();
};

graph::graph(int nodes = 0){
    v = nodes;
    adj.resize(nodes);
    distance.resize(nodes);
    parent.resize(nodes);
    color.resize(nodes);
}

void graph::add_edge(int src, int dst){
    adj[src].push_back(dst);
}

void graph::print_adj(){
    for( int i = 0; i < v; i++){
        cout<<i <<" -> ";
        for( int j = 0; j < adj[i].size(); j++)
            cout<<adj[i][j] <<", ";
        cout<<endl;
    }
}

int main(){

    graph g(8);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 0);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 2);
    g.add_edge(3, 4);
    g.add_edge(3, 5);
    g.add_edge(4, 3);
    g.add_edge(4, 5);
    g.add_edge(4, 6);
    g.add_edge(5, 3);
    g.add_edge(5, 4);
    g.add_edge(5, 6);
    g.add_edge(5, 7);
    g.add_edge(6, 4);
    g.add_edge(6, 5);
    g.add_edge(6, 7);
    g.add_edge(7, 5);
    g.add_edge(7, 6);

    g.print_adj();



    cout<<endl;
    return 0;
}
