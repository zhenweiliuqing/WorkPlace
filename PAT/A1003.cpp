//2018-8-22 16：12

#include <iostream>
#include <vector>
using namespace std;
const int inf = 99999999;
int main()
{
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    vector<int> teams(n);
    for (int i = 0; i < n; i++)
    {
        cin >> teams[i]; //输入每个城市救援的队伍数
    }
    int a, b, c;
    vector<vector<int>> graph(n, vector<int>(n, -1)); //n*n数组,初始值为-1
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c; //更新连接的权值
    }

    vector<int> dis(n, inf); //从初始点到每个城市的距离
    dis[c1] = 0;
    vector<bool> visit(n, false);
    vector<int> road_num(n);
    road_num[c1] = 1;
    vector<int> team_num(n);
    team_num[c1] = teams[c1];
    //开始核心算法
    for (int i = 0; i < n; i++)
    {
        //先找到次优点u
        int u = -1, min = inf;
        for (int j = 0; j < n; j++)
        {
            if (!visit[j] && dis[j] < min) //该点未访问 && 从初始点到j的距离最小
            {
                u = j;        //点更新
                min = dis[j]; //距离更新为最小
            }
        }

        if (u == -1) //所有点都被访问过 或者 初始点到该城市的距离无穷大
            break;
        visit[u] = true;

        //从次优点出发遍历所有未访问过的节点 计算初始点到这的距离 以及 路上的救援队数
        for (int k = 0; k < n; k++)
        {
            if (!visit[k] && graph[u][k] != -1) //k点未访问过 且 u,k有连接
            {
                if (dis[k] > dis[u] + graph[u][k])
                {
                    dis[k] = dis[u] + graph[u][k];        //距离更新为最短
                    team_num[k] = team_num[u] + teams[k]; //队伍数得加上这个城市有的队伍
                    road_num[k] = road_num[u];            //路还是原来那条路
                }
                else if (dis[k] == dis[u] + graph[u][k]) //如果原来到这个城市的路径（已经是最短）等于新的路径 那么最短路径就增加了road_num[u]
                {
                    road_num[k] += road_num[u];
                    if (team_num[k] < team_num[u] + teams[k])
                        team_num[k] = team_num[u] + teams[k];
                }
            }
        }
    }
    cout << road_num[c2] << " " << team_num[c2];
    return 0;
}

//17:22

//22:57

#include <algorithm>
#include <iostream>
using namespace std;
int n, m, c1, c2;
const int inf = 99999999;
int teams[510];      //每个城市救援队数
int graph[510][510]; //邻接矩阵

int dis[510];      //距离???
int road_num[510]; //有几条路？？？
int team_num[510]; //有多少救援队伍？？？
bool visit[510];

int main()
{
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
    {
        cin >> teams[i];
    }
    fill(graph[0], graph[0] + 510 * 510, inf);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c; //输入权重
    }
    fill(dis, dis + 510, inf);
    dis[c1] = 0;
    team_num[c1] = teams[c1];
    road_num[c1] = 1;
    for (int i = 0; i < n; i++)
    {
        int u = -1, min = inf;      //u是次优出发点
        for (int j = 0; j < n; j++) //找到局部最优点u
        {
            if (visit[j] == false && dis[j] < min) //第一次是靠后边这个条件选中c1 min是选择当前符合条件的最小值 局部最优
            {
                u = j;
                min = dis[j];
            }
        }

        if (u == -1)
            break;
        visit[u] = true;

        for (int k = 0; k < n; k++) //局部最优点对所有未访问点的距离操作
        {
            if (visit[k] == false && graph[u][k] != inf) //没访问过 有链接
            {
                if (dis[u] + graph[u][k] < dis[k]) //dis[k]初始时是无穷大
                {
                    dis[k] = dis[u] + graph[u][k];
                    road_num[k] = road_num[u];
                    team_num[k] = team_num[u] + teams[k]; //这条路上之前累计的救援队数加上在本城市的救援队数
                }
                else if (dis[u] + graph[u][k] == dis[k])
                {
                    road_num[k] += road_num[u];
                    if (team_num[u] + teams[k] > team_num[k]) //两条路的救援队伍数的比较
                    {
                        team_num[k] = team_num[u] + teams[k];
                    }
                }
            }
        }
    }
    return 0;
}