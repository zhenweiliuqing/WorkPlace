// //2019-9-23
// //参考答案 并查集
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// struct DATA {
//     int id, fid, mid, num, area;
//     int cid[10];
// } data[1005];
// struct node {
//     int id, people;
//     double num, area;
//     bool flag = false;
// } ans[10000];
// int father[10000];
// bool visit[10000];
// int find(int x) {
//     while (x != father[x])
//         x = father[x];
//     return x;
// }
// void Union(int a, int b) {
//     int faA = find(a);
//     int faB = find(b);
//     if (faA > faB)
//         father[faA] = faB;
//     else if (faA < faB)
//         father[faB] = faA;
// }
// int cmp1(node a, node b) {
//     if (a.area != b.area)
//         return a.area > b.area;
//     else
//         return a.id < b.id;
// }
// int main() {
//     int n, k, cnt = 0;
//     scanf("%d", &n);
//     for (int i = 0; i < 10000; i++)
//         father[i] = i;
//     for (int i = 0; i < n; i++) {
//         scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
//         visit[data[i].id] = true;
//         if (data[i].fid != -1) {
//             visit[data[i].fid] = true;
//             Union(data[i].mid, data[i].id);
//         }
//         for (int j = 0; j < k; j++) {
//             scanf("%d", &data[i].cid[j]);
//             visit[data[i].cid[j]] = true;
//             Union(data[i].cid[j], data[i].id);
//         }
//         scanf("%d %d", &data[i].num, &data[i].area);
//     }
//     for (int i = 0; i < n; i++) {
//         int id = find(data[i].id);
//         ans[id].id = id;
//         ans[id].num += data[i].num;
//         ans[id].area += data[i].area;
//         ans[id].flag = true;
//     }
//     for (int i = 0; i < 10000; i++) {
//         if (visit[i])
//             ans[find(i)].people++;
//         if (ans[i].flag)
//             cnt++;
//     }
//     for (int i = 0; i < 10000; i++) {
//         if (ans[i].flag) {
//             ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
//             ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
//         }
//     }
//     sort(ans, ans + 10000, cmp1);
//     printf("%d\n", cnt);
//     for (int i = 0; i < cnt; i++)
//         printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
//     return 0;
// }

// 2019-11-3
// 思路：这里是人的关系进行重叠
// 得需要一个结构体
// 怎么找到父亲 如果有母亲的时候 父亲应该在母亲后边 
#include <iostream>
#include <vector>
using namespace std;
int father[10010];
struct node {
    int id;
    double house, house_area;
};
struct family {
    int id, num;
    double house, house_m;
};
vector<node> v;
int findFather(int x) {
    int rex = x;
    while (x != father[x])
        x = father[x];
    while (rex != father[rex]) {
        int temp = rex;
        rex = father[rex];
        father[temp] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
        father[faA] = faB;
}
int main() {
    int n;
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i < 10010; i++)
        father[i] = i;
    int id, fa, ma;
    for (int i = 1; i <= n; i++) {
        cin >> id >> fa >> ma;
        if (fa != -1)
            Union(id, fa);
        if (ma != -1)
            Union(id, ma); // 最后是ma
        int child_num, child;
        cin >> child_num;
        for (int j = 0; j < child_num; j++) {
            cin >> child;
            Union(child, id);
        }
        double house_num, house_area;
        cin >> house_num >> house_area;
        v[i] = {id, house_num, house_area};
    }
    int cnt = 0;
    vector<family> res;
    for (int i = 1; i <= n; i++) {

    }
}
// 如何把人的信息都给存储到一起进行排序 找到最小的那个id 
// 同时也得把房子的信息给集合到一起还不能重复