//2019-1-28
#if 0
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    vector<int> v;
    int max = 0;
    
    for (int i = 1; i < s.size() - 1;i++)
    {
        if (s[i - 1] == s[i + 1])
            v.push_back(i);
    }
    int j, k;
    for (int i = 0; i < v.size(); i++)
    {
        int length = 0;
        for (j = v[i] + 1, k = v[i] - 1; j < s.size(), k >= 0;j++,k--)
        {
            if (s[j] == s[k])
                length += 2;
        }
        if (length > max)
            max = length;
    }
    cout << max + 1;
}
//部分正确！！ 19分  估计是没有解决偶数个的问题
#endif

//参考答案
#include <iostream>
using namespace std;
int dp[1010][1010];//这个数组是干什么用的？？？
int main()
{
    string s;
    getline(cin, s);
    int len = s.length(), ans = 1;
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;//对角线是1
        if (i < len - 1 && s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;//是用来判断连字符的吗？
            ans = 2;
        }
    }
    //下面这一段是是核心代码
    for (int L = 3; L <= len; L++)
    {
        for (int i = 0; i + L - 1 < len; i++)
        {
            int j = i + L - 1;//这是末尾那个字符
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1)//这是要扩展 = 1说明这两个字母相等
            {
                dp[i][j] = 1;  
                ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
