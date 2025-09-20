//Given a string, reverse it using STACK. For example “DataStructure” should be output as
//“erutcurtSataD.”

#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = x;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return '\0'; // null character returned if empty
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    char str[MAX];
    Stack s;

    cout << "Enter a string: ";
    cin >> str;  // Taking Input

    // Pushing all characters into stack
    for (int i = 0; str[i] != '\0'; i++) {
        s.push(str[i]);
    }

    // Pop all characters to reverse
    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}
