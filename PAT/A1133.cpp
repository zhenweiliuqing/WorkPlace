// // 2019-12-30
// // 思路：建立一个node 和 三个vector<node> 小于0 >0且<k >k
// #include <iostream>
// #include <vector>
// using namespace  std;
// struct node{
//     int add, data, next;
// } vertex[100000];
 
// int main() {
//     int start, n, k;
//     cin >> start >> n >> k;
//     vector<node> v(n);
//     vector<node> v0, v1, v2;
//     int temp, data, next;
//     for (int i = 0; i < n; i++) {
//         cin >> temp >> data >> next;
//         vertex[temp].add = temp;
//         vertex[temp].data = data;
//         vertex[temp].next = next;
//     }
//     for (int i = 0; i < n; i++) {
//         v[i].add = start;
//         v[i].data = vertex[start].data;
//         v[i].next = vertex[start].next;
//         start = v[i].next;
//         if (v[i].data < 0)
//             v0.push_back(v[i]);
//         else if (v[i].data <= k)
//             v1.push_back(v[i]);
//         else if (v[i].data > k)
//             v2.push_back(v[i]);
//     }    
//     for (int i = 0; i < v0.size() - 1; i++)
//         printf("%05d %d %05d\n", v0[i].add, v0[i].data, v0[i + 1].add);
//     printf("%05d %d %05d\n", v0[v0.size() - 1].add, v0[v0.size() - 1].data, v1[0].add);
//     for (int i = 0; i < v1.size() - 1; i++)
//         printf("%05d %d %05d\n", v1[i].add, v1[i].data, v1[i + 1].add);
//     printf("%05d %d %05d\n", v1[v1.size() - 1].add, v1[v1.size() - 1].data, v2[0].add);
//     for (int i = 0; i < v2.size() - 1; i++)
//         printf("%05d %d %05d\n", v2[i].add, v2[i].data, v2[i + 1].add);
//     printf("%05d %d %d\n", v2[v2.size() - 1].add, v2[v2.size() - 1].data, -1);
//     return 0;
// }
// // 17 分 段错误 答案错误！！

// 参考答案
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int id, data, next;
};
int main() {
    int begin, n, k, s, d, e;
    scanf("%d%d%d", &begin, &n, &k);
    node a[100010];
    vector<node> v, ans;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &s, &d, &e);
        a[s] = {s, d, e};
    }
    for (; begin != -1; begin = a[begin].next)
        v.push_back(a[begin]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data < 0)
            ans.push_back(v[i]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data >= 0 && v[i].data <= k)
            ans.push_back(v[i]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data > k)
            ans.push_back(v[i]);
    for (int i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i + 1].id);
    printf("%05d %d -1\n", ans[ans.size() - 1].id, ans[ans.size() - 1].data);
    return 0;
}
