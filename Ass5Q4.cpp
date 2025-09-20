//Reverse a Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = NULL; }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, NULL};
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void reverse() {
        Node* prev = NULL, *curr = head, *next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; list.insertAtEnd(x); }
    cout << "Original: "; list.display();
    list.reverse();
    cout << "Reversed: "; list.display();
    return 0;
}
