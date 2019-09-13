//2019-3-18

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string a,b;
    getline(cin, b);
    getline(cin, a);
    bool flag[256] = {false};
    for (int i = 0; i < a.length(); i++)
    {
        flag[int(a[i])] = true;//这个可以把他转化为ASCII值
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (flag[int(b[i])])
            b.erase(i, 1);
    }
    cout << b;
    return 0;
}
