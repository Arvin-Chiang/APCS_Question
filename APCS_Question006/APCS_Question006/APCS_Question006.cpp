#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
using namespace std;

// 自訂 gcd 與 lcm
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n;
    cin >> n;

    vector<int> days(n);
    for (int i = 0; i < n; ++i) {
        cin >> days[i];
    }

    string date_str;
    cin >> date_str;

    int year, month, day;
    sscanf(date_str.c_str(), "%d/%d/%d", &year, &month, &day);

    long long total_lcm = days[0];
    for (int i = 1; i < n; ++i) {
        total_lcm = lcm(total_lcm, days[i]);
    }

    tm base_date = {};
    base_date.tm_year = year - 1900;
    base_date.tm_mon = month - 1;
    base_date.tm_mday = day;

    time_t base_time = mktime(&base_date);
    base_time += total_lcm * 24 * 60 * 60;

    tm* result_date = localtime(&base_time);
    printf("%04d/%02d/%02d\n", result_date->tm_year + 1900, result_date->tm_mon + 1, result_date->tm_mday);

    return 0;
}
