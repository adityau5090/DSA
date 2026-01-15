#include<iostream>
#include<list>
using namespace std;

class Stack{
    public:

    list<int> l;

    int length(){
        return l.size();
    }

    void push(int val){
        l.push_front(val);
    }

    int peek(){
        if(l.size() == 0){
            cout<<"Stack is empty";
            return -1;
        }

        return l.front();
    }

    int pop(){
        if(l.size() == 0){
            cout<<"Stack is empty";
            return -1;
        }
        int top = l.front();
        l.pop_front();
        return top;
    }
};

int main(){
    Stack s;
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<"Length : "<<s.length()<<"\n";
    cout<<"Top element : "<<s.peek()<<"\n";
    cout<<"Deleted element : "<<s.pop()<<"\n";
    cout<<"Length : "<<s.length()<<"\n";
    cout<<"Top element : "<<s.peek()<<"\n";
}