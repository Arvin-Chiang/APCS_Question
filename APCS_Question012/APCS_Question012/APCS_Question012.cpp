#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    string s;
    char target;
    getline(cin, s);   // 讀取長字串
    cin >> target;     // 讀取指定字母

    // 不區分大小寫，先把 target 轉成小寫
    target = tolower(target);

    vector<int> positions;

    // 尋找指定字母位置，並紀錄
    for (int i = 0; i < (int)s.size(); ++i) {
        if (tolower(s[i]) == target) {
            positions.push_back(i);
        }
    }

    // 計算間隔距離
    for (int i = 1; i < (int)positions.size(); ++i) {
        cout << positions[i] - positions[i - 1];
        if (i != (int)positions.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
