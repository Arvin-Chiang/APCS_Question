#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    int current_sum = 0;
    int max_sum = scores[0]; 

    for (int i = 0; i < N; ++i) {
        current_sum = max(scores[i], current_sum + scores[i]);
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;
    return 0;
}
