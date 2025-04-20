#include <iostream>
#include <vector>
#include <stack>

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

    void DFS(int start){
        std::vector<bool> visited (V,false); 
        std::stack<int> s;

        s.push(start);

        while(s.empty()==false){
            int node=s.top();
            s.pop();

            if(visited[node]==false){
                visited[node]=true;
                std::cout<<node<<" ";
            }

            for(int neighbor: adj[node]){
                if(visited[neighbor]==false){
                    s.push(neighbor);
                }
            }
        }
    }
};

int main(){

    int V=8;
    Graph graph(V);

    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,3);
    graph.add_edge(1,4);
    graph.add_edge(3,5);
    graph.add_edge(2,6);
    graph.add_edge(6,7);

    std::cout<<"DFS\nStarting from vertex 0: ";
    graph.DFS(0);
    return 0;
}