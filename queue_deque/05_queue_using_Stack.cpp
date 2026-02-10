#include<iostream>
#include<stack>
using namespace std;

class QueueImpl{
    stack<int> s1;
    stack<int> s2;

    public:

    void push(int data){
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
    }

    void pop(){
        s1.pop();
    }

    void print(){

        stack<int> temp = s1;
        while (!temp.empty())   
        {
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<"\n";
        
    }
};

int main(){
    QueueImpl q;
    q.push(45);
    q.push(67);
    q.push(89);
    q.print();
    q.pop();
    q.print();
}