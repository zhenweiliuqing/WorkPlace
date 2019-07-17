//2019-6-29
//思路：使用深度优先搜索 先输入 找到根节点
//从根节点进行深度遍历 记录深度及最小深度的数量 直到没有节点为止
//先不考虑设置超过最小深度跳出的操作 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v[100005];
int min_depth = 99999999;
int min_num = 1;
void dfs(int root, int depth){
    if (min_depth < depth)
        return;
    if (v[root].size() == 0)//没有子节点
    {
        if (min_depth > depth){
            min_depth = depth;
            min_num = 1;
        }
        else if (min_depth == depth)
            min_num++;
    }   
    for (int i = 0; i < v[root].size(); i++){
            dfs(v[root][i], depth + 1);
    }
}
int main(){
    int n;
    double price, rate;
    cin >> n >> price >> rate;
    int num, temp;
    for (int i = 0; i < n; i++){
        cin >> num;
        for (int j = 0; j < num; j++){
            cin >> temp;
            v[i].push_back(temp);
        }
    }
    dfs(0, 0);
    printf("%.4f %d", price * pow((1 + rate / 100), min_depth), min_num);
    return 0;
}
//第一次11分
//最下边搞错了 min_depth 17分
//float改成double  满分！