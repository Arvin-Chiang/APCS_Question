#include <iostream>
#include <stack>
#include <string>
using namespace std;


int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


bool isRightAssociative(char op) {
    return op == '^';
}

int main() {
    string infix;
    while (cin >> infix) {
        stack<char> stk;
        string postfix = "";

        for (char ch : infix) {
            if (isalpha(ch)) {
                postfix += ch; 
            }
            else if (ch == '(') {
                stk.push(ch);
            }
            else if (ch == ')') {
                while (!stk.empty() && stk.top() != '(') {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.pop();  
            }
            else {
                while (!stk.empty() && stk.top() != '(' &&
                    (precedence(stk.top()) > precedence(ch) ||
                        (precedence(stk.top()) == precedence(ch) && !isRightAssociative(ch)))) {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(ch);
            }
        }

        while (!stk.empty()) {
            postfix += stk.top();
            stk.pop();
        }

        cout << postfix << endl;
    }
    return 0;
}