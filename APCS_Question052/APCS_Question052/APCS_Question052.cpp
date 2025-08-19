#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    // 讀到 EOF 為止
    while (getline(cin, line)) {
        map<int, int> freq;
        // 統計每個字元出現次數
        for (char c : line) {
            int ascii_val = (int)c;
            // 過濾不符合條件的字元
            if (ascii_val >= 32 && ascii_val <= 128) {
                freq[ascii_val]++;
            }
        }

        // 將 map 轉為 vector 以利排序
        vector<pair<int, int>> freq_vec(freq.begin(), freq.end());

        // 排序規則：出現次數由小到大，如果次數相同，ASCII值由大到小
        sort(freq_vec.begin(), freq_vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first;
            });

        // 輸出結果
        for (auto& p : freq_vec) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}
