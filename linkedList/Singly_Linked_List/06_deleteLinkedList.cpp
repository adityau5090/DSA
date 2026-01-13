// Delete the specific data

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void insertionAtEnd(int val)
    {
        Node *temp = new Node(val);

        if (head == nullptr)
        {
            head = temp;
            return;
        }

        Node *t1 = head;
        while (t1->next != nullptr)
        {
            t1 = t1->next;
        }
        t1->next = temp;
    }

    void deletion(int x)
    {

        if (head == nullptr){
            cout << "List is empty\n";
            return;
        }

        // corner case for delete first element
        if (head->data == x)
        {
            Node* temp = head;
            head = head->next;
            cout<<temp->data<<" deleted successfully\n";
            return;
        }

        Node *prev = head;
        Node* curr = head->next;

        while (curr != nullptr)
        {
            if (curr->data == x)
            {
                prev->next = curr->next;
                cout<<curr->data<<" deleted successfully\n";
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Value " << x << " not found in the list\n";
    }

    void display()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    SinglyLinkedList list;
    list.insertionAtEnd(10);
    list.insertionAtEnd(20);
    list.insertionAtEnd(30);
    list.deletion(10);
    list.deletion(30);
    list.display();
    return 0;
}
