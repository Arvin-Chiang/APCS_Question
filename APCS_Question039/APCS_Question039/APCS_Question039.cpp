#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    vector<int> weight(A);
    vector<int> value(A);

    for (int i = 0; i < A; ++i) {
        cin >> weight[i];
    }

    for (int i = 0; i < A; ++i) {
        cin >> value[i];
    }

    int C;
    cin >> C; 

    vector<int> dp(C + 1, 0);

    for (int i = 0; i < A; ++i) {
        for (int j = C; j >= weight[i]; --j) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[C] << endl;
    return 0;
}
