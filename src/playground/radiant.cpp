#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cmath>
#include <stdexcept>
#include <vector>

using namespace std;

double performOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        default: throw runtime_error("Invalid operator");
    }
}

void evaluatePostfix(const string& expression) {
    istringstream iss(expression);
    string token;
    stack<double> st;
    
    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Token is an operand (number)
            try {
                st.push(stod(token));
            } catch (invalid_argument&) {
                cout << "Invalid operand" << endl;
                return;
            }
        } else if (token.size() == 1 && string("+-*/").find(token) != string::npos) {
            // Token is an operator
            if (st.size() < 2) {
                cout << "Not enough operands" << endl;
                return;
            }
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            try {
                st.push(performOperation(a, b, token[0]));
            } catch (runtime_error& e) {
                cout << e.what() << endl;
                return;
            }
        } else {
            cout << "Invalid operator" << endl;
            return;
        }
    }

    if (st.size() != 1) {
        cout << (st.empty() ? "Not enough operands" : "Too many operands") << endl;
    } else {
        cout << st.top() << endl;
    }
}

int main() {
    string expression;
    while (true) {
        cout << "Enter postfix expression (or 'exit' to quit): ";
        getline(cin, expression);
        if (expression == "exit") break;
        evaluatePostfix(expression);
    }
    return 0;
}
