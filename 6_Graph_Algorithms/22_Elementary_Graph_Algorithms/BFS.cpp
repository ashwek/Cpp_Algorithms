#include <iostream>
#include <vector>

using namespace std;

class graph{
public:
    int v;
    vector<vector<int>> adj;
    vector<int> distance;
    vector<int> parent;
    vector<int> state;
    graph(int nodes);
    void add_edge(int src, int dst);
    void print_adj();
    void bfs(int src);
};

graph::graph(int nodes = 0){
    v = nodes;
    adj.resize(nodes);
    distance.resize(nodes);
    parent.resize(nodes);
    state.resize(nodes);
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

void graph::bfs(int src){

    vector<int> queue;
    int front = 0;

    for( int i = 0; i < v; i++){
        distance[i] = parent[i] = -1;
        state[i] = 0;
    }

    state[src] = 1;
    distance[src] = 0;
    queue.push_back(src);

    while( front < queue.size() ){
        int temp = queue[front++];
        cout<<temp <<" -> ";
        for( int i = 0; i < adj[temp].size(); i++){
            if( state[adj[temp][i]] == 0 ){
                state[adj[temp][i]] = 1;
                queue.push_back(adj[temp][i]);
                distance[adj[temp][i]] = distance[temp]+1;
                parent[adj[temp][i]] = temp;
            }
        }
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

    cout<<"\nBFS traversal : ";
    g.bfs(1);

    cout<<endl;
    return 0;
}
