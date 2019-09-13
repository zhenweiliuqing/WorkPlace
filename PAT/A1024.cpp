//2019-1-23
#if 0
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPalin(string x)
{
    int i;
    for (i = 0; i < x.size() / 2; i++)
    {
        if (x[i] != x[x.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

string add2num(string x)
{
    int t = 0;
    for (int i = 0; i < x.size(); i++)
    {
        t += (x[i] - '0') * pow(10, i);
    }
    int sum = t + stoi(x);
    string res = to_string(sum);
    return res;
}

int main()
{
    string s = "69";
    int k = 3;
    //cin >> s >> k;
    string temp = s;
    for (int i = 0; i < k; i++)
    {
        if (isPalin(temp))//是回文数
        {
            cout << temp << endl;
            cout << i;
            return 0;
        }        
        temp = add2num(temp);
    }
    cout << temp << endl;
    cout << k;
    return 0;
}
#endif
//参考答案
#include <iostream>
#include <algorithm>
using namespace std;
string s;
void add(string t)
{
    int len = s.length(), carry = 0;//进位
    for (int i = 0; i < len; i++)
    {
        s[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        if (s[i] > '9')
        {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }//从高位网低位加 应该没区别 因为这两个数本来就是相反的
    if (carry)
        s += '1';
    reverse(s.begin(), s.end());//最后在翻一下就行了
}
int main()
{
    int cnt, i;
    cin >> s >> cnt;
    for (i = 0; i <= cnt; i++)
    {
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t || i == cnt)
            break;
        add(t);
    }
    cout << s << endl << i;
    return 0;
}