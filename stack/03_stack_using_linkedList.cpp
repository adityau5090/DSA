#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int data, Node* next=nullptr){
        this->data = data;
        this->next = next;
    }
};

class StackImpl{
    public:
    Node* top;
    int size=0;

    StackImpl(){
        top = nullptr;
    }

    void push(int data){
        Node * temp = new Node(data);

        temp->next = top;
        top = temp;
        size++;
    }

    void pop(){
        Node* temp = top;
        top = top->next;
        size--;
        delete temp;
    }

    int getTop(){
        return top->data;
    }
    int getSize(){
        return size;
    }

    void print(){
        Node * temp = top;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";   
    }
};

int main(){
    StackImpl s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    cout<<"Top element : "<<s.getTop()<<"\n";
    cout<<"Stack size : "<<s.getSize()<<"\n";
    s.print();
    s.pop();
    s.pop();
    s.print();
    cout<<"Top element : "<<s.getTop()<<"\n";
    cout<<"Stack size : "<<s.getSize()<<"\n";
}