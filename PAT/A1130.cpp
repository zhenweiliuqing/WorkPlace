//2019-6-25
#include <iostream>
#include <vector>
using namespace std;
struct  node
{
    int par;
    string str;
    int left, right;
};
vector<node> tree(20);
string dfs(int root){
    if (tree[root].left != -1 && tree[root].right != -1){
        return "(" + dfs(tree[root].left) + tree[root].str + dfs(tree[root].right) + ")";
    }
    else if (tree[root].left == -1 && tree[root].right != -1){
        return "(" + tree[root].str + dfs(tree[root].right) + ")";
    }
    else if (tree[root].left == -1 && tree[root].right == -1){
        return tree[root].str;
    }
}
int main(){
    int n;
    cin >> n;
    int head = 0;
    for (int i = 1; i <= n; i++){
        cin >> tree[i].str >> tree[i].left >> tree[i].right;
        if (tree[i].left != -1 )
            tree[tree[i].left].par = i;
        if (tree[i].right != -1)
            tree[tree[i].right].par = i;
    }
    for (int i = 1; i <= n; i++){
        if (tree[i].par == 0){
            head = i;
            break;
        }
    }
    string ans = dfs(head);
    if (ans[0] == '(')
        cout << ans.substr(1, ans.size() - 2);
    else
        cout << ans;
    return 0;
}
//第一次18分 加上else 之后19分
//最后有一个段错误
//把20 改成 21就好了