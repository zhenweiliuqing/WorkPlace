// //2019-6-23
// //离开母校 来天大的第一天
// //解题思路：得递归求解 
// // #include <iostream>
// // #include <cmath>
// // using namespace std;
// // int max = 0;
// // void recursive(float n, int k, int p){
// //     int st = (int)pow(n, 1 / p);
// //     recursive(n - pow(st, p), k - 1, p);
// // }
// // int main(){
// //     float n, p;
// //     int k;
// //     cin >> n >> k >> p;
// //     recursive(n, k, p);
// // }

// //参考答案
// // 2019-9-13 回溯剪枝 是什么？
// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;
// int n, k, p, maxFacSum = -1;
// vector<int> v, ans, tempAns;
// // n 169 k 5 p 2
// void init(){
//     int temp = 0, index = -1;
//     while (temp <= n){
//         v.push_back(temp);//为什么这么初始化 index为什么从-1开始
//         temp = pow(index, p);// index得加到14 
//         index++;
//     }
// }
// // v 最后得能push到 169
// void dfs(int index, int tempSum, int tempK, int facSum){
//     if (tempK == k){
//         if (tempSum == n && facSum > maxFacSum){
//             ans = tempAns;
//             maxFacSum = facSum;
//         }
//         return;
//     }
//     while (index >= 1){
//         if (tempSum + v[index] <= n){
//             tempAns[tempK] = index;
//             dfs(index, tempSum + v[index], tempK + 1, facSum + index);//递归式子 计算好平方的下标 累加的和 计数 最大值 真的是妙啊
//         }
//         if (index == 1)
//             return;
//         index--;
//     }
// }

// int main(){
//     scanf("%d%d%d", &n, &k, &p);
//     init();
//     tempAns.resize(k);
//     dfs(v.size() - 1, 0, 0, 0);
//     if (maxFacSum == -1){
//         printf("Impossible");
//         return 0;
//     }
//     printf("%d = ", n);
//     for (int i = 0; i < ans.size(); i++){
//         if (i != 0)
//             printf(" + ");
//         printf("%d^%d", ans[i], p);
//     }
//     return 0;
// }

// 2019-12-5
// 思路: 先建立一个对照的平方的数组 
// 然后从最大的开始进行深度优先搜索 判断是否满足条件 
// 然后依次深入递归
// 关键是找到结束递归的条件 进入递归的参数 从哪里进入递归 不满足条件返回到哪里
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> square, res, tempres;
int max_sumIndex = -1;
int n, k, p;
void init() {
    int index = 1, temp = 0;
    while (temp <= n) {
        square.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}
// 不懂
// void dfs(int index, int sum, int knum, int sumIndex) {
//     if (knum > k || sum > n)
//         return;
//     if (sum == n) {
//         if (knum == k && sumIndex > max_sumIndex) {
//             res = tempres;
//             max_sumIndex = sumIndex;
//         }
//         return;
//     }

//     while (index > 0) {
//         tempres.push_back(index);
//         for (int i = index; i > 0; i--) {
//             dfs(i, sum + square[index], knum + 1, sumIndex + i);
//         }
//         tempres.pop_back();
//         if (index == 1)
//             return;
//         index--;
//     }
// }
// 还是自己写的容易懂
void dfs(int i, int sum,int sumIndex){
    sum += square[i];
    sumIndex += i;
    tempres.push_back(i);
    if (sum > n || tempres.size() > k) {
        tempres.pop_back();
        return;
    }
    if (sum == n) {
         if (tempres.size() == k && sumIndex > max_sumIndex) {
             res = tempres;
             max_sumIndex = sumIndex;
         }
         tempres.pop_back();
         return;
    }

    for (int j = i; j > 0; j--) {
        dfs(j, sum, sumIndex);
    }
    tempres.pop_back();
}
int main () {
    cin >> n >> k >> p;
    init();
    for (int i = square.size() - 1; i > 0; i--)
        dfs(i, 0, 0);
    if (max_sumIndex == -1){
        printf("Impossible");
        return 0;
    }
    printf("%d = %d^%d", n, res[0], p);
    for (int i = 1; i < res.size(); i++)
        printf(" + %d^%d", res[i], p);
    return 0;
}
// 27分 段错误
// Impossible 满分！！！