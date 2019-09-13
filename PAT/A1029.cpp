//2019-1-25
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(long long a, long long b)
{
    return a < b;
}
int main()
{
    int n, m;
    long long a;
    vector<long long> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a);
        v.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[(v.size() - 1) / 2];
}
//内存超限 只拿到16分。
*/

//参考答案
#include <iostream>
using namespace std;
int k[200005];
int main()
{
    int n, m, temp, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k[i]);
    }
    k[n + 1] = 0x7fffffff;
    cin >> m;
    int midpos = (n + m + 1) / 2, i = 1;
    for (int j = 1; j <= m; j++)
    {
        scanf("%d", &temp);
        while(k[i] < temp)
        {
            count++;
            if (count == midpos)
                cout << k[i];
            i++;
        }
        count++;
        if (count == midpos)
            cout << temp;
    }
    while (i <= n)//神机妙算吧 这个count一定要算准了！
    {
        count++;
        if (count == midpos)
            cout << k[i];
        i++;
    }
    return 0;
}