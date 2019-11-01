// //2019-7-21
// //参考答案
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// vector<vector<int>> v(10000);
// int visit[10000], minCnt, minTransfer, start, end1;
// unordered_map<int, int> line;
// vector<int> path, tempPath;
// int transferCnt(vector<int> a) {
//     int cnt = -1, preLine = 0;
//     for (int i = 1; i < a.size(); i++) {
//         if (line[a[i - 1] * 10000 + a[i]] != preLine)
//             cnt++;
//         preLine = line[a[i - 1] * 10000 + a[i]];
//     }
//     return cnt;
// }
// void dfs(int node, int cnt) {
//     //这里得保证到达了终点 且 总站数最小 当总站相等时 要保证换乘站最少 
//     if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
//         minCnt = cnt;
//         minTransfer = transferCnt(tempPath);
//         path = tempPath;
//     }
//     if (node == end1)
//         return;
//     for (int i = 0; i < v[node].size(); i++) {
//         if (visit[v[node][i]] == 0) {
//             visit[v[node][i]] = 1;
//             tempPath.push_back(v[node][i]);
//             dfs(v[node][i], cnt + 1);
//             visit[v[node][i]] = 0;
//             tempPath.pop_back();//这后边两句真的是琢磨不透
//         }
//     }//这样是不是把所有的路径都给找了出来
// }
// int main() {
//     int n, m, k, pre, temp;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++){
//         scanf("%d%d", &m, &pre);
//         for (int j = 1; j < m; j++) {
//             scanf("%d", &temp);
//             v[pre].push_back(temp);
//             v[temp].push_back(pre);
//             line[pre * 10000 + temp] = line[temp * 10000 + pre] = i + 1;//一条线上的车站连着的
//             pre = temp;
//         }
//     }
//     scanf("%d", &k);
//     for (int i = 0; i < k; i++) {
//         scanf("%d%d", &start, &end1);
//         minCnt = 99999, minTransfer = 99999;
//         tempPath.clear();
//         tempPath.push_back(start);
//         visit[start] = 1;
//         dfs(start, 0);
//         visit[start] = 0;
//         printf("%d\n", minCnt);
//         int preLine = 0, preTransfer = start;
//         for (int j = 1; j < path.size(); j++) {
//             if (line[path[j - 1] * 10000 + path[j]] != preLine) {
//                 if (preLine != 0)
//                     printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j - 1]);
//                 preLine = line[path[j - 1] * 10000 + path[i]];
//                 preTransfer = path[j - 1];
//             }
//         }
//         printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
//     }
//     return 0;
// }

//2019-8-22
//思路：采用什么数据结构 如果是图 一般都是邻接链表 便于进行深度优先搜索
//     采用什么数据结构能得到换乘站的信息 还得知道哪个站位于几号线上 
//     利用一个结构体 里边有isTransfer 和 line 进行判断
//     在这里是用一个map记录线路与站名 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> v[10000];
unordered_map<int, int> line;
vector<int> path, temp_path;
bool visit[10000];
int start1, end1;
int mincnt = 99999999, mintransfer = 99999999;
int transferCnt(vector<int> path1) {
    int preLine = 0, transferNum = 0;
    for (int i = 1; i < path1.size(); i++) {
        if (line[path1[i - 1] * 10000 + path1[i]] != preLine){
            if (preLine != 0)
                transferNum++;
            preLine = line[path1[i - 1] * 10000 + path1[i]];
        }
    }
    return transferNum;
}
void dfs(int start, int cnt) {
    if (start == end1 && (cnt < mincnt || (cnt == mincnt && transferCnt(temp_path) < mintransfer))){
        mincnt = cnt;
        mintransfer = transferCnt(temp_path);
        path = temp_path;
    }
    if (start == end1)
        return;

    //这实际上有点像二叉树的先根遍历 可能到达最底端的子树 也可能到达一个节点前方访问过 然后只能返回 
    //这个能把两点间的所有路径都访问一遍 然后找出最短的路径 效率如何 与dijkstra的区别?`
    
    for (int i = 0; i < v[start].size(); i++) { 
        if (!visit[v[start][i]]) {
            visit[v[start][i]] = true;
            temp_path.push_back(v[start][i]);
            dfs(v[start][i], cnt + 1);
            visit[v[start][i]] = false;
            temp_path.pop_back();
        } 
    }
}
int main(){
    int n, k, m;
    cin >> n;
    int temp, pre;
    for (int i = 0; i < n; i++) {
        cin >> k >> pre;
        for (int j = 1; j < k; j++) {
            cin >> temp;
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre * 10000 + temp] = line[temp * 10000 + pre] = i + 1;
            pre = temp;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> start1 >> end1;
        temp_path.push_back(start1);
        visit[start1] = true;
        dfs(start1, 0);//到最后temp_path只有start1
        visit[start1] = false;
        cout << mincnt << endl;
        int preline = 0, prestation = start1;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j - 1] * 10000 + path[j]] != preline) {
                if (preline != 0) {
                    printf("Take Line#%d from %04d to %04d.\n", preline, prestation, path[j - 1]);
                    prestation = path[j - 1];
                }
                preline = line[path[j - 1] * 10000 + path[j]];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preline, prestation, end1);
        temp_path.clear();
        path.clear();
        mincnt = mintransfer = 99999999;
    }
    return 0;
}
//记得要及时清除上一次的标志 23分
//基本的思路是有了 但是细节部分处理的不到位 还有7分
//把%d 改成 %04d就满分了！！！