#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

int main() {
    int n;
    cin >> n;
    Point points[100];  // n < 100

    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    double area = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += (points[i].x * points[j].y - points[j].x * points[i].y);
    }

    area = fabs(area) / 2.0;

    cout << fixed << setprecision(2) << area << endl;
    return 0;
}