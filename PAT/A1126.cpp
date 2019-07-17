// //2019-6-13
// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;
// int graph[501][501];
// vector<bool> visit;
// int count = 0;
// void dfs(int index){
//     visit[index] = true;
//     count++;
//     for (int i = 1; i < 501; i++)
//         if (graph[index][i] == 1 && visit[i] == false)
//             dfs(i);
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     int a, b;
//     visit.resize(n + 1);
//     map<int, int> mmap;
//     for (int i = 0; i < m; i++){
//         cin >> a >> b;
//         graph[a][b] = graph[b][a] = 1;//判断连通性
//         mmap[a]++;
//         mmap[b]++;
//     }
//     int cnt = 0;
//     auto it = mmap.begin();
//     if (it->second % 2 == 1)
//         cnt++;
//     cout << it->second;
//     it++;
//     while (it != mmap.end()){
//         cout << " " << it->second;
//         if (it->second % 2 == 1)
//             cnt++;
//         it++;
//     }
//     cout << endl;
//     dfs(1); //遍历看是否从一个顶点可以走完整幅图
//     if (cnt == 0 && count == n)
//         cout << "Eulerian";
//     else if (cnt == 2 && count == n)
//         cout << "Semi-Eulerian";
//     else
//         cout << "Non-Eulerian";
//     return 0;
// }
// //24分 还有一个测试点运行超时 有一个测试点就不是图 需要排除掉

#include <iostream>
#include <vector>
using namespace std;
vector<int> v[501];
vector<bool> visit;
int count = 0;
void dfs(int index){
    visit[index] = true;
    count++;
    for (int i = 0; i < v[index].size(); i++)
        if (!visit[v[index][i]])
            dfs(v[index][i]);
}
int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    visit.resize(n + 1);
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (i != 1)
            cout << " ";
        cout << v[i].size();
        if (v[i].size() % 2 == 1)
            cnt++;
    }
    cout << endl;
    dfs(1);
    if (cnt == 0 && count == n)
        cout << "Eulerian";
    else if (cnt == 2 && count == n)
        cout << "Semi-Eulerian";
    else
        cout << "Non-Eulerian";
    return 0;
}
//这个版本满分通过
//  vector<vector<int>> v;
//  vector<int> v[];没有区别