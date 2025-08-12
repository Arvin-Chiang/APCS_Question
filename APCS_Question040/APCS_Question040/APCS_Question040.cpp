#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> segments(N);
    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        segments[i] = { start, end };
    }

    
    sort(segments.begin(), segments.end());

    int total_length = 0;
    int current_start = -1, current_end = -1;

    for (const auto& seg : segments) {
        int start = seg.first;
        int end = seg.second;

        if (end <= current_end) {
            
            continue;
        }
        else if (start <= current_end) {
            
            current_end = end;
        }
        else {
            
            if (current_start != -1) {
                total_length += current_end - current_start;
            }
            current_start = start;
            current_end = end;
        }
    }

    if (current_start != -1) {
        total_length += current_end - current_start;
    }

    cout << total_length << endl;

    return 0;
}
