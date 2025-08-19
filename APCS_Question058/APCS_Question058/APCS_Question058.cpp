#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, a, b, color[100005], cnt[2], ans;
vector <int> v[100005];

bool dfs(int x, int c) {
    color[x] = c;
    cnt[c]++;
    int ret = 1;
    for (auto i : v[x]) {
        if (color[i] == color[x]) return 0;
        else if (color[i] == -1)  ret &= dfs(i, c ^ 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(color, -1, sizeof(color));
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            cnt[0] = 0;
            cnt[1] = 0;
            if (!dfs(i, 0)) {
                cout << 0 << "\n";
                return 0;
            }
            ans += min(cnt[0], cnt[1]);
        }
    }
    cout << ans << "\n";
}