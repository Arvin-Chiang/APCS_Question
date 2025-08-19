
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//
// 巧克力總共有 0~8 共 9 顆，每種一個：
//
//    | S | C | T |
// ---+---+---+---+
//  P | 1 | 2 | 3 |
//  B | 4 | 5 | 6 |
//  Y | 7 | 8 | 9 |
//

const int C1 = 1,
C2 = 1 << 1,
C3 = 1 << 2,
C4 = 1 << 3,
C5 = 1 << 4,
C6 = 1 << 5,
C7 = 1 << 6,
C8 = 1 << 7,
C9 = 1 << 8;

// 擺法規則可對應到哪幾顆
unordered_map<string, int> RULEMAP = {
    {"PS", C1},
    {"PC", C2},
    {"PT", C3},
    {"P?", C1 | C2 | C3},
    {"BS", C4},
    {"BC", C5},
    {"BT", C6},
    {"B?", C4 | C5 | C6},
    {"YS", C7},
    {"YC", C8},
    {"YT", C9},
    {"Y?", C7 | C8 | C9},
    {"?S", C1 | C4 | C7},
    {"?C", C2 | C5 | C8},
    {"?T", C3 | C6 | C9},
    {"??", C1 | C2 | C3 | C4 | C5 | C6 | C7 | C8 | C9},
};

// 盒子的組態
int box[9] = { C1, C2, C3, C4, C5, C6, C7, C8, C9 };

typedef vector<int>     Rule;
typedef vector<Rule>    RuleSet;

// 驗證盒子裡的擺法，能否滿足某條指定規則
bool validate(Rule& rule)
{
    for (int i = 0, j; i < 9; i += 3) {     // 有 3 排，要分 3 次，每次 3 顆
        if (rule.size() == 3) {
            if ((rule[0] & box[i]) && (rule[1] & box[i + 1]) && (rule[2] & box[i + 2]))
                return true;
        }
        else {    // rule.size == 2  ==> 拆成左、右測試看看，滿足其中邊就可以了
            if (((rule[0] & box[i]) && (rule[1] & box[i + 1]))
                || ((rule[0] & box[i + 1]) && (rule[1] & box[i + 2])))
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    char cs[5] = {};
    RuleSet rule_list;

    cin >> n;

    rule_list.reserve(n);

    for (; n > 0; n--) {
        cin >> l;
        Rule    rule(l);
        for (int i = 0; i < l; i++) {
            cin >> cs[0] >> cs[1];
            rule[i] = RULEMAP[cs];
        }
        rule_list.push_back(rule);
    }

    int cnt = 0;
    do {
        cnt += all_of(rule_list.begin(), rule_list.end(), validate);    // 滿足所有規則的才加進來
        // if (all_of(rule_list.begin(), rule_list.end(), validate)) {
        //     cnt++;
        // }
    } while (next_permutation(box, box + 9));
    cout << cnt << '\n';
    return 0;
}
