#if 0

//2018-8-23 21：25
//主要采用new二级指针 存储邻接矩阵！！！
#include <iostream>
#include <vector>
using namespace std;
const int inf = 0;
int DFS(int** map, int n, int city) //如何只把地址传过来呢
{
    for (int j = 0; j < n; j++)
        map[city - 1][j] = map[j][city - 1] = 0; //与其他城市断绝联系
    //开始深度优先搜索算法
    vector<bool> visit(n, false);
    vector<vector<int>> equaList;
    vector<int> tempList;
    for (int i = 0; i < n; i++)
    {
        if (visit[i]) //该节点访问过
        {
            continue;
        }
        visit[i] = true;
        tempList.push_back(i);
        for (int j = 0; j < tempList.size(); j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (map[tempList[j]][k] == 1 && !visit[k])
                {
                    tempList.push_back(k);
                    visit[k] = true;
                }
            }
        }
        equaList.push_back(tempList);
        tempList.clear();
    }
    return equaList.size();
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    //我还是用邻接矩阵存储连通量吧
    //vector<vector<int>> map(n, vector<int>(n, inf)); //map挺好但是如何 像指针那样传递呢
    //如何用new产生二级指针呢？？？
    int **map = new int *[n];
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            map[i][j] = 0;
        }
    }
    int c1, c2;
    for (int i = 0; i < m; i++)
    {
        cin >> c1 >> c2;
        map[c1 - 1][c2 - 1] = map[c2 - 1][c1 - 1] = 1;
    }

    int city;
    int num;
    int **map_copy = new int*[n];
    for (int i = 0; i < n; i++)
    {
        map_copy[i] = new int[n];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> city;

        //map_copy = map;//还是原来的地址
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k ++)
                map_copy[j][k] = map[j][k];
        num = DFS(map_copy, n, city);
        cout << num - 2 << endl;
    }

    return 0;
}
//最后一个测试点超时！
//两种方案都超时 采用双vector 或 new 二级指针！
#endif

//参考
#if 1
#include <iostream>
#include <algorithm>
using namespace std;
int v[1010][1010];
bool visit[1010];
int n;
void dfs(int node)
{
    visit[node] = true;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false && v[node][i] == 1)
            dfs(i);
    }
}
int main()
{
    int m, k, a, b;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a][b] = v[b][a] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        fill(visit, visit + 1010, false);
        cin >> a;
        int cnt = 0;
        visit[a] = true;
        for (int j = 1; j <= n; j++)
        {
            if (visit[j] == flase)
            {
                dfs(j);
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}
#endif