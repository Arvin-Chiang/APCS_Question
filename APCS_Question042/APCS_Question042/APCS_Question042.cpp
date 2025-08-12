#include <iostream>
#include <cstring>
using namespace std;
//建立一個整數陣列存大數 陣列中的每一個格子代表一個位數

int a[75];

void power(int b) {
    for (int i = 0; i < b; i++) {
        int carry = 0;
        for (int j = 0; j < 75; j++) {
            a[j] = a[j] * 4 + carry;
            carry = a[j] / 10;
            a[j] = a[j] % 10;
        }
    }
}

void subtract_one() {
    int i = 0;
    while (i < 75) {
        if (a[i] > 0) {
            a[i] -= 1;
            break;
        }
        else {
            a[i] = 9;
            i++;
        }
    }
}

void divide(int b) {
    int carry = 0;
    for (int i = 74; i >= 0; i--) {
        a[i] += carry * 10;
        carry = a[i] % b;
        a[i] = a[i] / b;
    }
}

int main() {
    int n;
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        a[0] = 1;
        power(n);
        subtract_one();
        divide(3);
        bool flag = false;
        for (int i = 74; i >= 0; i--) {
            if (a[i] == 0 && !flag) continue;
            flag = true;
            cout << a[i];
        }
        cout << "\n";
    }
}