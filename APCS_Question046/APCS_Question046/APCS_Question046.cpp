#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100005;
vector<int> tree[MAXN];
bool visited[MAXN];
int maxDist = 0;
int farNode = 0;

void dfs(int node, int dist) {
    visited[node] = true;
    if (dist > maxDist) {
        maxDist = dist;
        farNode = node;
    }

    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, dist + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    // 讀取 parent-child 關係
    for (int i = 0; i < n - 1; ++i) {
        int parent, child;
        cin >> parent >> child;
        tree[parent].push_back(child);
        tree[child].push_back(parent); // 無向邊
    }

    // 第一次 DFS 從任一節點開始，例如節點 0
    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(0, 0); // 找到最遠點 A

    // 第二次 DFS 從 A 出發
    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(farNode, 0); // 找到最遠點 B，maxDist 為 A 到 B 的距離

    cout << maxDist << endl;

    return 0;
}
