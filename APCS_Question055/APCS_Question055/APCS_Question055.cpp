#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
    return p1.first * p2.second < p1.second * p2.first;
}

int main() {
    int N;
    while (cin >> N) {
        vector<pair<long long, long long>> p(N);

        for (int i = 0; i < N; i++) {
            cin >> p[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> p[i].second;
        }

        sort(p.begin(), p.end(), cmp);

        long long energy = 0;
        long long cum_w = 0;
        for (int i = 0; i < N - 1; i++) {
            cum_w += p[i].first;
            energy += cum_w * p[i + 1].second;
        }

        cout << energy << endl;
    }
    return 0;
}
