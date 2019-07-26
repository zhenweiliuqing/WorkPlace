// //2019-7-20
// //思路：通过深度优先遍历依次遍历每一条路径 然后进行判定
// //3个条件：根为黑色 红色的孩子是黑色 每条路径黑色节点数相同
// //问题是怎么通过先序遍历呢？
// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;
// struct node{
//     int left, right;
// };
// vector<node> tree;
// vector<int> pre;
// bool flag = true;
// void dfs(int start, int end){
//     if (start >= end)
//         return;
    
//     int i = start + 1;
//     while (abs(pre[i]) < abs(pre[start]))
//         i++;   
    

//     node temp;
//     temp.left = pre[start + 1];
//     temp.right = pre[i];
//     tree[start] = temp;
//     dfs(start + 1, i - 1);
//     dfs(i, end);
// }
// int main(){
//     int m, n;
//     cin >> m;
//     for (int i = 0 ; i < m; i++){
//         cin >> n;
//         pre.resize(n);
//         tree.resize(n);
//         for (int j = 0; j < n; j++){
//             scanf("%d", &pre[j]);
//         }
//         if (pre[0] < 0)
//             cout << "No" << endl;
//         else 
//             dfs(0, n - 1);
//     }
// }

//2019-7-20
//参考答案
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> arr;
struct node {
    int val;
    struct node *left, *right;
};
node* build(node *root, int v){
    if (root == NULL) {
        root = new node();
        root->val = v;
        root->left = root->right = NULL;
    } else if (abs(v) <= abs(root->val))
        root->left = build(root->left, v);
    else
        root->right = build(root->right, v);
    return root;
}   
bool judge1(node *root) {
    if (root == NULL)
        return true;
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0)
            return false;
        if (root->right != NULL && root->right->val < 0)
            return false;
    }
    return judge1(root->left) && judge1(root->right);
}    
int getNum(node *root) {
    if (root == NULL)
        return 0;
    int l = getNum(root->left);
    int r = getNum(root->right);
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(node *root) {
    if (root == NULL)
        return true;
    int l = getNum(root->left);
    int r = getNum(root->right);
    if (l != r)
        return false;
    return judge2(root->left) && judge2(root->right);
}
int main() {
    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        arr.resize(n);
        node *root = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
            root = build(root, arr[j]);
        }
        if (arr[0] < 0 || judge1(root) == false || judge2(root) == false)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}