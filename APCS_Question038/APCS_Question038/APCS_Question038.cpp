#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m;
        cin >> m;
        vector<int> coins(m);
        int total = 0;

        for (int i = 0; i < m; ++i) {
            cin >> coins[i];
            total += coins[i];
        }

        int half = total / 2;
        vector<bool> dp(half + 1, false);
        dp[0] = true;

        for (int coin : coins) {
            for (int j = half; j >= coin; --j) {
                dp[j] = dp[j] || dp[j - coin];
            }
        }

        int best = 0;
        for (int i = half; i >= 0; --i) {
            if (dp[i]) {
                best = i;
                break;
            }
        }

        int other = total - best;
        cout << abs(total - best) << endl;
    }

    return 0;
}
