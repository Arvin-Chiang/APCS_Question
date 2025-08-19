#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 20;
bool prime[2 * MAXN + 1];
int n;
int path[MAXN];
bool used[MAXN];

void sieve() {
    fill(prime, prime + 2 * MAXN + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 2 * MAXN; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 2 * MAXN; j += i) {
                prime[j] = false;
            }
        }
    }
}

void dfs(int pos) {
    if (pos == n) {
        // 檢查最後一個與第一個和是否為質數
        if (prime[path[n - 1] + path[0]]) {
            for (int i = 0; i < n; i++) {
                cout << path[i] << (i == n - 1 ? '\n' : ' ');
            }
        }
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (!used[i] && prime[path[pos - 1] + i]) {
            used[i] = true;
            path[pos] = i;
            dfs(pos + 1);
            used[i] = false;
        }
    }
}

int main() {
    sieve();
    int case_num = 1;
    while (cin >> n) {
        cout << "Case " << case_num++ << ":\n";
        fill(used, used + MAXN, false);
        path[0] = 1;
        used[1] = true;
        dfs(1);
        cout << '\n';
    }
    return 0;
}
