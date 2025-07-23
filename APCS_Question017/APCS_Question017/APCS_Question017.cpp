#include <iostream>
#include <stack>
#include <string>
using namespace std;

int countValidBrackets(const string& expr) {
    stack<char> s;
    int pairCount = 0;

    for (char c : expr) {
        if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            if (!s.empty()) {
                s.pop();
                pairCount++;
            }
            else {
               
                return 0;
            }
        }
        else {
         
            return 0;
        }
    }

    
    if (!s.empty()) return 0;

    return pairCount;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;  
        cout << countValidBrackets(line) << endl;
    }
    return 0;
}
