#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data, Node* next=nullptr){
        this->data = data;
        this->next = next;
    }
};

class SinglyLinkedList{
    private:
    Node* head;
    public:
    SinglyLinkedList(){
        head = nullptr;
    }

    void insertionAtBeginnig(int val){
        Node* temp = new Node(val);

        if(head == nullptr){
            head = temp;
            return;
        }

        temp->next = head;
        head = temp;
    }

    void display(){
        Node* curr = head;
        while(curr != nullptr){
            cout<<curr->data<<" -> ";
            curr = curr->next;
        }
        cout<<"NULL";
    }
};

int main(){
    SinglyLinkedList list;
    list.insertionAtBeginnig(23);
    list.insertionAtBeginnig(33);
    list.insertionAtBeginnig(43);
    list.display();
}