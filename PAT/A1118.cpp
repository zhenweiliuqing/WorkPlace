// 2019-10-31
// 思路：关键是两个问题 如何找到交叠的关系 如何合并人
// 这里每一行都是属于一个集合的 所以先把每一行的内容给合并
// 行与行之间怎么找到交叠呢？ 通过更新父亲节点应该可以
// 统计树的个数 就是看一共有几个不同的父亲 并把一个父亲下的所有鸟都加在一起
// 然后通过找根父亲节点可以找到是否属于同一棵树 

#include <iostream>
#include <map>
using namespace std;
int maxn = 10010;
int father[10010];
bool visit[10010];
map<int, int> tree;
int findFather(int x) {
    int upx = x;
    while (x != father[x])
        x = father[x];
    while (upx != father[upx]) {
        int temp = upx;
        upx = father[upx];
        father[temp] = x;
    }
    return x;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
        father[faA] = faB; // ！！！
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < maxn; i++){
        father[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int k, fbird, temp;
        cin >> k >> fbird;
        visit[fbird] = true;
        for (int j = 0; j < k - 1; j++) {
            cin >> temp;
            visit[temp] = true;
            Union(fbird, temp);
            fbird = temp;
        }
    }
    for (int i = 1; i <= maxn; i++) {
        if (visit[i])
            findFather(i);
    }
    for (int i = 1; i <= maxn; i++) {
        if (visit[i] && father[i] != 0)
            tree[father[i]]++;
    }
    int sum = 0;
    for (auto it = tree.begin(); it != tree.end(); it++){
        sum += it->second;
    }
    cout << tree.size() << " " << sum << endl;
    int m, a, b;
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        printf(findFather(a) == findFather(b) ? "Yes\n" : "No\n");
    }
    return 0;
}
// 虽然提前看过答案 不过大部分还是自己又写了一遍 加深下印象！！！
//        father[faA] = faB; // ！！！
