#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

class Calculator {
public:
    double evaluateRPN(const std::string& expression) {
        std::stack<double> stack;
        std::stringstream ss(expression);
        std::string token;

        while (ss >> token) {
            if (!isOperator(token)) {
                stack.push(std::stod(token));
            }
            else {
                double operand2 = stack.top();
                stack.pop();
                double operand1 = stack.top();
                stack.pop();
                double result = applyOperator(token, operand1, operand2);
                stack.push(result);
            }
        }

        return stack.top();
    }

private:
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    double applyOperator(const std::string& op, double operand1, double operand2) {
        if (op == "+") {
            return operand1 + operand2;
        }
        else if (op == "-") {
            return operand1 - operand2;
        }
        else if (op == "*") {
            return operand1 * operand2;
        }
        else if (op == "/") {
            if (std::fabs(operand2) < 1e-8) {
                std::cerr << "Error: Division by zero\n";
                return NAN; // Not a Number
            }
            return operand1 / operand2;
        }
        return NAN; // Not a Number
    }
};
