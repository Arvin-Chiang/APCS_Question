#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int case_num = 1;
    int N;

    while (cin >> N) {
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        long long max_ending_here = arr[0];
        long long min_ending_here = arr[0];
        long long max_so_far = arr[0];

        for (int i = 1; i < N; i++) {
            int x = arr[i];
            if (x < 0) {
                swap(max_ending_here, min_ending_here);
            }

            max_ending_here = max((long long)x, max_ending_here * x);
            min_ending_here = min((long long)x, min_ending_here * x);

            if (max_ending_here > max_so_far) {
                max_so_far = max_ending_here;
            }
        }

        if (max_so_far <= 0) max_so_far = 0;

        cout << "Case #" << case_num++ << ": The maximum product is " << max_so_far << ".\n\n";
    }

    return 0;
}
