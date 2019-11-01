//2019-1-23
//这道题估计得用到深度优先搜索
/*    
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> flag;
    for (int i = 0; i < n; i++)
}
*/

//参考答案

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, maxheight = 0;
vector<vector<int>> v;
bool visit[10010];//默认的是false？
set<int> s;
vector<int> temp;
void dfs(int node, int height)
{
    if (height > maxheight)
    {
        temp.clear();//把之前认为是最深的给清除掉 加上这次的 
        temp.push_back(node);
        maxheight = height;
    }
    else if (height == maxheight)
    {
        temp.push_back(node);
    }
    //这四行是深度优先遍历的精髓
    visit[node] = true;
    for (int i = 0; i < v[node].size(); i++)//这个节点有几个连接点
    {
        if (visit[v[node][i]] == false)//未访问过且有连接
            dfs(v[node][i], height + 1);//从新的连接递归 深度加1
    }
}
int main()
{
    scanf("%d", &n);
   // n = 5;
    v.resize(n + 1);//重置的应该是外边那一层
    int a, b, cnt = 0, s1 = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }//连接矩阵
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false)
        {
            dfs(i, 1);//先从1深度优先遍历 初始深度为1
            if (i == 1)//如果是一棵树 连在一起
            {
                if (temp.size() != 0)
                    s1 = temp[0];//这个s1是神来之笔啊 s1必定是一个根
                for (int j = 0; j < temp.size(); j++)
                    s.insert(temp[j]);
            }
            cnt++;
        }
    }
    if (cnt >= 2)
        printf("Error: %d components", cnt);
    else 
    {
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);//核心代码 怎么就深度遍历完了 并且还把最深的根存到了temp里
        //为什么从s1开始遍历  
        //从s1顺藤摸瓜 
        for(int i = 0; i < temp.size(); i++)
            s.insert(temp[i]);//这个里面只有两个 原来还有一个
        for (auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}