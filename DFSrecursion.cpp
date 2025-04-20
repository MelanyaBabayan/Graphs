#include <iostream>
#include <vector>

class Graph{
    public:
    int V; //num of verticles
    std::vector<std::vector<int>> adj;

    Graph(int verticles){
        V=verticles;
        adj.resize(V);
    }

    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start, std::vector<bool>& visited){
        visited[start]=true;
        std::cout<<start<<" ";

        for(int neighbor:adj[start]){
            if(visited[neighbor]==false){
                DFS(neighbor, visited);
            }
        }
    }
};

int main(){
    int V=7;
    Graph graph(V);

    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,3);
    graph.add_edge(1,4);
    graph.add_edge(2,5);
    graph.add_edge(2,6);

    std::vector<bool> visited(V, false);

    std::cout<<"DFS\nStarting from 0: ";
    graph.DFS(0,visited);

    return 0;
}