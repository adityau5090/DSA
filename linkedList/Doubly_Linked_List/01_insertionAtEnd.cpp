#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data, Node* prev=nullptr,  Node* next=nullptr){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

class DoublyLinkedList{
    private:
    Node* head;

    public:
    DoublyLinkedList(){
        head = nullptr;
    }

    void insertionAtEnd(int val){
        Node* temp = new Node(val);

        if(head == nullptr){
            head = temp;
            return;
        }

        Node* curr = head;

        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }

    void display(){
        Node* curr = head;
        while(curr != nullptr){
            cout<<curr->data<<" <--> ";
            curr = curr->next;
        }

        cout<<"NULL\n";
    }
};

int main(){
    DoublyLinkedList list;
    list.insertionAtEnd(5);
    list.insertionAtEnd(10);
    list.insertionAtEnd(15);
    list.insertionAtEnd(20);
    list.display();
}