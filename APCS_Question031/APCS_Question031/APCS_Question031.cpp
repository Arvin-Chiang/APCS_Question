#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        vector<int> prices(N);
        for (int i = 0; i < N; ++i) {
            cin >> prices[i];
        }
        int M;
        cin >> M;
        
        sort(prices.begin(), prices.end());

        int left = 0, right = N - 1;
        int book1 = 0, book2 = 0;
        int min_diff = INT_MAX;

        while (left < right) {
            int sum = prices[left] + prices[right];
            if (sum == M) {
                int diff = abs(prices[right] - prices[left]);
                if (diff < min_diff) {
                    min_diff = diff;
                    book1 = prices[left];
                    book2 = prices[right];
                }
             
                left++;
                right--;
            }
            else if (sum < M) {
                left++;
            }
            else {
                right--;
            }
        }

        cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << ".\n\n";
    }

    return 0;
}
