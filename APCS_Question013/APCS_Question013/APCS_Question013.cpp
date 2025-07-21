#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    double area = 0.0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;  // 下一个點（環狀）
        area += (polygon[i].x * polygon[j].y) - (polygon[j].x * polygon[i].y);
    }

    area = abs(area) / 2.0;

    cout << fixed << setprecision(2) << area << endl;

    return 0;
}
