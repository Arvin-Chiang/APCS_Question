#include <iostream>
using namespace std;
int main() {
    int N = 1;
    int a[75];
    
    int num = 0;
    cin >> N;
    for (int i = 0; i < 75; i++) {
        a[i] = 0;
    }
    a[0] = a[0] = 1;
    if(N > 1){
        for (int b = 0; b < N-1; b++) {
            a[0] = a[0] + 4 ^ b;
        }
    }

    
    cout << a[0] << endl;
    return 0;
}