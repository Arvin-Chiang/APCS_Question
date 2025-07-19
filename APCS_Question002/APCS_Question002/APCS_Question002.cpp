
#include <iostream>
#include <cmath>
using namespace std;


bool isAverageEven(int num, int k) {
    int sum = 0, digits = 0;
    int original = num;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
        digits++;
    }
    if (digits != k) return false;
    return ((sum % k) == 0) && (((sum / k) % 2) == 0);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;

        int start = pow(10, k - 1);       
        int end = pow(10, k) - 1;        
        int root = sqrt(start);
        if (root * root < start) root++;  

        while (true) {
            int square = root * root;
            if (square > end) break;

            if (isAverageEven(square, k)) {
                cout << square << endl;
                break;
            }

            root++;
        }
    }

    return 0;
}


