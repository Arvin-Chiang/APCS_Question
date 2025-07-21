#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
using namespace std;

// 將整數轉為 3 位二進位字串
string intToBinary3(int n) {
    return bitset<3>(n).to_string();
}

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s); // 吃掉換行

    while (n--) {
        getline(cin, s);

        // 檢查是否只有 0/1
        bool valid = true;
        for (char c : s) {
            if (c != '0' && c != '1') {
                valid = false;
                break;
            }
        }

        if (!valid || s.empty()) {
            cout << "-1\n";
            continue;
        }

        string result = "";
        int i = 0, len = s.length();
        int compressedBits = 0;

        while (i < len) {
            char bit = s[i];
            int count = 0;

            while (i < len && s[i] == bit && count < 7) {
                count++;
                i++;
            }

            string group = (bit == '0' ? "0" : "1") + intToBinary3(count);
            result += group + " ";
            compressedBits += 4;
        }

        if (i != len) {
            cout << "-1\n";
        }
        else {
            double percentage = (double)compressedBits / (len) * 100;
            cout << result << fixed << setprecision(0) << percentage << "%\n";
        }
    }

    return 0;
}
