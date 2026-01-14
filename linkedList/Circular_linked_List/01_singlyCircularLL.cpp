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

class CircularLL{
    private:
    Node* head;

    public: 
    CircularLL(){
        head = nullptr;
    }
   
    void insertionAtEnd(int val){
        Node* temp = new Node(val);

        if(head == nullptr){
            head = temp;
            temp->next = head;
            return;
        }

        Node* curr = head;
        while(curr->next != head){
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;  // circular LL
    }

    void insertionAtBeginning(int val){
        Node* temp = new Node(val);

        if(head == nullptr){
            head = temp;
            temp->next = head;
            return;
        }

        Node* curr = head;
        while(curr->next != head){
            curr = curr->next;
        }
        temp->next = head;
        head = temp;
        curr->next = head;

    }

    void display(){
        if(head == nullptr){
        cout << "List is empty\n";
        return;
        }
        Node* curr = head;
        do{
            cout<<curr->data<<" -> ";
            curr = curr->next;
        }while(curr != head);
        
        cout<<"(back to head)\n";
    }
};

int main(){
    CircularLL list;
    list.insertionAtEnd(5);
    list.insertionAtEnd(10);
    list.insertionAtBeginning(30);
    list.display();
}