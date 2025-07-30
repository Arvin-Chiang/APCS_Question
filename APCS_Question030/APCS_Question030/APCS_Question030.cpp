#include <iostream>
#include <vector>
using namespace std;

vector<int> bestFriend;
vector<bool> visited;

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;
    dfs(bestFriend[node]); 
}

int main() {
    int N;
    cin >> N;
    bestFriend.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < N; ++i) {
        cin >> bestFriend[i];
    }

    int groupCount = 0;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i);  
            groupCount++;
        }
    }

    cout << groupCount << endl;
    return 0;
}
