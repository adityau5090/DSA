#include<iostream>
#include<list>
using namespace std;

// A Deque allows insertion and deletion at both ends.
class Deque{
    public:
    list<int> dq;

    void length(){
        cout<<"Length : "<<dq.size()<<"\n";
    }

    void insertAtEnd(int val){
        dq.push_back(val);
        cout<<val<<" inserted\n";
    }

    void insertAtBeginning(int val){
        dq.push_front(val);
        cout<<val<<" inserted\n";
    }

    void deleteAtEnd(){
        if(dq.empty()){
            cout << "Deque is empty\n";
            return;
        }
        int del = dq.back();
        dq.pop_back();
        cout<<del<<" is deleted\n";
    }

    void deleteAtBeginning(){
        if(dq.empty()){
            cout << "Deque is empty\n";
            return;
        }
        int del = dq.front();
        dq.pop_front();
        cout<<del<<" is deleted\n";
    }
};

int main(){
    Deque dq;
    dq.insertAtEnd(20);
    dq.insertAtEnd(40);
    dq.insertAtBeginning(10);
    dq.insertAtBeginning(5);
    dq.length();
    dq.deleteAtBeginning();
    dq.deleteAtEnd();
    dq.deleteAtEnd();
    dq.length();
}