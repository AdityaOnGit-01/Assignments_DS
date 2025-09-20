//Menu Driven Program for Singly Linked List 
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

    // (a) Insertion at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    // (b) Insertion at end
    void insertAtEnd(int val) {
        Node* newNode = new Node{val, NULL};
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // (c) Insert before a node
    void insertBefore(int key, int val) {
        if (head == NULL) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (temp->next == NULL) {
            cout << "Key not found\n";
            return;
        }
        Node* newNode = new Node{val, temp->next};
        temp->next = newNode;
    }

    // (c) Insert after a node
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (temp == NULL) {
            cout << "Key not found\n";
            return;
        }
        Node* newNode = new Node{val, temp->next};
        temp->next = newNode;
    }

    // (d) Deletion from beginning
    void deleteBeginning() {
        if (head == NULL) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) Deletion from end
    void deleteEnd() {
        if (head == NULL) {
            cout << "List empty\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    // (f) Delete specific node
    void deleteNode(int key) {
        if (head == NULL) return;
        if (head->data == key) {
            Node* t = head;
            head = head->next;
            delete t;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (temp->next == NULL) {
            cout << "Key not found\n";
            return;
        }
        Node* t = temp->next;
        temp->next = temp->next->next;
        delete t;
    }

    // (g) Search for node
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found\n";
    }

    // (h) Display list
    void display() {
        Node* temp = head;
        if (!temp) { cout << "List empty\n"; return; }
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Count occurrences and delete all
    void deleteAllOccurrences(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* t = head;
            head = head->next;
            delete t;
            count++;
        }
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->next->data == key) {
                Node* t = temp->next;
                temp->next = t->next;
                delete t;
                count++;
            } else {
                temp = temp->next;
            }
        }
        cout << "Count: " << count << "\n";
    }

    // Find middle node
    void findMiddle() {
        if (!head) { cout << "List empty\n"; return; }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << "\n";
    }

    // Reverse list
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
};

int main() {
    SinglyLinkedList list;
    int choice, val, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before\n4. Insert After\n";
        cout << "5. Delete Beginning\n6. Delete End\n7. Delete Specific Node\n8. Search\n";
        cout << "9. Display\n10. Delete All Occurrences\n11. Find Middle\n12. Reverse\n13. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
        case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
        case 3: cout << "Enter key and new value: "; cin >> key >> val; list.insertBefore(key, val); break;
        case 4: cout << "Enter key and new value: "; cin >> key >> val; list.insertAfter(key, val); break;
        case 5: list.deleteBeginning(); break;
        case 6: list.deleteEnd(); break;
        case 7: cout << "Enter key: "; cin >> key; list.deleteNode(key); break;
        case 8: cout << "Enter key: "; cin >> key; list.search(key); break;
        case 9: list.display(); break;
        case 10: cout << "Enter key: "; cin >> key; list.deleteAllOccurrences(key); list.display(); break;
        case 11: list.findMiddle(); break;
        case 12: list.reverse(); cout << "List reversed.\n"; list.display(); break;
        case 13: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice\n";
        }
    } while (choice != 13);

    return 0;
}
