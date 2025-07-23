#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        while (true) {
            vector<int> target(N);
            cin >> target[0];
            if (target[0] == 0) {
                cout << endl;
                break;
            }

            for (int i = 1; i < N; ++i) cin >> target[i];

            stack<int> station;
            int current = 1; 
            int index = 0;  

            while (current <= N) {
                station.push(current);

                while (!station.empty() && station.top() == target[index]) {
                    station.pop();
                    index++;
                }

                current++;
            }

            if (station.empty()) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}