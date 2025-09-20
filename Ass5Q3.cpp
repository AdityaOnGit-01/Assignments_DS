//Find Middle of Linked List
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

    void findMiddle() {
        if (!head) { cout << "List empty\n"; return; }
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << "\n";
    }
};

int main() {
    SinglyLinkedList list;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; list.insertAtEnd(x); }
    list.findMiddle();
    return 0;
}
