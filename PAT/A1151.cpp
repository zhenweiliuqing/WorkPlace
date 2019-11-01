// //2019-7-9
// //思路:找两个数嘛 分开找 
// //首先看这两个数找不找得到
// //第一种情况：都找不到 一个找不到
// //都找到：分别记录他们的祖先 找到第一个重复的即可
// //难点：如何通过前序中序得到一棵树

// #include <iostream>
// #include <vector>
// using namespace std;
// struct node{
//     int par;
// };
// vector<node> v;
// vector<int> in;
// vector<int> pre;
// bool isexist(int x){
//     for (int i = 0; i < in.size(); i++){
//         if (x == in[i])
//             return true;
//     }
//     return false;
// }
// void make_tree(int root, int start, int end){
//     if (start > end)
//         return;
//     int i = start;
//     while (pre[root] != in[i])
//         i++;
//     v[pre[root + 1]].par = pre[root];
//     make_tree(root + 1, start, i - 1);
//     v[pre[root + 1 + i - start]].par = pre[root];
//     make_tree(root + 1 + i - start, i + 1, end);
// }
// int main(){
//     int test, n;
//     cin >> test >> n;
//     in.resize(n + 1);
//     pre.resize(n + 1);
//     v.resize(n + 1);
//     for (int i = 0; i < n; i++){
//         cin >> in[i];
//     }
//     for (int i = 0; i < n; i++){
//         cin >> pre[i];
//     }
//     make_tree(0, 0, n - 1);
//     int a, b;
//     for (int i = 0; i < test; i++){
//         cin >> a >> b;
//         bool isa ,isb;
//         isa = isexist(a);
//         isb = isexist(b);
//         if (!isa && !isb)
//             printf("ERROR: %d and %d zre not found.", a, b);
//         else if (!isa && isb)
//             printf("ERROR: %d is not found.", a);
//         else if (isa && !isb)
//             printf("ERROR: %d is not found.", b);
//         else {
//             vector<int> a_par, b_par;
//             int temp = a;
//             while (v[temp].par != 0){
//                 a_par.push_back(v[temp].par);
//                 temp = v[temp].par;
//             }
//             temp = b;
//             while (v[temp].par != 0){
//                 b_par.push_back(v[temp].par);
//                 temp = v[temp].par;
//             }

//             for (int i = 0; i < a_par.size() && i < b_par.size(); i++){
//                 if (a_par[i] == b_par[i]){
//                     printf("LCA of %d and %d is %d", a, b, a_par[i]);
//                     break;
//                 }
//             }
//         }
//     }
//     return 0;
// }


// //参考答案
// //2019-7-11
// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;
// map<int, int> pos;
// vector<int> in, pre;
// void lca(int inl, int inr, int preRoot, int a, int b){
//     if (inl > inr)
//         return;
//     int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b];//根 a b 在中序中的位置
//     if (aIn < inRoot && bIn < inRoot)
//         lca(inl, inRoot - 1, preRoot + 1, a, b);
//     else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot))//这个效率更高啊
//         printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
//     else if (aIn > inRoot && bIn > inRoot)
//         lca(inRoot + 1, inr, preRoot + 1 + (inRoot - inl), a, b);
//     else if (aIn == inRoot)//这个方法也不错啊 a的位置 root的位置 a b同属于root下 a恰好等于root
//         printf("%d is an ancestor of %d.\n", a, b);
//     else if (bIn == inRoot)
//         printf("%d is an ancestor of %d.\n", b, a);
// }

// int main(){
//     int m, n, a, b;
//     scanf("%d %d", &m, &n);
//     in.resize(n + 1), pre.resize(n + 1);
//     for (int i = 1; i <= n; i++){
//         scanf("%d", &in[i]);
//         pos[in[i]] = i;//记录中序的位置
//     }
//     for (int i = 1; i <= n; i++)
//         scanf("%d", &pre[i]);
//     for (int i = 0; i < m; i++){
//         scanf("%d %d", &a, &b);
//         if (pos[a] == 0 && pos[b] == 0)//用这个来判定存不存在很妙啊
//             printf("ERROR: %d and %d are not found.\n", a, b);
//         else if (pos[a] == 0 || pos[b] == 0)
//             printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
//         else
//             lca(1, n, 1, a, b);
//     }
//     return 0;
// }


///2019-7-17
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> pre, in;
map<int, int> mp;
void post(int preroot, int inl, int inr, int a, int b){
    if (inl > inr)
        return;
    int inRoot = mp[pre[preroot]];
    if (mp[a] < inRoot && mp[b] < inRoot)//左子树
        post(preroot + 1, inl, inRoot - 1, a, b);
    else if (mp[a] > inRoot && mp[b] > inRoot)
        post(preroot + 1 + inRoot - inl, inRoot + 1, inr, a, b);
    else if ((mp[a] < inRoot && mp[b] > inRoot) || (mp[a] > inRoot && mp[b] < inRoot))
        printf("LCA of %d and %d is %d.\n", a, b, pre[preroot]);
    else if (mp[a] == mp[pre[preroot]])
        printf("%d is an ancestor of %d.\n", a, b);
    else if (mp[b] == mp[pre[preroot]])
        printf("%d is an ancestor of %d.\n", b, a);
}
int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    pre.resize(m + 1), in.resize(m + 1);
    for (int i = 1; i <= m; i++){
        scanf("%d", &in[i]);
        mp[in[i]] = i;
    }
    for (int i = 1; i <= m; i++)
        scanf("%d", &pre[i]);

    int a, b;
    for (int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        if (mp[a] == 0 && mp[b] == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (mp[a] == 0 && mp[b] != 0)
            printf("ERROR: %d is not found.\n", a);
        else if (mp[a] != 0 && mp[b] == 0)
            printf("ERROR: %d is not found.\n", b);
        else
            post(1, 1, m, a, b);
    }
    return 0;
} 
// 26分 有一个测试点 运行超时 
// mp[pre[preroot]]这样很浪费时间啊