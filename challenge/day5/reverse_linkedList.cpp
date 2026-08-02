#include<iostream>
using namespace std;
    class Node{
        public: 
            int data;
            Node* next;

            Node(int data){
                this->data = data;
                this->next = nullptr;
            }
    };

    class ReverseLinkedList{
        private:
            Node* head;
        public: 
            Node* reverse(Node* head){
                Node* curr = head;
                Node* prev = nullptr;

                while(curr != nullptr){
                    Node* next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                return prev;
            }
    };

    void printList(Node* head) {
                while (head != nullptr) {
                    cout << head->data << " ";
                    head = head->next;
                }
                cout << endl;
    }

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    ReverseLinkedList obj;
    head = obj.reverse(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}