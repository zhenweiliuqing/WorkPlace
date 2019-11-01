//2018-8-20 16:14
#if 0
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num;
    cin >> num; //输入个数
    vector<int> v(num);
    vector<bool> FLAG(num); //默认全为false
    int a;
    for (int i = 0; i < num; i++)
    {
        cin >> a;
        v[i] = a;
        FLAG[i] = true;
        for (int j = 0; j < i; j++)
        {
            if (a == v[j])
            {
                FLAG[i] = FLAG[j] = false;
                break;
            }
        }
    }
    int i;
    for (i = 0; i < num; i++)
    {
        if (FLAG[i] == true)
        {
            cout << v[i];
            break;
        }
    }
    if (i == num)
        cout << "None";
    return 0;
}
//16:42
//16points! 最后两个运行超时！
#endif
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;//输入个数
    cin >> n;
    int m;//输入数值
    vector<int> range(10001,-1);
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (range[m] == -1)//第一次
        {
            range[m] = m;
            continue;
        }
        if (range[m] == m)
        {
            range[m] = 0;//表明重复
        }
    }

    for (int i = 0; i < 10001; i++)
    {
        if (range[i] > 0)
        {
            cout << range[i];
            break;
        }
        if (i == 10000)
            cout << "None";
    }
    return 0;
}