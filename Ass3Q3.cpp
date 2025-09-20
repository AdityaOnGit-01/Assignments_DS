//Write a program that checks if an expression has balanced parentheses.

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
            return '\0'; // return null char if empty
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

// Function to check if two brackets match
bool match(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool checkBalanced(char expr[]) {
    Stack s;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false;  // closing bracket without opening
            }
            char topChar = s.pop();
            if (!match(topChar, ch)) {
                return false;  // mismatch
            }
        }
    }

    return s.isEmpty();  // must be empty if balanced
}

int main() {
    char expr[MAX];
    cout << "Enter expression: ";
    cin >> expr;  // input expression without spaces

    if (checkBalanced(expr)) {
        cout << "Expression is Balanced." << endl;
    } else {
        cout << "Expression is NOT Balanced." << endl;
    }

    return 0;
}
