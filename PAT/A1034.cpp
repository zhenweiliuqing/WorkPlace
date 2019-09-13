//2019-2-5
//团伙 3个人及以上 之间通话记录时间大于阈值 通话时间最长的是老大
#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct member
{
    string name;
    int time;
};
using namespace std;
int main()
{
    int n, k;
    int num = 0;//队伍数
    scanf("%d %d", &n, &k);
    string s1, s2;
    int time;
    vector<member> v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2 >> time;
        v[]
    }
}
//想想怎么搞一个数据结构把相关的人的名字搞进去 每个人的时间也搞进去
//每个人的名字 还得 查重 分到自己对应的组里边去
#endif

//参考答案
#include <iostream>
#include <map>
using namespace std;
map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> ans;
int idNumber = 1, k;
int stoifunc(string s)
{
    if (stringToInt[s] == 0)//stringToInt 里下标是string 里边存储的内容是 int
    {
        stringToInt[s] = idNumber;//
        intToString[idNumber] = s;
        return idNumber++;
    }
    else 
    {
        return stringToInt[s];
    }
}
int G[2010][2010], weight[2010];
bool vis[2010];
void dfs(int u, int &head, int &numMember, int &totalweight)
{
    vis[u] = true;
    numMember++;
    if (weight[u] > weight[head])//谁的权重大谁当头
    {
        head = u;
    }
    for (int v = 1; v < idNumber; v++)
    {
        if (G[u][v] > 0)//有连接
        {
            totalweight += G[u][v];//总权重加进来
            G[u][v] = G[v][u] = 0;//权重置为0
            if (vis[v] == false)
                dfs(v, head, numMember, totalweight);
        }
    }
}
void dfsTrave()
{
    for (int i = 1; i < idNumber; i++)
    {
        if (vis[i] == false)//如果i没有被访问过
        {
            int head = i, numMember = 0, totalweight = 0;//初始头就是i
            dfs(i, head, numMember, totalweight);
            if (numMember > 2 && totalweight > k)
                ans[intToString[head]] = numMember;
        }
    }
}

int main()
{
    int n, w;
    cin >> n >> k;//输入数量跟阈值
    string s1, s2;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2 >> w;//输入两个人名 跟 通话时间
        int id1 = stoifunc(s1);//转化成id号
        int id2 = stoifunc(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    dfsTrave();//妙啊！
    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}

#if 0
//这题估计得用深度优先搜索 分团 
#include <iostream>
#include <map>
using namespace std;
map<string, int> stringToInt;
map<int, string> intToString;
int idNumber = 1;

int stoifunc(string s)
{
    if (stringToInt[s] == 0)
    {
        stringToInt[s] = idNumber;
        intToString[idNumber] = s;
        return idNumber++;
    }
    else
    {
        return stringToInt[s];
    } 
}
int G[1010][1010];//图之间的连通性
int time[1010];//每个节点的时间
bool visit[1010];
void dfs(int u, int &head, int &numMember, int &totalweight)
{
    visit[u] = true;
    numMember++;
    if (time[u] > time[head])
        head = u;
    for (int i = 1; i < idNumber; i++)
    {
       
        if (G[u][i] > 0 && !visit[i])
        {
            totalweight += G[u][i];
            dfs(i, head, numMember, totalweight);
        }
    }
}
void dfsTrave()
{
    for (int i = 1; i < idNumber; i++)//小于节点数
    {
        if (!visit[i])
        {
            int head = i, numMember = 0, totalweight = 0;
            dfs(i, head, numMember, totalweight);
        }
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    string s1, s2;
    int w;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2 >> w;
        int id1 = stoifunc(s1);
        int id2 = stoifunc(s2);
        G[id1][id2] += w;
        G[id2][id1] += w;
        time[id1] += w;
        time[id2] += w;
    }
    dfsTrave();
}
//没写完 下次接着写
#endif