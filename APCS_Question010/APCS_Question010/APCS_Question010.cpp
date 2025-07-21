#include <iostream>
#include <string>
using namespace std;

char rot13(char c) {
    if (c >= 'a' && c <= 'z') {
        return 'a' + (c - 'a' + 13) % 26;
    }
    else if (c >= 'A' && c <= 'Z') {
        return 'A' + (c - 'A' + 13) % 26;
    }
    return c; // 非字母原樣輸出
}

int main() {
    string line;
    while (getline(cin, line)) {
        for (char c : line) {
            cout << rot13(c);
        }
        cout << endl;
    }
    return 0;
}
