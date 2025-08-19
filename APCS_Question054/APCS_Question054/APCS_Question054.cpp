#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

// 判斷兩個數字是否包含的數字互不重複且合起來是 0~9
bool isValid(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);

    // 如果長度不等於 5，補0在前面（因為題目規定五位數）
    while (sa.size() < 5) sa = "0" + sa;
    while (sb.size() < 5) sb = "0" + sb;

    set<char> digits;
    for (char c : sa) digits.insert(c);
    for (char c : sb) digits.insert(c);

    // 必須包含10個數字，且不重複
    return digits.size() == 10;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        bool found = false;
        vector<pair<string, string>> results;

        for (int fghij = 1234; fghij <= 98765; ++fghij) {
            int abcde = fghij * N;
            if (abcde > 98765) continue;

            if (isValid(abcde, fghij)) {
                string s1 = to_string(abcde);
                string s2 = to_string(fghij);
                while (s1.size() < 5) s1 = "0" + s1;
                while (s2.size() < 5) s2 = "0" + s2;

                results.push_back({ s1, s2 });
                found = true;
            }
        }

        if (!found) {
            cout << "There are no solutions for " << N << "." << endl;
        }
        else {
            for (auto& p : results) {
                cout << p.first << " / " << p.second << " = " << N << endl;
            }
        }
        cout << endl; // 每筆測試資料間空一列
    }

    return 0;
}
