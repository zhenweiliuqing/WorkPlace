// //2019-7-25
// //思路：先进行插入操作 构建成一棵树
// //然后读取最后一层及倒数第二层的个数
// #include <iostream>
// #include <vector>
// using namespace std;
// struct node{
//     int v;
//     struct node *left, *right;
// };
// node* build(node *root, int v){
//     if (root == NULL){
//         root = new node();
//         root->v = v;
//         root->left = root->right = NULL;
//     } else if (v <= root->v)
//         root->left = build(root->left, v);
//     else
//         root->right = build(root->right, v);
//     return root;
// }
// vector<int> num(1000);
// int maxdepth = -1;
// void dfs(node *root, int depth) {
//     if (root == NULL) {
//         maxdepth = max(depth, maxdepth);
//         return;
//     }
//     num[depth]++;
//     dfs(root->left, depth + 1);
//     dfs(root->right, depth + 1);
// }

// int main(){
//     int n, t;
//     scanf("%d", &n);
//     node *root = NULL;
//     for (int i = 0; i < n; i++){
//         scanf("%d", &t);
//         root = build(root, t);
//     }
//     dfs(root, 0);
//     printf("%d + %d = %d", num[maxdepth - 1], num[maxdepth - 2], num[maxdepth - 1] + num[maxdepth - 2]);
//     return 0;
// }


//2019-9-8
//思路：先构建一棵树再说
//然后再考虑depth的问题
#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};
map<int, int, greater<int>> dp;
int maxdepth = 0;
node* insert(node *tree, int val, int depth) {
    dp[depth]++;
    if (maxdepth < depth)
        maxdepth = depth;
    if (tree == NULL) {
        tree = new node();
        tree->val = val;
        tree->left = tree->right = NULL;
    } else if (val <= tree->val) {
        tree->left = insert(tree->left, val, depth + 1);
    } else {
        tree->right = insert(tree->right, val, depth +1);
    }
    return tree;
}
int main() {
    int n, temp;
    cin >> n;
    node *Tree = NULL;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        Tree = insert(Tree, temp, 1);
    }
    printf("%d + %d = %d", dp[maxdepth], dp[maxdepth - 1] - dp[maxdepth], dp[maxdepth - 1]);
    return 0;
}
//29分就很舒服 差一个边缘 这在哪呢？