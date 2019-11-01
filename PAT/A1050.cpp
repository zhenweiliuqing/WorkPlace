//2019-2-27
# if 0
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i] == b[j])
            {
                a.erase(i, 1);
                break;
            }
        }
    }
    cout << a;
    return 0;
}
//15分
#endif

//参考答案
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char s1[100000], s2[100000];
int main()
{
    cin.getline(s1, 100000);
    cin.getline(s2, 100000);
    int lens1 = strlen(s1), lens2 = strlen(s2);
    bool flag[256] = {false};
    for (int i = 0; i < lens2; i++)
        flag[s2[i]] = true;
    for (int i = 0; i < lens1; i++)
        if (!flag[s1[i]])
            printf("%c", s1[i]);
    return 0;
}