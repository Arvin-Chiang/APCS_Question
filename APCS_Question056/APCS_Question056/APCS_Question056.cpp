#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int R_NO_ANSWER = 0,
R_FOUND_ORDER = 1,
R_CONFLICT = 2;

struct Node {
    int         pre = 0,   // 前面有哪些節點(bit mask)
        post = 0;   // 後面有哪些節點(bit mask)
    vector<int> child;      // 下一個節點清單
};

int             n, m;
vector<Node>    g;
string          order;

// DFS 展開測試順序
bool expand(int index, int me)
{
    order[index] = 'A' + me;
    if (index == n - 1)
        return true;
    for (auto& c : g[me].child) {
        if (expand(index + 1, c))
            return true;
    }
    return false;
}

int main()
{
    char        s, t;
    set<int>    head;   // 可當成起點的節點
    int         result = R_NO_ANSWER,
        cause_pair = 0;

    cin >> n >> m;

    g.resize(n);
    order.assign(n, ' ');

    for (int i = 0; i < n; i++)
        head.insert(i);

    for (int i = 1; i <= m; i++) {
        cin >> s >> t;
        s -= 'A';
        t -= 'A';

        g[s].child.push_back(t);            // 把 t 加到 s 的後面
        g[s].post |= (1 << t) | g[t].post;  // s 後續可到的節點為 t 的後續節點加上 t
        g[t].pre |= (1 << s) | g[s].pre;    // t 的前置節點為 s 的前置節點加上 s

        for (int j = 0, mask = 1; j < n; j++, mask <<= 1) {
            if (g[s].pre & mask)            // 更新 s 前置節點的後續節點
                g[j].post |= g[s].post;

            if (g[t].post & mask)           // 更新 t 後續節點的前置節點
                g[j].pre |= g[t].pre;
        }

        if (g[t].post & g[t].pre) {         // 前置與後續有共同的節點 -> loop
            result = R_CONFLICT;
            cause_pair = i;
            break;
        }
        else if (result == R_NO_ANSWER) {     // 還沒有答案
            head.erase(t);      // t 不能當成起點(因為 s 要在 t 前面)

            if (head.size() == 1 && expand(0, *head.begin())) { // 僅有一個起點時再展開就好，多個起點無法決定順序
                result = R_FOUND_ORDER;
                cause_pair = i;
            }
        }
    }

    if (result == R_NO_ANSWER)
        cout << "No answer\n";
    else if (result == R_FOUND_ORDER)
        cout << "Determine the testing sequence after getting pair " << cause_pair << " : " << order << '\n';
    else
        cout << "Order conflict after getting pair " << cause_pair << '\n';

    return 0;
}