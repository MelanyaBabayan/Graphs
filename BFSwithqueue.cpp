#include <iostream>
#include <vector>
#include <queue>

class Graph{
public:
    int V;
    std::vector<std::vector<int>> adj;

    Graph(int v){
        V=v;
        adj.resize(V);
    }

    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start){
        std::vector<bool> visited(V,false);
        std::queue<int> q;

        q.push(start);

        while(q.empty()==false){
            int node=q.front();
            q.pop();
            std::cout<<node<<" ";

            for(int neighbor : adj[node]){
                if(visited[neighbor]==false){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout<<std::endl;
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
    graph.add_edge(5,6);

    std::cout<<"BFS\nStarting from 0: ";
    graph.BFS(0);
    return 0;
}