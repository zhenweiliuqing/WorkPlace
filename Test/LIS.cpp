//最长上升子序列 dp数组是只能输出子序列的长度 
//就像01背包问题 最后只能输出 最大的价值 要想知道都有什么元素 还得更复杂一些

#include <iostream>
using namespace std;
int dp[100];
int main()
{
    int n;
    cin >> n;
    int *x = new int[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        dp[i] = 1;
        //判断的条件是不是有些冗余了 
        for (int j = 1; j < i; j++)//感觉也没用到动态规划的思想啊
        {
            if (x[i] >= x[j])
                dp[i] = max(dp[j] + 1, dp[i]);//这跟dp[i]++有区别吗
        }
    }
    delete[] x;
}