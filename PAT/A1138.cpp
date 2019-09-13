// //2019-7-5
// //参考答案
// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> pre, in;
// bool flag = false;
// void post(int root, int start, int end){
//     if (start > end || flag == true)
//         return;
//     int i = start;
//     while (in[i] != pre[root])
//         i++;
//     post(root + 1, start, i - 1);
//     post(root + 1 - start + i, i + 1, end);//i - start是左子树的宽度
//     if (flag == false){
//         printf("%d", in[i]);
//         flag = true;
//     }
// }
// int main(){
//     int n;
//     scanf("%d", &n);
//     pre.resize(n);
//     in.resize(n);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &pre[i]);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &in[i]);
//     post(0, 0, n - 1);//是以先序遍历为基础的 root为根 为什么呢？
//     return 0;
// }

//2019-7-16
#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in;
vector<int> res;
int index = 0;
void post(int preroot, int inl, int inr){
    if (inl > inr)
        return;
    int inroot = inl;
    while (inroot < inr && pre[preroot] != in[inroot])
        inroot++;
    post(preroot + 1, inl, inroot -1);
    post(preroot + 1 + inroot - inl, inroot + 1, inr);
    res[index++] = pre[preroot];
}
int main(){
    int n;
    cin >> n;
    pre.resize(n), in.resize(n), res.resize(n);
    int temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        pre[i] = temp;
    }
    for (int i = 0; i  < n; i++){
        cin >> temp;
        in[i] = temp;
    }
    post(0, 0, n - 1);
    cout << res[0];
    return 0;
}
//虽然有点麻烦 但还是全对了