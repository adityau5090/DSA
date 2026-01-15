#include<iostream>
#include<list>
using namespace std;

// FIFO PRINCIPLE
class Queue{
    public:
    list<int> q;

    void length(){
        cout<<"Length : "<<q.size()<<"\n";
    }

   void  insert(int val){
        q.push_back(val);
        cout<<val<<" inserted\n";
   }

   void del(){
    if(q.size() == 0){
        cout<<"Queue is empty\n";
        return;
    }
    int d = q.front();
    q.pop_front();
    cout<<d<<" is deleted from queue\n";
   }

};

int main(){
    Queue q;
    q.insert(20);
    q.insert(50);
    q.insert(80);
    q.length();
    q.del();
    q.length();
}