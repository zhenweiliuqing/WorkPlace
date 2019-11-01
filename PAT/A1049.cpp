//2019-1-31
#if  0
//参考答案
#include <iostream>
using namespace std;
int main()
{
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    n = 1024;
    //scanf("%d", &n);
    while (n / a)
    {
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if (now == 0)
            ans += left * a;//left * a
        else if (now == 1)
            ans += left * a + right + 1;//左边left次 要乘上 位数 右边 right次加上 0那一次
        else
            ans += (left + 1) * a;//左边有left+1次1，右边又重复的从1-9出现
        a = a * 10;
    }
    printf("%d", ans);
    return 0;
}
#endif

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string n;
    cin >> n;
    n = " " + n + " ";
    int num = 0;
    string l, r;
    int left, right;
    int flag = 1;
    
    for (int i = n.length() - 2; i >= 1; i--)
    {
        l = n.substr(0, i);
        r = n.substr(i + 1);//不好截取啊
        if (l == " ")
            left = 0;
        else
            left = stoi(l);
        if (r == " ")
            right = 0;
        else
            right = stoi(r);

        if (n[i] == '0')
            num += left * flag;
        else if (n[i] == '1')
            num += left * flag + right + 1;
        else
            num += (left + 1) * flag;
        flag *= 10;
    }
    cout << num;//nm = 338!
    return 0;
}

//哈哈  劳动人民的智慧是无穷的！！