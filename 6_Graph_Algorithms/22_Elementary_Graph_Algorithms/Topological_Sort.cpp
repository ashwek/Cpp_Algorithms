#include <iostream>
#include <vector>

using namespace std;

class graph{
public:
    int v, count;
    vector<vector<int>> edges;
    vector<int> timestamp[2], state;
    graph(int);
    void add_edge(int, int);
    void print_edges();
    void dfs(vector<int>&);
    void dfs_visit(int, vector<int>&);
    void topological_sort();
};

graph::graph(int ver){
    v = ver;
    edges.resize(ver);
    state.resize(ver);
    timestamp[0].resize(ver);
    timestamp[1].resize(ver);
}

void graph::add_edge(int src, int dst){
    edges[src].push_back(dst);
}

void graph::print_edges(){
    for(int i=0; i<v; i++){
        cout <<(i+1) <<" -> ";
        for(int j=0; j<edges[i].size(); j++)
            cout <<(edges[i][j]+1) <<", ";
        cout<<endl;
    }
}

void graph::dfs(vector<int> &srt){

    for(int i = 0; i < v; i++) state[i] = 0;

    for(int i = 0; i < v; i++){
        if( state[i] == 0 ){
            state[i] = 1;
            dfs_visit(i, srt);
            srt.push_back(i);
        }
    }
}

void graph::dfs_visit(int src, vector<int> &srt){

    for(int i = 0; i < edges[src].size(); i++){
        if( state[edges[src][i]] == 0 ){
            state[edges[src][i]] = 1;
            dfs_visit(edges[src][i], srt);
            srt.push_back(edges[src][i]);
        }
    }
}

void graph::topological_sort(){
    vector<int> srt;
    dfs(srt);
    cout<<"\nTopological sort : ";
    for(int i = srt.size()-1; i >= 0; i--)
        cout <<srt[i] <<", ";
    cout<<endl;
}

int main(){

    graph g(8);

    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 7);
    g.add_edge(2, 5);
    g.add_edge(3, 5);
    g.add_edge(3, 7);
    g.add_edge(4, 7);
    g.add_edge(5, 6);
    g.add_edge(6, 7);

    g.topological_sort();

    cout<<endl;
    return 0;
}
