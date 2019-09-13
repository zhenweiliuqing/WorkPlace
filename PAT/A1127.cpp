// //2019-7-22
// //思路：通过中序后序建立一个层序 其中没有的位置空着
// //然后再考虑输出
// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> in, post;
// vector<int> level(31);
// int n;
// void levelOrder(int postroot, int instart, int inend, int index){
//     if (instart > inend)
//         return;
//     int i = inend;
//     while (post[postroot] != in[i])
//         i--;
//     levelOrder(postroot - 1 - inend + i, instart, i - 1, index * 2);
//     if ((postroot - 1 - inend + i) > 0 )
//         level[index * 2] = post[postroot - 1 - inend + i];
//     levelOrder(postroot - 1, i + 1, inend, index * 2 + 1);
//     if (postroot - 1 > 0)
//         level[index * 2 + 1] = post[postroot - 1];
// }
// int main(){
//     cin >> n;
//     in.resize(n), post.resize(n);
//     for (int i = 0; i < n; i++)
//         cin >> in[i];
//     for (int i = 0; i < n; i++)
//         cin >> post[i];
//     levelOrder(n - 1, 0, n - 1, 1);
//     return 0;
// }

// //2019-7-22
// //参考答案
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// vector<int> in, post, result[35];
// int n, tree[35][2], root;
// struct node{
//     int index, depth;
// };
// void dfs(int &index, int inLeft, int inRight, int postLeft, int postRight) {
//     if (inLeft > inRight)
//         return;
//     index = postRight;
//     int i = 0;
//     while (in[i] != post[postRight])
//         i++;
//     dfs(tree[index][0], inLeft, i - 1, postLeft, postLeft + (i - inLeft) - 1);//postleft有什么用？
//     dfs(tree[index][1], i + 1, inRight, postLeft + (i - inLeft), postRight - 1);
// }

// void bfs() {
//     queue<node> q;
//     q.push(node{root, 0});
//     while (!q.empty()){
//         node temp = q.front();
//         q.pop();
//         result[temp.depth].push_back(post[temp.index]);
//         if (tree[temp.index][0] != 0)
//             q.push(node{tree[temp.index][0], temp.depth + 1});
//         if (tree[temp.index][1] != 0)
//             q.push(node{tree[temp.index][1], temp.depth + 1});
//     }
// }

// int main() {
//     cin >> n;
//     in.resize(n + 1), post.resize(n + 1);
//     for (int i = 1; i <= n; i++)
//         cin >> in[i];
//     for (int i = 1; i <= n; i++)
//         cin >> post[i];
//     dfs(root, 1, n, 1, n);
//     bfs();
//     printf("%d", result[0][0]);
//     for (int i = 1; i < 35; i++) {
//         if (i % 2 == 1){
//             for (int j = 0; j < result[i].size(); j++)
//                 printf(" %d", result[i][j]);
//         } else {
//             for (int j = result[i].size() - 1; j >= 0; j--)
//                 printf(" %d", result[i][j]);
//         }
//     }
//     return 0;
// }

//2019-8-29
//思路：那一天大好的时光竟然没有深入思考 真的是浪费
//现在晚上看一看 先进行输入 主要是他采用了引用把数据存在一个树中
//先把树的构建那一部分写了 bfs那一部分再说
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> in, post;
int tree[35][2];
vector<int> level[35];
struct node {
    int data, depth;
};
void dfs(int &index, int inL, int inR, int postL, int postR){
    if (inL > inR)
        return;
    int i = 1;
    index = postR;
    while (in[i] != post[index])
        i++;
    dfs(tree[index][0], inL, i - 1, postL, postL + (i - inL) - 1);
    dfs(tree[index][1], i + 1, inR, postL + (i - inL), postR - 1);
}
void bfs(int root) {
    queue<node> q;
    q.push(node{root, 0});
    while (!q.empty()) {
        node temp = q.front();
        level[temp.depth].push_back(post[temp.data]);
        q.pop();
        if (tree[temp.data][0] != 0)
            q.push(node{tree[temp.data][0], temp.depth + 1});
        if (tree[temp.data][1] != 0)
            q.push(node{tree[temp.data][1], temp.depth + 1});
    }
}
int main(){
    int n;
    cin >> n;
    in.resize(n + 1), post.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
    } 
    for (int i = 1; i <= n; i++) {
        cin >> post[i];
    }
    int root;
    dfs(root, 1, n, 1, n);
    bfs(root);
    printf("%d", level[0][0]);
    for (int i = 1; i < 35; i++) {
        if (i % 2 == 1){
            for (int j = 0; j < level[i].size(); j++){
                printf(" %d", level[i][j]);
            }
        } else if (i % 2 == 0) {
            for (int j = level[i].size() - 1; j >= 0; j--) {
                printf(" %d", level[i][j]);
            }
        }
    }
    return 0;
}
//全对 但是中途看了好几次答案