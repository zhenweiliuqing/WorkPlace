//2019-6-23
//离开母校 来天大的第一天
//解题思路：得递归求解 
// #include <iostream>
// #include <cmath>
// using namespace std;
// int max = 0;
// void recursive(float n, int k, int p){
//     int st = (int)pow(n, 1 / p);
//     recursive(n - pow(st, p), k - 1, p);
// }
// int main(){
//     float n, p;
//     int k;
//     cin >> n >> k >> p;
//     recursive(n, k, p);
// }

//参考答案
// 2019-9-13 回溯剪枝 是什么？
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
// n 169 k 5 p 2
void init(){
    int temp = 0, index = -1;
    while (temp <= n){
        v.push_back(temp);//为什么这么初始化 index为什么从-1开始
        temp = pow(index, p);// index得加到14 
        index++;
    }
}
// v 最后得能push到 169
void dfs(int index, int tempSum, int tempK, int facSum){
    if (tempK == k){
        if (tempSum == n && facSum > maxFacSum){
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }
    while (index >= 1){
        if (tempSum + v[index] <= n){
            tempAns[tempK] = index;
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);//递归式子 计算好平方的下标 累加的和 计数 最大值 真的是妙啊
        }
        if (index == 1)
            return;
        index--;
    }
}

int main(){
    scanf("%d%d%d", &n, &k, &p);
    init();
    tempAns.resize(k);
    dfs(v.size() - 1, 0, 0, 0);
    if (maxFacSum == -1){
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < ans.size(); i++){
        if (i != 0)
            printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}
