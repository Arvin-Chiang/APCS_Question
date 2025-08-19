#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin >> k;
    int target = 1 << k; // 2^k
    int max_val = (int)sqrt(target);
    vector<vector<int>> results;

    // a <= b <= c <= d
    for (int a = 1; a <= max_val; ++a) {
        int a2 = a * a;
        if (a2 * 4 > target) break; // Too large

        for (int b = a; b <= max_val; ++b) {
            int ab2 = a2 + b * b;
            if (ab2 + b * b * 2 > target) break;

            for (int c = b; c <= max_val; ++c) {
                int abc2 = ab2 + c * c;
                if (abc2 + c * c > target) break;

                int d2 = target - abc2;
                int d = (int)sqrt(d2);
                if (d < c) continue;
                if (d * d == d2) {
                    results.push_back({ a, b, c, d });
                }
            }
        }
    }

    if (results.empty()) {
        cout << 0 << endl;
    }
    else {
        sort(results.begin(), results.end()); // 字典順序
        for (auto& res : results) {
            cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << endl;
        }
    }

    return 0;
}
