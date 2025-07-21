#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string X;
    cin >> X;

    int A = 0, B = 0;

    for (size_t i = 0; i < X.length(); ++i) {
        int digit = X[i] - '0';

        if ((i + 1) % 2 == 1) {
            A += digit; // 奇數位（1-based）
        }
        else {
            B += digit; // 偶數位
        }
    }

    cout << abs(A - B) << endl;

    return 0;
}
