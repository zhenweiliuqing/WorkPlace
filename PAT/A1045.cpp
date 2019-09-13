//2019-2-1
#if 0
//参考答案
#include <iostream>
#include <vector>
using namespace std;
int book[201], a[10001], dp[10001];
int main()
{
    int n, m, x, l, num = 0, maxn = 0;
    scanf("%d %d", &n, &m);//n种颜色 m种喜欢的颜色
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        book[x] = i;//给输入的元素标上序号 小的说明优先级高
    }
    scanf("%d", &l);//已有的颜色序列
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &x);
        if (book[x] >= 1)
            a[num++] = book[x];//把喜欢颜色的序号 给挑出来 不是颜色 过滤掉了不喜欢的颜色
    }
    for (int i = 0; i < num; i++)//这段代码是核心 就是求最长上升子序列
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] >= a[j])//a[i]是后边的数每次要跟前面的数挨个比较大小 
            {
                dp[i] = max(dp[i], dp[j] + 1);//a[i]的次序dp[i]初始为1 如果满足递增条件 看前面那个数的次序加1是不是更大 如果更大 则替换 
            }
        }
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}
//a  1 1 3 4 4 5 2 3 3 4 5
//dp 1 2 3 4 5 6 3 4 5 6 7
#endif

//最长上升子序列
#include <iostream>
#include <vector>
using namespace std;
int color[201];
int dp[10010];
int main()
{
    int n, m;
    int t, fav_color;
    cin >> n;//一共是n种颜色
    cin >> fav_color;
    int id = 1;
    for (int i = 0; i < fav_color; i++)
    {
        cin >> t;
        color[t] = id++;
    }
    cin >> m;
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        if (color[t] >= 1)
            v.push_back(t);
    }
    //已经把准备工作做完了 把不喜欢的颜色给滤除掉
    int max = 0;
    for (int i = 0; i < v.size(); i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (color[v[j]] <= color[v[i]])//递增
            {
                dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : dp[j] + 1;
            }
        }
        if (dp[i] > max)
            max = dp[i];
    }
    cout << max;
    return 0;
}
//满分！