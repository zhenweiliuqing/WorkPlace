// //2019-7-24
// //大概知道是一个左子树一个右子树 但是不知道如何递归起来
// //是不是可以用一个visit数组表示遍历过
// //通过判断是否是满二叉树来判断yes no
// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;
// vector<int> pre;
// vector<int> post;
// map<int, int> mpre;
// map<int, int> mpost;
// vector<bool> visit;
// struct node{
//     int left, right;
// };
// vector<node> tree;
// void InOrder(int preroot, int postroot){
    
// }

// int main(){
//     int n;
//     cin >> n;
//     pre.resize(n), post.resize(n), visit.resize(n);
//     tree.resize(n);
//     for (int i = 0; i < n; i++){
//         cin >> pre[i];
//         mpre[pre[i]] = i;
//     }
//     for (int i = 0; i < n; i++){
//         cin >> post[i];
//         mpost[post[i]] = i;
//     }
//     InOrder(0, n - 1);

// }
//不知道该用什么数据结构比较好 

//2019-7-24
//参考答案
#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
bool unique = true;
void getIn(int preLeft, int preRight, int postLeft, int postRight){
    if (preLeft == preRight){
        in.push_back(pre[preLeft]);
        return;
    }
    if (pre[preLeft] == post[postRight]){
        int i = preLeft + 1;
        while (i <= preRight && pre[i] != post[postRight - 1])
            i++;
        if (i - preLeft > 1)
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
        else
            unique = false;
        in.push_back(post[postRight]);
        getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    pre.resize(n), post.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    getIn(0, n - 1, 0, n - 1);
    printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
    return 0;
}