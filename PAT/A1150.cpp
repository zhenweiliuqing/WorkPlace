//2019-6-3
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int e[300][300], n, m, k, ans = 99999999, ansid;
vector<int> v;
void check(int index){
    int sum = 0, cnt, flag = 1;
    scanf("%d", &cnt);
    set<int> s;
    vector<int> v(cnt);
    for (int i = 0; i < cnt; i++){
        scanf("%d", &v[i]);
        s.insert(v[i]);
    }
    for (int i = 0; i < cnt - 1; i++){
        if (e[v[i]][v[i+1]] == 0)
            flag = 0;
        sum += e[v[i]][v[i + 1]];
    }
    if (flag == 0){//此路不通
        printf("Path %d: NA (Not a TS cycle)\n", index);
    } else if (v[0] != v[cnt - 1] || s.size() != n){//首尾不连 或者 首尾连通却没有遍历所有节点
        printf("Path %d: (Not a TS cycle)\n", index, sum);
    } else if (cnt != n + 1){//不止一次经过节点
        printf("Path %d: %d (TS cycle)\n", index, sum);
        if (sum < ans){
            ans = sum;
            ansid = index;
        }
    } else {
        printf("Path %d: %d (TS simple cycle)\n", index, sum);
        if (sum < ans){
            ans = sum;
            ansid = index;
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        int t1, t2, t;
        scanf("%d%d%d", &t1, &t2, &t);
        e[t1][t2] = e[t2][t1] = t;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
        check(i);
    printf("Shortest Dist(%d) = %d\n", ansid, ans);
    return 0;
}
//这个题真的是没用到任何算法

// //2018-6-9
// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;
// int edge[200][200];
// int main(){
//     int nv, ne;
//     cin >> nv >> ne;
//     int v1, v2, w;
//     for (int i = 0; i < ne; i++){
//         cin >> v1 >> v2 >> w;
//         edge[v1][v2] = edge[v2][v1] = w;
//     }
//     int n;
//     cin >> n;
//     int m, minsum = 99999999, index;
//     for (int i = 1; i <= n; i++){
//         cin >> m;
//         vector<int> v(m);
//         set<int> s;
//         bool isCycle = true, isSimple = true;
//         int sum = 0;
//         cin >> v[0];
//         s.insert(v[0]);
//         for (int j = 1; j < m; j++){
//             cin >> v[j];
//             s.insert(v[j]);
//             if (edge[v[j - 1]][v[j]] == 0){//没有连接
//                 cout << "Path " << i << ": NA (Not a TS cycle)" << endl;
//                 isCycle = isSimple = false;
//                 break;
//             }else 
//                 sum += edge[v[j - 1]][v[j]];
//             if (j == m - 1){
//                 if (v[0] != v[j] || s.size() != nv)//
//                     isCycle = false;
//                 else if (m != nv + 1)
//                     isSimple = false;
//                 if (sum < minsum && isCycle){
//                     minsum = sum;
//                     index = i;
//                 }
//             }
//         }
       
//         if (!isCycle && isSimple)
//             cout << "Path " << i << ": " << sum << " (Not a TS cycle)" << endl;
//         else if (!isSimple && isCycle)
//             cout << "Path " << i << ": " << sum << " (TS cycle)" << endl;
//         else if (isCycle && isSimple)
//             cout << "Path " << i << ": " << sum << " (TS simple cycle)" << endl;
//     }
//     cout << "Shortest Dist(" << index << ") = " << minsum;
//     cout << endl;
//     return 0;
// }
// //示例是对着的啊怎么只有2分
// //加了一个endl 多了四分 段错误没了？