
#include<iostream>
using namespace std;

const int N = 8;
int ans = 0;
int sum = 0;
int value[N][N] = { 0 };
int column[N] = { 0 };        // 同行是否有皇后 ↑↓
int slash[2 * N] = { 0 };     // 右上至左下是否有皇后？↙
int backSlash[2 * N] = { 0 }; // 左上至右下是否有皇后 ↘
int queens[N] = { 0 };

//檢查這一格是否可以放下皇后，可以回傳true
int isVisitable(int y, int x) {
    return !(column[x] || slash[x + y] || backSlash[x - y + N]);
}

//印出棋盤結果
void print() {
    int x, y;
    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            cout << (queens[y] == x ? "Q" : "x");
        }
        cout << endl;
    }
    cout << endl;
}

//找尋可以放皇后的格子
void dfs(int y) {//i是第幾隻皇后，同時也是第幾列

    if (y >= N) { //已放好第8隻皇后
        if (sum > ans) {
            ans = sum;
        }
        //print(); //印出正解
    }
    else {
        int x;
        for (x = 0; x < N; x++) {

            if (isVisitable(y, x)) { //這格能不能放皇后
                sum += value[y][x];
                queens[y] = x;
                column[x] = slash[x + y] = backSlash[x - y + N] = 1; //將皇后放下去，所以不能放的地方增加了
                dfs(y + 1); //往下一列，繼續尋找皇后的擺放點
                sum -= value[y][x];
                column[x] = slash[x + y] = backSlash[x - y + N] = 0; //將皇后拿起來，所以不能放的地方減少了
            }

        }
    }
}

int main(void) {
    int k;
    while (cin >> k) {
        while (k--) {
            ans = sum = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cin >> value[i][j];
                }
            }
            dfs(0); //0代表放了幾隻皇后，每一行都會有一隻，且只能有一隻
            cout << ans << endl;
        }
    }
    return 0;
}