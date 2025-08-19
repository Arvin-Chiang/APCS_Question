#include <iostream>
#include <vector>
using namespace std;
#define ll long long 
vector <ll> tree[100004];
ll h[100004];
ll dfs(ll node) {
    if (tree[node].size() == 0) {
        h[node] = 0;
        return 0;
    }
    if (h[node] != 0) {
        return h[node];
    }
    ll ch = tree[node].size();
    for (ll i = 0; i < ch; i++) {
        h[node] = max(h[node], dfs(tree[node][i]) + 1);
    }
    return h[node];
}
int main() {
    ll n;
    while (cin >> n) {
        fill(h, h + n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            tree[i].clear();
            ll num;
            cin >> num;
            if (num != 0) {
                for (ll j = 1; j <= num; j++) {
                    ll nn;
                    cin >> nn;
                    tree[i].push_back(nn);
                }
            }
        }
        ll ans = 0;
        ll Node = 1;
        for (ll i = 1; i <= n; i++) {
            ll df = dfs(i);
            ans += df;
            if (df > h[Node]) {
                Node = i;
            }
        }
        cout << Node << endl;
        cout << ans << endl;
    }
}
