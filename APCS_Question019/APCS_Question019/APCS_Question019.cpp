#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool invalid = false;

int parseExpression(const string& expr, int& pos) {
    
    while (pos < expr.length() && expr[pos] == ' ') pos++;

   
    if (isdigit(expr[pos])) {
        int val = 0;
        while (pos < expr.length() && isdigit(expr[pos])) {
            val = val * 10 + (expr[pos] - '0');
            pos++;
        }
        return val;
    }

    
    if (expr[pos] == '(') {
        pos++;  
        int left = parseExpression(expr, pos);
        if (invalid || expr[pos] != ',') { invalid = true; return 0; }
        pos++;  

        int right = parseExpression(expr, pos);
        if (invalid || expr[pos] != ',') { invalid = true; return 0; }
        pos++;  

        if (pos >= expr.length()) { invalid = true; return 0; }
        char op = expr[pos++];
        if (pos >= expr.length() || expr[pos] != ')') { invalid = true; return 0; }
        pos++; 

        switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/':
            if (right == 0) { invalid = true; return 0; }
            return left / right;
        default:
            invalid = true;
            return 0;
        }
    }

    
    invalid = true;
    return 0;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        int pos = 0;
        invalid = false;
        int result = parseExpression(line, pos);
        if (invalid || pos != line.length()) {
            cout << -1 << endl;
        }
        else {
            cout << result << endl;
        }
    }

    return 0;
}
