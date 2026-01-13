// Delete the node at given index

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data, Node *prev = nullptr, Node *next = nullptr)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insertionAtEnd(int val)
    {
        Node* temp = new Node(val);

        if (head == nullptr)
        {
            head = temp;
            return;
        }

        Node* curr = head;

        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }

    void deleteAtIndex(int index)
    {
        if (head == nullptr)
        {
            cout<<"List is empty!";
            return;
        }

        if(index == 0){
            Node* del = head;

            // if only one node
            if(head->next == nullptr){
                head = nullptr;
            }else{
                head = head->next;
                head->prev = nullptr;
            }
            cout<<"Value "<<del->data<<" is deleted from index "<<index<<"\n";
            delete del;
            return;
        }

        Node *curr = head;
        int i=0;
        while (curr != nullptr && i < index)
        {
            curr = curr->next;
            i++;
        }
        if(curr == nullptr){
            cout<<"Index "<<index<<" not found\n";
            return;
        }

        Node* del = curr;

        // last node
        if(curr->next == nullptr){
            curr->prev->next = nullptr;
        }
        // delete middle nodes
        else{
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        cout<<"Value "<<del->data<<" is deleted from index "<<index<<"\n";
        delete del;
        return;
    }

    void display()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " <--> ";
            curr = curr->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    DoublyLinkedList list;
    list.insertionAtEnd(10);
    list.insertionAtEnd(15);
    list.insertionAtEnd(25);
    list.insertionAtEnd(30);
    list.deleteAtIndex(0);
    list.deleteAtIndex(2);
    list.display();
}