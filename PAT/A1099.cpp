// //2019-7-27
// //思路：通过深度优先搜索遍历每一个节点 
// //按照左根右的顺序进行编号 
// //将输入进行排序 按照编号的顺序填进去
// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> pre;
// vector<int> level;
// struct node {
//     int order;
//     int left,right;
// };
// vector<node> tree;
// void dfs(int index){

// }
// int main(){
//     int n;
//     cin >> n;
//     tree.resize(n), pre.resize(n);
//     for (int i = 0; i < n; i++)
//         cin >> tree[i].left >> tree[i].right;
//     for (int i = 0; i < n; i++)
//         cin >> pre[i];
//     dfs(0);
// }

//2019-7-27
//参考答案
#include <iostream>
#include <algorithm>
using namespace std;
int n, cnt, b[100];
struct node {
    int data, l, r, index, level;
} a[110];
bool cmp(node x, node y) { 
    if (x.level != y.level)
        return x.level < y.level;
    return x.index < y.index;
}
void dfs(int root, int index, int level) {
    if (a[root].l == -1 && a[root].r == -1) {
        a[root] = {b[cnt++], a[root].l, a[root].r, index, level};
    } else {
        if (a[root].l != -1)
            dfs(a[root].l, index * 2 + 1, level + 1);
        a[root] = {b[cnt++], a[root].l, a[root].r, index, level};
        if (a[root].r != -1)
            dfs(a[root].r, index * 2 + 2, level + 1);
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i].l >> a[i].r;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b + n);
    dfs(0, 0, 0);
    sort(a, a + n, cmp);
    for (int i = 0; i < n ; i++) {
        if ( i != 0) 
            cout << " ";
        cout << a[i].data;
    }
    return 0;                            
}