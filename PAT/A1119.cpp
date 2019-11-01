// //2019-9-5
// //思路：改天地伟业有点头蒙  抄一下代码 放松一下
// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> in, pre, post;
// bool unique = true;
// void getIn(int preLeft, int preRight, int postLeft, int postRight) {
//     if (preLeft == preRight) {
//         in.push_back(pre[preLeft]);
//         return;
//     }
//     if (pre[preLeft] == post[postRight]) {
//         int i = preLeft + 1;
//         while (i <= preRight && pre[i] != post[postRight - 1])
//             i++;
//         if (i - preLeft > 1)
//             getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
//         else
//             unique = false;
//         in.push_back(post[postRight]);
//         getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
//     }
// }

// int main() {
//     int n;
//     scanf("%d", &n);
//     pre.resize(n), post.resize(n);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &pre[i]);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &post[i]);
//     getIn(0, n - 1, 0, n - 1);
//     printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
//     for (int i = 1; i < in.size(); i++)
//         printf(" %d", in[i]);
//     printf("\n");
//     return 0;
// }

//2019-9-7
//思路：先输入 先不判断是否unique
//i是post中左根节点的终点 j是pre中右根节点的起点
//在中序函数中 先得到i j的序号 当preL == preR的时候 push return

#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, post;
vector<int> res;
bool unique = true;
void getIn(int preL, int preR, int postL, int postR) {
    if (preL > preR)
        return;
    if (pre[preL] == pre[preR]) {
        res.push_back(pre[preL]);
        return;
    }
    int i = 0, j = 0;
    while (post[i] != pre[preL + 1])
        i++;
    while (pre[j] != post[postR - 1])
        j++;
    if ( post[i] == pre[j] )
        unique = false;
    getIn(preL + 1, j - 1, postL, i);
    res.push_back(pre[preL]);
    getIn(j, preR, i + 1, postR - 1);
}
int main() {
    int n;
    cin >> n;
    pre.resize(n), post.resize(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];
    getIn(0, n - 1, 0, n - 1);
    if (unique)
        printf("Yes\n");
    else
        printf("No\n");
    printf("%d", res[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", res[i]);
    cout << endl;
    return 0;
}
//我去 最后加了个endl 满分！