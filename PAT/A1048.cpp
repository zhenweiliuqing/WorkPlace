//2019-1-30
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, money;
    scanf("%d%d", &n, &money);
    vector<int> coin(501);
    vector<int> result;
    int single;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &single);
        coin[single] = 1;//有的这枚硬币标志位为1
    }
    for (int i = 1; i <= money / 2; i++)
    {
        if (coin[i] == 1 && coin[money - i] == 1)
        {
            result.push_back(i);
            result.push_back(money - i);
        }
    }
    if (result.size() != 0)
    {
        sort(result.begin(), result.end());
        cout << result[0] << " " << money - result[0];
    }
    else
        cout << "No Solution";
    return 0;
}
//23分！ 怎么会有答案错误呢???