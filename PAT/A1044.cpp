//2019-1-29
#if 0
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; sum < n; j++)
        {
            sum += v[j];
            if (sum == n)
            {
                cout << i + 1 << "-" << j + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
#endif
//10分 运行超时 段错误？？

#include <iostream>
#include <vector>
using namespace std;
vector<int> sum, resultArr;
int n, m;
void Func(int i, int &j, int &tempsum)//这个j是什么存在?
{
    int left = i, right = n;//初始的right就是到最后一块钻石
    while (left < right)
    {
        int mid = (left + right) / 2;//我这个序列是累加和 所以 我right-left是这段钻石的价钱
        if (sum[mid] - sum[i-1] >= m)//sum[i-1]是把第i个包括进去了 这才是 从第i个钻石到第mid个钻石的价钱
        {                            //sum[i-1]是固定的   
            right = mid;
        }
        else 
        {
            left = mid + 1;
        }
    }
    j = right;//j是每次的右边界
    tempsum = sum[j] - sum[i - 1];
}

int main()
{
    scanf("%d%d", &n, &m);
    sum.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];//在输入的时候就进行累加
    }
    int minans = sum[n];//累加的和
    for (int i = 1; i <= n; i++)
    {
        int j, tempsum;
        Func(i, j, tempsum);
        if (tempsum >= m)
        {
            if (tempsum < minans)
            {
                resultArr.clear();
                minans = tempsum;//选一个能支付的最低价钱
            }
            resultArr.push_back(i);
            resultArr.push_back(j);
        }
    }
    for (int i = 0; i < resultArr.size(); i+=2)
    {
        printf("%d-%d\n", resultArr[i], resultArr[i + 1]);
    }
    return 0;
}