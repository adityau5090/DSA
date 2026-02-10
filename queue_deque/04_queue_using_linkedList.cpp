#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data, Node* next =nullptr){
        this->data = data;
        this->next = next;
    }
};

class QueueImpl{
    int size=0;
    Node* start;
    Node* end;

    public:
    QueueImpl(){
        start = nullptr;
        end = nullptr;
    }

    void push(int data){
        Node* temp = new Node(data);

        if(start == nullptr){
            start=temp;
            end=temp;
        }else{
            end->next = temp;
            end = temp;
        }
        size++;
    }

    void pop(){

        if(start == nullptr){
            return;
        }

        Node* temp = start;
        start = start->next;
        size--;
        delete temp;
    }

    int getTop(){
        if(start == nullptr){
            return -1;
        }
        return start->data;
    }

    int getSize(){
        if(start == nullptr){
            return -1;
        }
        return size;
    }

    void print() {
        Node* temp = start;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
};

int main(){
    QueueImpl q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    q.print();
    cout<<"Top element : "<<q.getTop()<<"\n";
    cout<<"Size : "<<q.getSize()<<"\n";
    q.pop();
    q.print();
}