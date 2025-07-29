#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canReach(int N, vector<vector<int>>& graph, int A, int B) {
    vector<bool> visited(N + 1, false);
    queue<int> q;
    q.push(A);
    visited[A] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == B) return true;

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<vector<int>> graph(N + 1);
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        int A, B;
        cin >> A >> B;

        if (canReach(N, graph, A, B)) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}
