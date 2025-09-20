//Count and Delete all Occurances
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

    void deleteAllOccurrences(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* t = head; head = head->next; delete t; count++;
        }
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->next->data == key) {
                Node* t = temp->next;
                temp->next = t->next;
                delete t; count++;
            } else temp = temp->next;
        }
        cout << "Count: " << count << "\n";
    }

    void display() {
        Node* temp = head;
        while (temp) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int n, x, key;
    cout << "Enter number of elements: ";
}