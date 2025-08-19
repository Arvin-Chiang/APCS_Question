#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 定義函數 f(x)
double f(double x) {
    return 2 - exp(x);
}

int main() {
    double a = 0.0, b = 1.0; // 根據提示 f(0) < 0，但實際情況 f(0) = 1 > 0，為了示範，假設 b = 1，並調整區間使 f(a) 與 f(b) 异號
    // 這裡需要找到一個區間 [a,b] 使得 f(a)*f(b) < 0
    // 例如 f(0) = 1 > 0, f(2) = 2 - e^2 < 0，則可取 a=0, b=2
    a = 0.0;
    b = 2.0;

    // 容許誤差
    double TOL = 1e-8;
    double mid;

    while ((b - a) / 2 > TOL) {
        mid = (a + b) / 2;
        if (f(mid) == 0.0) {
            break; // 找到根了
        }
        else if (f(a) * f(mid) < 0) {
            b = mid;
        }
        else {
            a = mid;
        }
    }

    // mid 是近似根，輸出四捨五入到小數點後六位
    cout << fixed << setprecision(6) << mid << endl;

    return 0;
}
