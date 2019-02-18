#include <iostream>
#include <vector>

using namespace std;

class graph{
public:
    int v, count;
    vector<vector<int>> adj;
    vector<int> distance, parent, state, timestamp[2];
    graph(int nodes);
    void add_edge(int src, int dst);
    void print_adj();
    void dfs();
    void dfs_visit(int src);
    int print_path(int src, int dst);
};

graph::graph(int nodes = 0){
    v = nodes;
    adj.resize(nodes);
    distance.resize(nodes);
    parent.resize(nodes);
    state.resize(nodes);
    timestamp[0].resize(nodes);
    timestamp[1].resize(nodes);
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

void pr_vec(vector<int> queue){
    for(int i = 0; i<queue.size(); i++)
        cout<<i <<" -> " <<queue[i] <<endl;
}

void graph::dfs_visit(int src){

    for(int i = 0; i < adj[src].size(); i++){
        if( state[adj[src][i]] == 0 ){
            state[adj[src][i]] = 1;
            cout<<adj[src][i] <<" -> ";
            distance[adj[src][i]] = distance[src]+1;
            parent[adj[src][i]] = src;
            timestamp[0][adj[src][i]] = count++;
            dfs_visit(adj[src][i]);
            timestamp[1][adj[src][i]] = count++;
        }
    }
}

void graph::dfs(){

    for(int i=0; i<v; i++){
        state[i] = 0;
        parent[i] = distance[i] = timestamp[0][i] = timestamp[1][i] = -1;
    }

    count = 1;
    for(int i = 0; i < v; i++){
        if( state[i] == 0){
            state[i] = 1;
            timestamp[0][i] = count++;
            cout <<i <<" -> ";
            dfs_visit(i);
            timestamp[1][i] = count++;
            cout<<endl;
        }
    }
}

int graph::print_path(int src, int dst){
    if( dst == src )
        cout<<src<<", ";
    else if( parent[dst] == -1 )
        return 0;
    else if(print_path(src, parent[dst] ))
        cout<<dst <<", ";
    else
        return 0;
    return 1;
}

int main(){

    graph g(6);

    /*g.add_edge(0, 1);
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
    g.add_edge(7, 6);*/

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    g.add_edge(4, 3);
    g.add_edge(4, 5);
    g.add_edge(5, 5);

    /*g.add_edge(1, 0);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 5);
    g.add_edge(4, 3);
    g.add_edge(4, 6);
    g.add_edge(5, 4);
    g.add_edge(5, 6);
    g.add_edge(5, 7);
    g.add_edge(6, 7);
    g.add_edge(7, 5);*/

    //g.print_adj();

    cout<<"\nDFS traversal : ";
    g.dfs();

    cout<<"\nParent :\n";
    pr_vec(g.parent);

    cout<<"\nDistance :\n";
    pr_vec(g.distance);

    cout<<"\nPrev Time :\n";
    pr_vec(g.timestamp[0]);

    cout<<"\nPost Time :\n";
    pr_vec(g.timestamp[1]);

    g.print_path(1, 0);

    cout<<endl;
    return 0;
}
