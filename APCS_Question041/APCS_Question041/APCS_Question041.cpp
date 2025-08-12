#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int toSeconds(const string& timeStr) {
    int h = stoi(timeStr.substr(0, 2));
    int m = stoi(timeStr.substr(3, 2));
    int s = stoi(timeStr.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

string toTimeStr(int totalSeconds) {
    int h = totalSeconds / 3600;
    totalSeconds %= 3600;
    int m = totalSeconds / 60;
    int s = totalSeconds % 60;

    
    ostringstream oss;
    oss << setw(2) << setfill('0') << h << ":"
        << setw(2) << setfill('0') << m << ":"
        << setw(2) << setfill('0') << s;
    return oss.str();
}

int main() {
    string t1, t2;
    cin >> t1 >> t2;

    int s1 = toSeconds(t1);
    int s2 = toSeconds(t2);

    int diff = s2 - s1;
    if (diff < 0) diff += 24 * 3600; 

    cout << toTimeStr(diff) << "\n";

    return 0;
}
