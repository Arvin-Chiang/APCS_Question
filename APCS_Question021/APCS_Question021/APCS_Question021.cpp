#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t, scenario = 1;
    while (cin >> t && t) {
        cout << "Scenario #" << scenario++ << "\n";

        unordered_map<int, int> memberToTeam;
        for (int i = 0; i < t; ++i) {
            int n, member;
            cin >> n;
            while (n--) {
                cin >> member;
                memberToTeam[member] = i;
            }
        }

        queue<int> teamQueue;
        vector<queue<int>> teamMembers(t);
        vector<bool> inQueue(t, false);

        string cmd;
        while (cin >> cmd && cmd != "STOP") {
            if (cmd == "ENQUEUE") {
                int x;
                cin >> x;
                int team = memberToTeam[x];
                if (!inQueue[team]) {
                    teamQueue.push(team);
                    inQueue[team] = true;
                }
                teamMembers[team].push(x);
            }
            else if (cmd == "DEQUEUE") {
                int team = teamQueue.front();
                int x = teamMembers[team].front();
                teamMembers[team].pop();
                cout << x << "\n";
                if (teamMembers[team].empty()) {
                    teamQueue.pop();
                    inQueue[team] = false;
                }
            }
        }

        cout << "\n";
    }
    return 0;
}
