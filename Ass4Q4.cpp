//First Non Repeating Charactert in string using Queue
#include <iostream>
using namespace std;
#define MAX 256

class Queue {
    char arr[1000];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }
    bool isEmpty() { return front == -1; }
    void enqueue(char x) {
        if (rear == 999) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue() {
        if (isEmpty()) return;
        if (front == rear) front = rear = -1;
        else front++;
    }
    char frontVal() { return arr[front]; }
};

int main() {
    char str[100];
    cout << "Enter string: ";
    cin >> str;

    int freq[MAX] = {0};
    Queue q;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        freq[ch]++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.frontVal()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty()) cout << -1 << " ";
        else cout << q.frontVal() << " ";
    }
    cout << "\n";
    return 0;
}
