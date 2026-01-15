#include<iostream>
#include<list>
using namespace std;

class Stack{
    public:
    list<int> l;

    void length(){
        cout<<"Length : "<<l.size()<<"\n";
    }

    void push(int val){
        l.push_back(val);
        cout<<val<<" inserted in stack\n";
    }

    void pop(){
        if(l.size() == 0){
            cout<<"Stack is empty\n";
            return;
        }
        int del = l.back();
        l.pop_back();
        cout<<del<<" deleted from stack\n";
    }

    void peek(){
        if(l.size() == 0){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<"Peek of stack is :"<<l.back()<<"\n";
    }

};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.length();
    s.peek();
    s.pop();
    s.peek();
}