//最长公共子序列问题
#include <iostream>
#include <string>
using namespace std;
int dp[100][100];//字符串设为100吧
int main()
{
    string a, b;
    cin >> a >> b;
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1]) //递推关系式才是关键 我还是没搞清
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);//dp[i][j-1]有用吗 啊 有用 他们分别保证了 第一行和第一列的正确性
        }
    }
    cout << dp[a.size()][b.size()];
    return 0;
}
