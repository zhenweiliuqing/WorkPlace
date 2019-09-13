//2019-2-5
#if 0
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp()
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {

    }
}
有一种可行的思路是比较大小 不足的位用首字母补齐
#endif

//参考答案
#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a, string b)
{
    return a + b < b + a;
}
string str[10010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    string s;
    for (int i = 0; i < n; i++)
    {
        s += str[i];
    }
    while (s.length() != 0 && s[0] == '0')
    {
        s.erase(s.begin());
    }
    if (s.length() == 0)
        cout << 0;
    cout << s;
    return 0;
}
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool cmp(string a, string b)
{
    return a + b < b + a;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    string res;
    for (int i = 0; i < n; i++)
    {
        res += v[i];
    }
    while (res[0] == '0')
        res.erase(0, 1);
    if (res.length() == 0)
      cout << 0;
    else 
      cout << res;
}
//最后那一点 得了 7分！