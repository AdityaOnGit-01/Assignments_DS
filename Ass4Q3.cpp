//Interleave first half and second half of Queue
#include <iostream>
using namespace std;
#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
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
    void interleave() {
        int n = size();
        int half = n / 2;
        int firstHalf[MAX];
        for (int i = 0; i < half; i++) firstHalf[i] = dequeue();
        int i = 0;
        while (i < half) {
            enqueue(firstHalf[i]);
            enqueue(dequeue());
            i++;
        }
    }
    void display() {
        if (isEmpty()) { cout << "Queue empty\n"; return; }
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    Queue q;
    int n, x;
    cout << "Enter number of elements (even): ";
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; q.enqueue(x); }
    cout << "Original: "; q.display();
    q.interleave();
    cout << "Interleaved: "; q.display();
    return 0;
}
