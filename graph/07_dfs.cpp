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

    

    return 0;
}
