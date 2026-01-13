// Insertion after specific data

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertionAtEnd(int val) {
        Node* temp = new Node(val);

        if (head == nullptr) {
            head = temp;
            return;
        }

        Node* t1 = head;
        while (t1->next != nullptr) {
            t1 = t1->next;
        }
        t1->next = temp;
    }
 
    void insertionAtMiddle(int val,int x) {
        Node* temp = new Node(val);

        if (head == nullptr) {
            head = temp;
            return;
        }

        Node* t1 = head;
        while (t1 != nullptr){ 
            // here we donot apply t1.next != nullptr bcs we have to check last node data also 
            if(t1->data == x){
                temp->next = t1->next;
                t1->next = temp;
                return;
            }
            t1 = t1->next;
        }
        cout<<"Value "<<x<<" not found in the list\n";
        delete temp;
    }

    void display() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};


int main() {
    SinglyLinkedList list;
    list.insertionAtEnd(10);
    list.insertionAtEnd(20);
    list.insertionAtEnd(30);
    list.insertionAtMiddle(50,20);
    list.insertionAtMiddle(60,50);
    list.insertionAtMiddle(15,36);
  
    list.display();
    return 0;
}
