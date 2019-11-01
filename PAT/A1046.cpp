//2019-1-19

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m;//输入5个数
    vector<int> dis(m);
    int round = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> dis[i];
        round += dis[i];
    }
    cin >> n;//输出行数
    int x1, x2;
    for (int i = 0; i < n; i++)
    {
		int sum = 0;
        cin >> x1 >> x2;
        if (x1 < x2)
        {
            for (int j = x1; j < x2; j++)
            {
                sum += dis[j - 1];
            }
        }
        else 
        {
            for (int j = x2; j < x1; j++)
            {
                sum += dis[j - 1];
            }
        }
        if (sum < round/2)
            cout << sum << endl;
        else
            cout << round - sum << endl;
    }

    return 0;
}
//非常开心的拿了满分？？？？