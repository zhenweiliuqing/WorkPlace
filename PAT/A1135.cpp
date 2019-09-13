// //2019-7-15
// //给出先序就可以建立起一棵树嘛？
// //参考答案
// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;
// vector<int> arr;
// struct node{
//     int val;
//     struct node *left, *right;
// };
// node* build(node *root, int v) {
//     if (root == NULL) {
//         root = new node();
//         root->val = v;
//         root->left = root->right = NULL;
//     } else if (abs(v) <= abs(root->val))
//         root->left = build(root->left, v);
//     else
//         root->right = build(root->right, v);
//     return root;
// }
// bool judge1(node *root) {
//     if (root == NULL)
//         return true;
//     if (root->val < 0) {
//         if (root->left != NULL && root->left->val < 0)
//             return false;
//         if (root->right != NULL && root->right->val < 0)
//             return false;
//     }
//     return judge1(root->left) && judge1(root->right);
// }
// int getNum(node *root) {
//     if (root == NULL)
//         return 0;
//     int left = getNum(root->left);
//     int right = getNum(root->right);
//     return root->val > 0 ? max(left, right) + 1 : max(left, right);
// }

// bool judge2(node *root) {
//     if (root == NULL)
//         return true;
//     int left = getNum(root->left);
//     int right = getNum(root->right);
//     if (left != right)
//         return false;
//     return judge2(root->left) && judge2(root->right);
// }

// int main() {
//     int k, n;
//     scanf("%d", &k);
//     for (int i = 0; i < k; i++) {
//         scanf("%d", &n);
//         arr.resize(n);
//         node *root = NULL;
//         for (int j = 0; j < n; j++) {
//             scanf("%d", &arr[j]);
//             root = build(root, arr[j]);
//         }
//         if (arr[0] < 0 || judge1(root) == false || judge2(root) == false)
//             printf("No\n");
//         else
//             printf("Yes\n");
//     }
//     return 0;
// }

//2019-7-29
//思路： 先建立一棵树 然后再用dfs两个条件进行判断
// 注意观察输入是以二叉搜索树的规则插入的
// 两个条件 红色不能挨着红色 黑色的深度得相等
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct node {
    int data;
    struct node *left, *right;
};
node* BuildTree(node* root, int data) {
    if (root == NULL) {
        root = new node();
        root->data = data;
        root->left = root->right = NULL;
    } else if (abs(data) > abs(root->data)) 
        root->right = BuildTree(root->right, data);
    else if (abs(data) < abs(root->data))
        root->left = BuildTree(root->left, data);
    return root;
}
bool redJudge(node* root) {
    if (root == NULL)
        return true; 
    if (root->data < 0 && root->left != NULL && root->left->data < 0)
        return false;
    else if (root->data < 0 && root->right != NULL && root->right->data < 0)
        return false;
    return redJudge(root->left) && redJudge(root->right);
}

// vector<int> depths;
// void dfs(node* root, int depth) {
//     if (root->left == NULL && root->right == NULL) {
//         depths.push_back(depth);
//         return;
//     }
//     if (root->left != NULL && root->left->data > 0)
//         dfs(root->left, depth + 1);
//     else if (root->left != NULL && root->left->data < 0)
//         dfs(root->left, depth);
//     if (root->right != NULL && root->right->data > 0)
//         dfs(root->right, depth + 1);
//     else if (root->right != NULL && root->right->data < 0)
//         dfs(root->right, depth);
// }

int getNum(node* root){
    if (root == NULL)
        return 0;
    int left = getNum(root->left);
    int right = getNum(root->right);
    return root->data > 0 ? max(left, right) + 1 : max(left, right);
}

bool blackJudge(node* root) {
    if (root == NULL)
        return true;
    int left = getNum(root->left);
    int right = getNum(root->right);
    if (left != right)//left == right 为什么不是真
        return false;
    return blackJudge(root->left) && blackJudge(root->right);
}
vector<int> arr;
int main(){
    int m, n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> n;
        node *root = NULL;
        arr.resize(n);
        bool redFlag = true, blackFlag = true;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            root = BuildTree(root, arr[i]);//我给的不是一个地址吗？    
        }
        redFlag = redJudge(root);
        blackFlag = blackJudge(root);
        // depths.clear();
        // dfs(root, 1);
        // for (int i = 1; i < depths.size(); i++){
        //     if (depths[i] != depths[i - 1]){
        //         blackFlag = false;
        //         break;
        //     }
        // }
        if (arr[0] > 0 &&  redFlag && blackFlag)
            cout << "Yes" <<endl;
        else 
            cout << "No" <<endl;
    }
    return 0;
}
//那个构建树那点我不是用的是地址吗 为什么还得返回赋值
//第一次15分 加了 arr[0] > 0 之后变成21分
//估计是深度那点有问题
//找到问题了 全部子树相等 不一定局部子树就相等
//改成参考答案的判定方式 除了总的节点数 子树的节点数也得进行判断
//第三个测试点1分不知道是什么 第四个测试点8分应该是考虑了子树的黑色节点

//疑问：它不可能顶部都相同 下边不相同