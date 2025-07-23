#include <iostream>
#include <stack>
#include <string>
using namespace std;

int applyOperation(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '%': return a % b;
    }
    return 0;
}

int main() {
    string expr;
    while (cin >> expr) {
        stack<int> stk;
        for (char ch : expr) {
            if (isdigit(ch)) {
                stk.push(ch - '0');
            }
            else {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int result = applyOperation(a, b, ch);
                stk.push(result);
            }
        }
        cout << stk.top() << endl;
    }
    return 0;
}
