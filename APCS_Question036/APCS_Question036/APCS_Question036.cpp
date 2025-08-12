#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int MAX = 30001;
    int coins[] = { 1, 5, 10, 25, 50 };
    vector<long long> dp(MAX, 0);
    dp[0] = 1;  

   
    for (int c = 0; c < 5; ++c) 
    {
        for (int i = coins[c]; i < MAX;i++) 
        {
            dp[i] += dp[i - coins[c]];
        }
    }
    int n;
    while (cin >> n) {
        if (dp[n] == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
    }

    return 0;
}
    


