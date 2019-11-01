//2019-1-27
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int m, n;
    vector<int> v1, v2;
    int nc, np;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> nc;
        v1.push_back(nc);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> np;
        v2.push_back(np);
    }
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    long long res;
    
}
#endif

//参考答案
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int m, n, ans = 0, p = 0, q = 0;
    scanf("%d", &m);
    vector<int> v1(m);
    for (int i = 0; i < m; i++)
        scanf("%d", &v1[i]);
    scanf("%d", &n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v2[i]);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    while (p < m && q < n && v1[p] < 0 && v2[q] < 0)
    {
        ans += v1[p] * v2[q];
        p++;
        q++;
    }
    p = m - 1, q = n - 1;
    while (p >= 0 && q >= 0 && v1[p] > 0 && v2[q] > 0)
    {
        ans += v1[p] * v2[q];
        p--;
        q--;
    }

}