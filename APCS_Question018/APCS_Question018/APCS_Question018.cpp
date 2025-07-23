#include <iostream>
#include <queue>
using namespace std;

struct Document {
    int index;      
    int priority;   
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        queue<Document> q;
        int count[10] = {}; 

        for (int i = 0; i < n; ++i) {
            int p;
            cin >> p;
            q.push({ i, p });
            count[p]++;
        }

        int time = 0;
        while (!q.empty()) {
            Document cur = q.front();
            q.pop();

         
            bool hasHigher = false;
            for (int i = cur.priority + 1; i <= 9; ++i) {
                if (count[i] > 0) {
                    hasHigher = true;
                    break;
                }
            }

            if (hasHigher) {
              
                q.push(cur);
            }
            else {
               
                time++;
                count[cur.priority]--;
                if (cur.index == m) {
                    cout << time << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
