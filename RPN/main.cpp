#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int prioritet(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string& expression) {
    stack<char> operatorStack;
    string postfix = "";

    for (char c : expression) {
        if (isalnum(c))
            postfix += c;
        else if (isOperator(c)) {
            while (!operatorStack.empty() && prioritet(operatorStack.top()) >= prioritet(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
        else if (c == '(')
            operatorStack.push(c);
        else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty())
                operatorStack.pop(); 
            else {
                cout << "Error: Invalid character in expression." << endl;
                return "";
            }
        }
        else {
            cout << "Error: Invalid character in expression." << endl;
            return "";
        }
    }

    while (!operatorStack.empty()) {
        if (operatorStack.top() == '(') {
            cout << "Error: Invalid character in expression." << endl;
            return "";
        }
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& expression) {
    stack<int> operandStack;

    for (char c : expression) {
        if (isalnum(c))
            operandStack.push(c - '0');
        else if (isOperator(c)) {
            if (operandStack.size() < 2) {
                cout << "Error: Invalid postfix expression." << endl;
                return 0;
            }
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (c) {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0) {
                    cout << "Error: Division by zero." << endl;
                    return 0;
                }
                operandStack.push(operand1 / operand2);
                break;
            }
        }
    }

    if (operandStack.size() != 1) {
        cout << "Error: Invalid postfix expression." << endl;
        return 0;
    }

    return operandStack.top();
}

int main() {
    string expression = "2+2*4/2+3";

    string postfix = infixToPostfix(expression);
    
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
        
    cout << "Evaluation result: " << result << endl;
    

    return 0;
}
