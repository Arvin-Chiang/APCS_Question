#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < N; ++i) {
            long long x;
            cin >> x;
            pq.push(x);
        }

        long long totalCost = 0;
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            long long sum = a + b;
            totalCost += sum;
            pq.push(sum);
        }

        cout << totalCost << endl;
    }
    return 0;
}
