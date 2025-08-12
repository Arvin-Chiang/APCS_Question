#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int caseNumber = 1;

    while (true) {
        int N1, N2;
        cin >> N1 >> N2;

        if (N1 == 0 && N2 == 0) break;

        vector<int> A(N1), B(N2);
        for (int i = 0; i < N1; ++i) cin >> A[i];
        for (int i = 0; i < N2; ++i) cin >> B[i];

        
        vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1, 0));

        for (int i = 1; i <= N1; ++i) {
            for (int j = 1; j <= N2; ++j) {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        
        cout << "Twin Towers #" << caseNumber++ << endl;
        cout << "Number of Tiles : " << dp[N1][N2] << endl;
        cout << endl;
    }

    return 0;
}
