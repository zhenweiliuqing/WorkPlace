//2019-3-19
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    int temp;
    for (int i = 0; i < k; i++)
    {
        queue<int> q;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            q.push(temp);
            //scanf("%d", &temp[j]);//先把要输出的结果存进去
        }

        stack<int> s;
        for (int t = 1; t <= n; t++)
        {
            s.push(t);
            while (s.top() == q.front() && s.size() <= m )
            {
                q.pop();
                s.pop();
                if (q.size() == 0 || s.size() == 0)
                    break;
            }
        }
        if (s.size() == 0 && q.size() == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
//只有两个测试点对 3 分 还有一个问题是 一起输入是错的 单独输入是对的
//果然是queue的位置不对 改了之后 全部正确！