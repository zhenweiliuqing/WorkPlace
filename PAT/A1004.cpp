//参考答案
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100];
int book[100], maxdepth = -1;
//又有一种dfs的变种
void dfs(int index, int depth)//核心代码
{
    if (v[index].size() == 0)//没有孩子
    {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return;
    }
    for (int i = 0; i < v[index].size(); i++)
    {
        dfs(v[index][i], depth + 1);
    }
}
//是看没有孩子的节点 就是叶子 在每一层有多少个 
int main()
{
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &node, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &c);
            v[node].push_back(c);//c是node的孩子
        }
    }
    dfs(1, 0);
    printf("%d", book[0]);
    for (int i = 1; i <= maxdepth; i++)
    {
        printf(" %d", book[i]);
    }
    return 0;
}