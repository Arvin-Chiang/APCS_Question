
//first trying github
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // 考生人數
    cin >> n;

    vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }

    int min_score = 101;
    int max_score = -1;
    int min_failed = 101;
    int max_failed = -1;
    const int pass_line = 60;

    for (int i = 0; i < n; ++i) {
        int score = scores[i];
        min_score = min(min_score, score);
        max_score = max(max_score, score);
        if (score < pass_line) {
            min_failed = min(min_failed, score);
            max_failed = max(max_failed, score);
        }
    }


    if (min_score >= pass_line) {
        cout << "best case" << endl;
    }
    else if (max_score < pass_line) {
        cout << "worst case" << endl;
    }

    return 0;
}

