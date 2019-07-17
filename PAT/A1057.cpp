//2019-3-22

#if 0
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

const string pop = "Pop";
const string peek = "PeekMedian";

int main()
{
    int n;
    scanf("%d", &n);
    string temp;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == pop)
        {
            if (s.size() != 0)
                s.pop();
            else
                printf("Invalid\n");
        }
        else if (temp == peek)
        {
            vector<int> v;
            for (int j = 0; j < s.size(); j++)
            {
                v.push_back(s[j]);
            }
        }
    }
}
#endif

#include <iostream>
#include <stack>
#define lowbit(i) ((i) & (-i)) //等于2的k次方 k为从低位到高位数连续0的个数 
//用来查中值 如果用排序的话 会超时
const int maxn = 100010;
using namespace std;
int c[maxn];
stack<int> s;
void update(int x, int v)//更新应该是建立树状数组
{
    for (int i = x; i < maxn; i += lowbit(i))
    {
        c[i] += v;
    }
}

int getsum(int x)//这个是计算某一位的和
{
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
    {
        sum += c[i];
    }
    return sum;
}
//二分法查中值
void PeekMedian()
{
     int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        if (str[1] == 'u')
        {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);//这里的东西没看懂
        }
        else if (str[1] == 'o')
        {
            if (!s.empty())
            {
                update(s.top() , -1);
                printf("%d\n", s.top());
                s.pop();
            }
            else  
            {
                printf("Invalid\n");
            }
        }
        else  
        {
            if (!s.empty())
                PeekMedian();
            else
                printf("Invalid\n");
        }
    }
    return 0;
}