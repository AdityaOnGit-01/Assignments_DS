//Write a program for the evaluation of a Postfix expression.

#include <iostream>
#include <cmath>  
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int evaluatePostfix(char postfix[]) {
    Stack s;
    int i = 0;

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        // If operand (digit), push to stack
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');  // convert char to int
        }
        // If operator, pop two operands and apply
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
                default: 
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }
            s.push(result);
        }
        i++;
    }

    return s.pop();
}

int main() {
    char postfix[MAX];

    cout << "Enter postfix expression: ";
    cin >> postfix;   // input without spaces

    int result = evaluatePostfix(postfix);

    cout << "Result = " << result << endl;

    return 0;
}
