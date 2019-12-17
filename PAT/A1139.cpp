// 2019-12-16
// 思路：无向图寻找A->B的路径 dfs
// 看了答案 有更简单的思路 就判断两个人的线人是不是朋友
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
struct node {
    int x, y;
};
bool cmp(node a, node b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}
vector<int> v[10010];
unordered_map<int, bool> line;
int main() {
    int n, m;
    cin >> n >> m;
    string a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a.length() == b.length()) { // 说明同号
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        // 只要是朋友就连接起来
        line[abs(stoi(a)) * 10000 + abs(stoi(b))] = line[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        for (int j = 0; j < v[abs(c)].size(); j++)
            for (int l = 0; l < v[abs(d)].size(); l++) {
                // 同性恋排除自己当线人
                if (v[abs(c)][j] == abs(d) || v[abs(d)][l] == abs(c))
                    continue;
                if (line[v[abs(c)][j] * 10000 + v[abs(d)][l]])
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][l]});
            }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for (int p = 0; p < ans.size(); p++) {
            printf("%04d %04d\n", ans[p].x, ans[p].y);
        }
    }
    return 0;
}
// a b 一定要加abs 否则有段错误 19分！
// %04 string 25分！
// 答案是满分 到底哪点不一样啊！！！
// 终于找到了 就是同性恋那里l 写成了j！！！

// // 参考答案
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
// using namespace std;
// unordered_map<int, bool> arr;
// struct node {
//     int a, b;
// };
// bool cmp(node x, node y) {
//     return x.a != y.a ? x.a < y.a : x.b < y.b;
// }
// int main() {
//     int n, m, k;
//     scanf("%d%d", &n, &m);
//     vector<int> v[10000];
//     for (int i = 0; i < m; i++) {
//         string a, b;
//         cin >> a >> b;
//         // 建立同性朋友邻接链表
//         if (a.length() == b.length()) {
//             v[abs(stoi(a))].push_back(abs(stoi(b)));
//             v[abs(stoi(b))].push_back(abs(stoi(a)));
//         }
//         // 这种表示连接关系的在地铁那道题见过一次
//         // 邻接链表表示连接关系
//         arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
//     }
//     scanf("%d", &k);
//     for (int i = 0; i < k; i++) {
//         int c, d;
//         cin >> c >> d;
//         vector<node> ans;
//         for (int j = 0; j < v[abs(c)].size(); j++) {
//             for (int k = 0; k < v[abs(d)].size(); k++) {
//                 if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k])
//                     continue;
//                 // 这道题只要符合要求的两个线人是朋友即可
//                 if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]] == true)
//                     ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
//             }
//         }
//         sort(ans.begin(), ans.end(), cmp);
//         printf("%d\n", int(ans.size()));
//         for (int j = 0; j < ans.size(); j++)
//             printf("%04d %04d\n", ans[j].a, ans[j].b);
//     }
//     return 0;
// }

//10 18 -2001 1001 -2002 -2001 1004 1001 -2004 -2001 -2003 1005 1005 -2001 1001 -2003 1002 1001 1002 -2004 -2004 1001 1003 -2002 -2003 1003 1004 -2002 -2001 -2003 1001 1003 1003 -2001 1002 -2001 -2002 -2003

