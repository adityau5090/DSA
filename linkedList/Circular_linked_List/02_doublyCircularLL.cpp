#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data, Node* prev=nullptr, Node* next=nullptr){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

class CircularLL{
    private:
    Node* head;
    public:
    CircularLL(){
        head = nullptr;
    }

    void insertAtEnd(int val){
        Node* temp = new Node(val);

        if(head == nullptr){
            head = temp;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* curr = head;
        while(curr->next != head){
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
        temp->next = head;
        head->prev = temp;
    }

    void insertAtBeginning(int val){
        Node* temp = new Node(val);

        if(head == nullptr){
            head= temp;
            head->next = head;
            head->prev = head;
            return;
        }

        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head = temp;
    }

    void insertAtIndex(int val,int index){
        Node* temp = new Node(val);

        if(head == nullptr){
            head = temp;
            head->next = head;
            head->prev = head;
            return;
        }

        // insert at beginning
        if(index == 0){
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
            head = temp;
            return;
        }

        Node* curr = head;
        int i=0;

        while(curr->next != head && i < index){
            curr = curr->next;
            i++;
        }
        temp->next = curr;
        temp->prev = curr->prev;
        curr->prev->next = temp;
        curr->prev = temp;
        
    }
    
    void deleteAtIndex(int index){

        if(head == nullptr){
            cout<<"List is empty";
            return;
        }

        if(index == 0){

            // delete single element
            if(head->next == head){
                Node* del = head;
                head = nullptr;
                cout<<"Value "<<del->data<<" at index 0 deleted\n";
                delete del;
                return;
            }
            Node* del = head;
            head->next->prev = head->prev;
            head->prev->next = head->next;
            head = head->next;
            cout<<"Value "<<del->data<<" at index 0 deleted\n";
            delete del;
            return;
        }

        Node* curr = head;
        int i=0;

        while(curr->next != head && i < index){
            curr = curr->next;
            i++;
        }

        if(i != index){
            cout<<"Index out of range";
            return;
        }

        Node* del = curr;
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        cout<<"Value "<<del->data<<" at index "<<i<<" deleted\n";
        delete del;
        return;

    }

    void display(){
        Node* curr = head;
        do{
            cout<<curr->data<<" <-> ";
            curr = curr->next;
        }while(curr != head);
        cout<<"(HEAD)\n";
    }
};

int main(){
    CircularLL list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);
    list.insertAtIndex(15,2);
    list.insertAtIndex(25,4);
    list.deleteAtIndex(5);
    list.display();
}