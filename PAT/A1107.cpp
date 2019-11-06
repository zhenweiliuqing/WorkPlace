//2019-9-22
//这个才是并查集 之前没写过 看看并查集用什么数据结构

// 思路： 永远都是 圈子重复 人合并
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father, isRoot;
int cmp1(int a, int b) { return a > b; }
int findFather(int x) {
    int a = x;
    while (x != father[x])
        x = father[x];
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x; // 通过这个把所有人的上一级都调整为总的父亲
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
    int n, k, t, cnt = 0;
    int course[1001] = {0}; // course[] 下标代表爱好 取值代表喜欢这个爱好的人
    scanf("%d", &n);
    father.resize(n + 1);
    isRoot.resize(n + 1);
    for (int i = 1; i <= n; i++) // 初始化的时候父节点等于自己
        father[i] = i;
    for (int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &t);//输入爱好 这他妈是糟糕的命名 
            if (course[t] == 0)
                course[t] = i; // 如果这个爱好没人喜欢 初始化为第一个喜欢它的人 
            Union(i, findFather(course[t])); // 第一个喜欢t的人的最父节点与i合并 因为i这个人也是喜欢t的
        }
    }
    for (int i = 1; i <= n; i++)
        isRoot[findFather(i)]++;
    for (int i = 1; i <= n; i++) {
        if (isRoot[i] != 0)
            cnt++;
    }
    printf("%d\n", cnt);
    sort(isRoot.begin(), isRoot.end(), cmp1);
    for (int i = 0; i < cnt; i++) {
        printf("%d", isRoot[i]);
        if (i != cnt - 1)
            printf(" ");
    }
    return 0;
}