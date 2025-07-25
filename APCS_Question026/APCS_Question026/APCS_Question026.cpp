#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 10005;
vector<int> tree[MAXN];
bool isChild[MAXN];
int totalHeight = 0;

int dfs(int node) {
    int maxH = 0;
    for (int child : tree[node]) {
        maxH = max(maxH, dfs(child) + 1);
    }
    totalHeight += maxH;
    return maxH;
}

int main() {
    int n;
    cin >> n;

    
    for (int i = 1; i <= n; ++i) {
        tree[i].clear();
    }
    memset(isChild, false, sizeof(isChild));
    totalHeight = 0;

    for (int i = 0; i < n; ++i) {
        int parent, k;
        cin >> parent >> k;
        for (int j = 0; j < k; ++j) {
            int child;
            cin >> child;
            tree[parent].push_back(child);
            isChild[child] = true;
        }
    }

    
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (!isChild[i]) {
            root = i;
            break;
        }
    }

    dfs(root);
    cout << root << endl;
    cout << totalHeight << endl;

    return 0;
}
