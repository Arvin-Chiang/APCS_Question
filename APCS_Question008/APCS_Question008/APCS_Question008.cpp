#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m;
    cin >> t;

    // 建立田地陣列，初始都沒種樹
    vector<vector<bool>> field(m+1, vector<bool>(n+1, false));

    for (int i = 0; i < t; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 判斷方向
        if (x1 == x2) {  // 直排
            int start = min(y1, y2);
            int end = max(y1, y2);
            for (int y = start; y <= end; y++) {
                field[y][x1] = true;
            }
        } else if (y1 == y2) {  // 橫排
            int start = min(x1, x2);
            int end = max(x1, x2);
            for (int x = start; x <= end; x++) {
                field[y1][x] = true;
            }
        } else if ((x2 - x1) == (y2 - y1)) {  // 左下到右上（斜率+1）
            int length = abs(x2 - x1);
            int dx = (x2 > x1) ? 1 : -1;
            int dy = (y2 > y1) ? 1 : -1;
            for (int j = 0; j <= length; j++) {
                field[y1 + j * dy][x1 + j * dx] = true;
            }
        } else if ((x2 - x1) == -(y2 - y1)) {  // 右下到左上（斜率-1）
            int length = abs(x2 - x1);
            int dx = (x2 > x1) ? 1 : -1;
            int dy = (y2 > y1) ? 1 : -1;
            for (int j = 0; j <= length; j++) {
                field[y1 + j * dy][x1 + j * dx] = true;
            }
        }
    }

    // 計算總共種的樹
    int total = 0;
    for (int y = 1; y <= m; y++) {
        for (int x = 1; x <= n; x++) {
            if (field[y][x]) total++;
        }
    }

    cout << total << endl;

    return 0;
}