// //2019-6-23
// //参考答案
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// struct node {
//     int id, left, right, index, level;
// } a[100];
// vector<node> v1;
// void dfs(int root, int index, int level){
//     if (a[root].right != -1)
//         dfs(a[root].right, index * 2 + 2, level + 1);
//     v1.push_back({root, 0, 0, index, level});
//     if (a[root].left != -1)
//         dfs(a[root].left, index * 2 + 1, level + 1);
// }

// bool cmp(node a, node b){
//     if (a.level != b.level)
//         return a.level < b.level;
//     return a.index > b.index;
// }

// int main(){
//     int n, have[100] = {0}, root = 0;
//     cin >> n;
//     for (int i = 0; i < n; i++){
//         a[i].id = i;
//         string left, right;
//         cin >> left >> right;
//         if (left != "-"){
//             a[i].left = stoi(left);
//             have[stoi(left)] = 1;
//         } else {
//             a[i].left = -1;
//         }

//         if (right != "-"){
//             a[i].right = stoi(right);
//             have[stoi(right)] = 1;
//         } else {
//             a[i].right = -1;
//         }
//     }
//     while (have[root] == 1)
//         root++;
//     dfs(root, 0, 0);
//     vector<node> v2(v1);
//     sort(v2.begin(), v2.end(), cmp);
//     for (int i = 0; i < v2.size(); i++){
//         if (i != 0)
//             cout << " ";
//         cout << v2[i].id;
//     }
//     cout << endl;
//     for (int i = 0; i < v1.size(); i++){
//         if (i != 0)
//             cout << " ";
//         cout << v1[i].id;
//     }
//     return 0;
// }

//2019-9-15
// 思路：先构建一棵树 层序采用BFS 中序采用DFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int par;
    int left, right;
};
vector<node> v;
vector<int> in, level;
void dfs(int root) {
    if (root == -1)
        return;
    if (v[root].right != -1)
        dfs(v[root].right);
    in.push_back(root);
    if (v[root].left != -1)
        dfs(v[root].left);
}
void bfs(int root) {
    queue<int> q;
    int temp;
    q.push(root);
    while (!q.empty()) {
        temp = q.front();
        level.push_back(temp);
        q.pop();
        if (v[temp].right != -1)
            q.push(v[temp].right);
        if (v[temp].left != -1)
            q.push(v[temp].left);
    }
}
int main() {
    int n;
    cin >> n;
    v.resize(n);
    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a != "-") {
            v[i].left = stoi(a);
            v[stoi(a)].par = n;
        } else
            v[i].left = -1;
        if (b != "-"){
            v[i].right = stoi(b);
            v[stoi(b)].par = n;
        } else
            v[i].right = -1;
    }
    // 找到根节点
    int root;
    for (int i = 0; i < n; i++) {
        if (v[i].par != n)
            root = i;
    }
    dfs(root);
    bfs(root);
    printf("%d", level[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", level[i]);
    cout << endl;
    printf("%d", in[0]);
    for (int i = 1; i< n; i++)
        printf(" %d", in[i]);
    return 0;
}
// 答案正确 25分！！！