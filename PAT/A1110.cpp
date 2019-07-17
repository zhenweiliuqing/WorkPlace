// //2019-6-28
// //思路： 没有出现的子节点就是根
// //从根开始判断是否子节点为空 若左空右不空 肯定是NO
// //若左不空 右空 说明以后的节点不能再有子节点 
// //若左右都空 同上
// //左右都不空 把节点push进去

// #include <iostream>
// #include <queue>
// using namespace std;
// struct node{
//     int left, right;
// };
// int show[20];
// int main(){
//     int n;
//     cin >> n;
//     string a, b;
//     vector<node> tree(n);
    
//     for (int i = 0; i < n; i++){
//         cin >> a >> b;
//         if (a != "-"){
//             tree[i].left = stoi(a);
//             show[stoi(a)] = 1;
//         }else
//             tree[i].left = -1;
//         if (b != "-"){
//             tree[i].right = stoi(b);
//             show[stoi(b)] = 1;
//         }else
//             tree[i].right = -1;
//     }
//     int root;
//     for (int i = 0; i < n; i++){
//         if (show[i] == 0){
//             root = i;
//             break;
//         }
//     }

//     queue<int> q;
//     bool no_child = false;
//     q.push(root);
//     int last;
//     while (!q.empty()){
//         if (tree[q.front()].left != -1 && tree[q.front()].right != -1 && !no_child){
//             q.push(tree[q.front()].left);
//             q.push(tree[q.front()].right);
//             last = q.front();
//             q.pop();
//         } else if (tree[q.front()].left != -1 && tree[q.front()].right == -1){
//             q.push(tree[q.front()].left);
//             last = q.front();
//             q.pop();
//             no_child = true;
//         } else if (tree[q.front()].left == -1 && tree[q.front()].right == -1) {
//             last = q.front();
//             q.pop();
//             no_child = true;
//         } else {
//             cout << "NO" << " " << root;
//             return 0;
//         }
//     }
//     cout << "YES" << " " << last;
//     return 0;
// }
// //部分正确 11分！
// //把NO的break改成return 0 就满分了！

#include <iostream>
using namespace std;
struct node{
    int left, right;
} a[100];
int maxn = -1, ans;
void dfs(int root, int index){
    if (index > maxn){
        maxn = index;
        ans = root;
    }
    if (a[root].left != -1)
        dfs(a[root].left, index * 2);
    if (a[root].right != -1)
        dfs(a[root].right, index * 2 + 1);
}

int main(){
    int n, root = 0, have[100] = {0};
    cin >> n;
    for (int i = 0; i < n; i++){
        string left, right;
        cin >> left >> right;
        if (left == "-") {
            a[i].left = -1;
        } else {
            a[i].left = stoi(left);
            have[stoi(left)] = 1;
        }
        if (right == "-"){
            a[i].right = -1;
        } else {
            a[i].right = stoi(right);
            have[stoi(right)] = 1;
        }
    }
    while (have[root] != 0)
        root++;
    dfs(root, 1);
    if (maxn == n)
        cout << "YES " << ans;
    else
        cout << "NO " << root;
    return 0;
}