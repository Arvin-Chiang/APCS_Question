#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> drinks(N);
    for (int i = 0; i < N; ++i) {
        cin >> drinks[i];
    }

    // 儲存每位員工的「下次可服務時間」，初始為 0
    priority_queue<long long, vector<long long>, greater<long long>> workers;

    // 初始化 M 位員工，每人都是空閒的（可用時間 = 0）
    for (int i = 0; i < M && i < N; ++i) {
        workers.push(drinks[i]); // 前 M 個人直接分給員工
    }

    // 接著從第 M+1 人開始處理
    for (int i = M; i < N; ++i) {
        long long available_time = workers.top(); workers.pop();
        long long new_time = available_time + drinks[i];
        workers.push(new_time);
    }

    // 所有顧客完成時間 = 所有員工最晚完成時間
    long long result = 0;
    while (!workers.empty()) {
        result = workers.top();
        workers.pop();
    }

    cout << result << endl;
    return 0;
}
