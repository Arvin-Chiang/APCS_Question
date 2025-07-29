#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<string> grid;
vector<vector<bool>> visited;

// 8個方向（包含對角線）
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            !visited[nx][ny] && grid[nx][ny] == '@') {
            dfs(nx, ny);
        }
    }
}

int main() {
    while (cin >> m >> n) {
        if (m == 0) break;

        grid.assign(m, "");
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            cin >> grid[i];
        }

        int oilFields = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '@') {
                    dfs(i, j);
                    oilFields++;
                }
            }
        }

        cout << oilFields << endl;
    }

    return 0;
}
