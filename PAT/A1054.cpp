//2019-3-21
//只要超过半数就可以退出了 
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    map<int, int> x;
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &temp);
            x[temp]++;
            if (x[temp] > (m * n / 2))
            {
                cout << temp;
                return 0;
            }
        }
    }
}
//竟然有18分 有一个测试点是超时了
//把cin 换成 scanf就很开心的解决了