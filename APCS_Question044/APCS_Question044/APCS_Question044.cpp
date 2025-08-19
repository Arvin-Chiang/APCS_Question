#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int simulateBall(int D, int I) {
    int node = 1; // 從 root 開始
    int size = (1 << D); // 樹最大節點編號 = 2^D
    vector<bool> tree(size, false); // 初始皆為 false，向左走

    for (int i = 0; i < I; ++i) {
        int cur = 1;
        while (cur < size / 2) { // 不是葉節點就繼續
            if (!tree[cur]) {
                tree[cur] = true;
                cur *= 2; // 向左走
            }
            else {
                tree[cur] = false;
                cur = cur * 2 + 1; // 向右走
            }
        }
        if (i == I - 1) {
            return cur; // 第 I 顆球的最終落點
        }
    }
    return -1; // 不會發生
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int D, I;
        cin >> D >> I;
        cout << simulateBall(D, I) << endl;
    }
    return 0;
}
