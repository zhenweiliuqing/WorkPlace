// //2019-9-22
// //这个才是并查集 之前没写过 看看并查集用什么数据结构
// #include <cstdio>
// #include <vector>
// #include <algorithm>
// using namespace std;
// vector<int> father, isRoot;
// int cmp1(int a, int b) { return a > b; }
// int findFather(int x) {
//     int a = x;
//     while (x != father[x])
//         x = father[x];
//     while (a != father[a]) {
//         int z = a;
//         a = father[a];
//         father[z] = x;
//     }
//     return x;
// }
// void Union(int a, int b) {
//     int faA = findFather(a);
//     int faB = findFather(b);
//     if (faA != faB)
//         father[faA] = faB;
// }
// int main() {
//     int n, k, t, cnt = 0;
//     int course[1001] = {0};
//     scanf("%d", &n);
//     father.resize(n + 1);
//     isRoot.resize(n + 1);
//     for (int i = 1; i <= n; i++)
//         father[i] = i;
//     for (int i = 1; i <= n; i++) {
//         scanf("%d:", &k);
//         for (int j = 0; j < k; j++) {
//             scanf("%d", &t);//输入爱好 这他妈是糟糕的命名 
//             if (course[t] == 0)
//                 course[t] = i;
//             Union(i, findFather(course[t]));
//         }
//     }
//     for (int i = 1; i <= n; i++)
//         isRoot[findFather(i)]++;
//     for (int i = 1; i <= n; i++) {
//         if (isRoot[i] != 0)
//             cnt++;
//     }
//     printf("%d\n", cnt);
//     sort(isRoot.begin(), isRoot.end(), cmp1);
//     for (int i = 0; i < cnt; i++) {
//         printf("%d", isRoot[i]);
//         if (i != cnt - 1)
//             printf(" ");
//     }
//     return 0;
// }


// 2019-11-2
// 思路：关键是两个函数 Union 和 findFather 
// 然后考虑如何利用交叠信息进行合并 
// 合并还是合并人 重叠的还是关系
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father ,isRoot;
int hobby[1010];
map<int, int> classes;
bool cmp(int a, int b){
    return a > b;
}
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
    int n, k, hob;
    cin >> n;
    // scanf("%d", &n);
    father.resize(n + 1);
    isRoot.resize(n + 1);
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= n ; i++) {
        // cin >> k;
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            cin >> hob;
            // scanf("%d", &hob);
            if (hobby[hob] == 0)
                hobby[hob] = i;
            Union(i, findFather(hobby[hob])); // 很多时候都是自己跟自己 但是如果这个爱好之前有人喜欢 那么后来的就与其合并
        }
    }

    // 假设合并完了 统计类数和个数
    // 其实可能有的并没有合并完 
    for (int i = 1; i <= n; i++) {
        classes[findFather(i)]++; // father[i]还是不完全对 这就全对了
    }
    cout << classes.size() << endl;
    vector<int> members(classes.size());
    int cnt = 0;
    for (auto it = classes.begin(); it != classes.end(); it++) {
        members[cnt++] = it->second;
    }
    sort(members.begin(), members.end(), greater<int>());
    cout << members[0];
    for (int i = 1; i < members.size(); i++)
        cout << " " << members[i];
    return 0;

    // // 改改后边试一下
    // int cnt = 0;
    // for (int i = 1 ; i <= n; i++) {
    //     isRoot[findFather(i)]++;
    // }
    // for (int i = 1; i <= n; i++) {
    //     if (isRoot[i] != 0)
    //         cnt++;
    // }
    // sort(isRoot.begin(), isRoot.end(), cmp);
    // cout << cnt << endl;
    // cout << isRoot[0];
    // for (int i = 1; i < cnt; i++)
    //     cout << " " << isRoot[i];
    // return 0;
}
// 才1分 也太惨了把
// father[i]还是不完全对 这就全对了 20->30
// 输入的那个冒号必须要有 才能得满分