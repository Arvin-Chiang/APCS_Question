#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

bool cmpX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool cmpY(const Point& a, const Point& b) {
    return a.y < b.y;
}

// 計算兩點距離
double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// 合併時處理跨越左右區的最小距離
double stripClosest(vector<Point>& strip, double d) {
    double minDist = d;
    sort(strip.begin(), strip.end(), cmpY); // 依 y 排序

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}

// 主體遞迴分治
double closestUtil(vector<Point>& Px) {
    int n = Px.size();
    if (n <= 3) {
        double minD = 1e20;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                minD = min(minD, dist(Px[i], Px[j]));
        return minD;
    }

    int mid = n / 2;
    Point midPoint = Px[mid];

    vector<Point> left(Px.begin(), Px.begin() + mid);
    vector<Point> right(Px.begin() + mid, Px.end());

    double dl = closestUtil(left);
    double dr = closestUtil(right);
    double d = min(dl, dr);

    // 處理中間 strip
    vector<Point> strip;
    for (int i = 0; i < n; ++i)
        if (abs(Px[i].x - midPoint.x) < d)
            strip.push_back(Px[i]);

    return min(d, stripClosest(strip, d));
}

double closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), cmpX);
    return closestUtil(points);
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<Point> points(N);
        for (int i = 0; i < N; ++i)
            cin >> points[i].x >> points[i].y;

        double ans = closestPair(points);
        if (ans >= 10000)
            cout << "INFINITY" << endl;
        else
            cout << fixed << setprecision(4) << ans << endl;
    }
    return 0;
}
