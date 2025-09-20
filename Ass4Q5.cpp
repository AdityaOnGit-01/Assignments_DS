//Stacks Using Queues
//(a) using two queues 
#include <iostream>
using namespace std;
#define MAX 100

class Queue {
    int arr[MAX], front, rear;
public:
    Queue() { front = -1; rear = -1; }
    bool isEmpty() { return front == -1; }
    void enqueue(int x) {
        if (rear == MAX - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int x = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return x;
    }
    int size() { return (isEmpty()) ? 0 : rear - front + 1; }
};

class Stack {
    Queue q1, q2;
public:
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) q2.enqueue(q1.dequeue());
        Queue temp = q1; q1 = q2; q2 = temp;
    }
    void pop() {
        if (q1.isEmpty()) { cout << "Stack Empty\n"; return; }
        cout << q1.dequeue() << " popped\n";
    }
    void top() {
        if (q1.isEmpty()) { cout << "Stack Empty\n"; return; }
        cout << "Top: " << q1.dequeue() << "\n"; // temporarily removes
    }
};
//(b) using one queue
class Stack1Q {
    Queue q;
public:
    void push(int x) {
        int s = q.size();
        q.enqueue(x);
        for (int i = 0; i < s; i++) {
            q.enqueue(q.dequeue());
        }
    }
    void pop() {
        if (q.isEmpty()) { cout << "Stack Empty\n"; return; }
        cout << q.dequeue() << " popped\n";
    }
    void top() {
        if (q.isEmpty()) { cout << "Stack Empty\n"; return; }
        cout << "Top: " << q.dequeue() << "\n"; // temporarily removes
    }
};
