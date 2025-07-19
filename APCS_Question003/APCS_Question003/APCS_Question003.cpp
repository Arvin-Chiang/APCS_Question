#include <iostream>
#include <vector>
using namespace std;

int fib[31];

void precomputeFibonacci() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= 30; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    precomputeFibonacci();
    int n;
    while (cin >> n) {
        cout << fib[n] << endl;
    }

    return 0;
}
