#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool isChild[MAXN]; 
int maxDist = 0, farthestNode = 0;


void dfs(int node, int parent, int dist) {
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node, dist + 1);
        }
    }
}

int main() {
    int N;
    while (cin >> N) {
        
        for (int i = 0; i < N; ++i) {
            adj[i].clear();
        }
        memset(isChild, 0, sizeof(bool) * N);

        for (int i = 0; i < N - 1; ++i) {
            int parent, child;
            cin >> parent >> child;
            adj[parent].push_back(child);
            isChild[child] = true;
        }

       
        int root = 0;
        for (int i = 0; i < N; ++i) {
            if (!isChild[i]) {
                root = i;
                break;
            }
        }

        
        maxDist = 0;
        dfs(root, -1, 0);

       
        maxDist = 0;
        dfs(farthestNode, -1, 0);

        cout << maxDist << endl;
    }

    return 0;
}
