// // 2019-12-27 
// // 思路：刚开始没看太懂 
// // 给定一个顶点集合 这些顶点能否连接到所有的edge
// // 感觉以点以边为中心都可以 
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> v[n];
//     int v1, v2;
//     for (int i = 0; i < m; i++) {
//         cin >> v1 >> v2;
//         v[v1].push_back(i);
//         v[v2].push_back(i);
//     }
//     int k;
//     cin >> k;
//     for (int i = 0; i < k; i++) {
//         int num, vertex;
//         vector<bool> visit(m, false);
//         // fill(visit, visit, false);
//         cin >> num;
//         for (int j = 0; j < num; j++) {
//             cin >> vertex;
//             for (int l = 0; l < v[vertex].size(); l++) {
//                 visit[v[vertex][l]] = true;
//             }
//         }
//         for (int l = 0; l < m; l++) {
//             if (!visit[l]) {
//                 printf("No\n");
//                 break;
//             }
//             if (l == m - 1)
//                 printf("Yes\n");
//         }
//     }
//     return 0;
// }
// // 满分！！！

// 参考答案
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, k, nv, a, b, num;
    scanf("%d%d", &n, &m);
    vector<int> v[n];

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &nv);
        int flag = 0;
        vector<int> hash(m, 0);
        for (int j = 0; j < nv; j++) {
            scanf("%d", &num);
            for (int t = 0; t < v[num].size(); t++)
                hash[v[num][t]] = 1;
        }
        for (int j = 0; j < m; j++) {
            if (hash[j] == 0) {
                printf("No\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("Yes\n");
    }
    return 0;
}