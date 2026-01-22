#include<iostream>
#include<vector>
using namespace std;

class DirectedGraph{
    private: 
    vector<vector<int>> adjlist;
    vector<int> vertices;

    int findVertex(int v){
        for(int i=0; i<vertices.size(); i++){
            if(vertices[i] == v)
                return i;
        }
        return -1;
    }

    void addVertex(int v){
        if(findVertex(v) == -1){
            vertices.push_back(v);
            adjlist.push_back(vector<int>());
        }
    }

    public:
    void addEdge(int src,int dest){
        addVertex(src);
        addVertex(dest);

        int srcIndex = findVertex(src);

        adjlist[srcIndex].push_back(dest);
    }

    void printGraph(){
        for(int i=0; i<vertices.size(); i++){
            cout<<vertices[i]<<" -> ";
            for(int edge: adjlist[i]){
                cout<<edge<<",";
            }
            cout<<"\n";
        }
    }
};

int main(){
    DirectedGraph g;
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(3,1);
    g.addEdge(1,3);

    g.printGraph();
}