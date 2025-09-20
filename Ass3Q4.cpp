//Write a program to convert an Infix expression into a Postfix expression.

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
            return '\0';  // return null char if empty
        } else {
            return arr[top--];
        }
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

// Function to define precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0') {
        ch = infix[i];

        // If operand, add to postfix
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop(); // remove '('
        }
        // If operator
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix[j++] = s.pop();
            }
            s.push(ch);
        }
        i++;
    }

    // Pop all remaining operators
    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0'; // null character found terminate
}

int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter infix expression: ";
    cin >> infix;   // input without spaces

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
