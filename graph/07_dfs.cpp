                // Depth first search
#include<iostream>
#include<vector>
using namespace std;

class Graph{
    public:
    vector<vector<int>> matrix;
    int size;
    Graph(int vertex){
        size = vertex;
        matrix.resize(vertex, vector<int>(vertex,0));
    }  
    
    void addEdge(int src,int destination){
        if(src >= 0 && src < size && destination >= 0 && destination < size){
            matrix[src][destination] =  1;
            matrix[destination][src] =  1;
        }else{
            cout<<"Invalid Edge!";
            return;
        }
    }

    void dfs(int src){
        vector<int> visited(size,0);
        vector<int> stack;
        stack.push_back(src);

        while (!stack.empty()) {
            int v = stack.back();
            stack.pop_back();

            if (!visited[v]) {
                cout << v << " -> ";
                visited[v] = 1;
            }

            // push neighbors
            for (int i = size - 1; i >= 0; i--) {
                if (matrix[v][i] == 1 && !visited[i]) {
                    stack.push_back(i);
                }
            }
        }
        
    }

    void print(){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";

        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.print();

    cout << "DFS traversal:\n";
    g.dfs(0);

    return 0;
}
