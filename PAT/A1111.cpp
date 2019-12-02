//2019-11-27
//思路：应用两次dijkstra算法
// 然后找到路径的话从后往前找
#include <iostream>
#include <vector>
using namespace std;
#define inf 99999999
int disgraph[510][510], timegraph[510][510];
int dispre[510], timepre[510];
bool disvisit[510], timevisit[510];
vector<int> dispath, timepath;
int start, final;
void DisPath(int x) {
    dispath.push_back(x);
    if (x == start)
        return;
    DisPath(dispre[x]);
}
void TimePath(int x) {
    timepath.push_back(x);
    if (x == start)
        return;
    TimePath(timepre[x]);
}
int main() {
    int n, m;
    cin >> n >> m;
    fill(disgraph[0], disgraph[0] + 510 * 510, 0);
    fill(timegraph[0], timegraph[0] + 510 * 510, 0);
    int a, b, single, d, t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> single >> d >> t;
        disgraph[a][b] = d;
        timegraph[a][b] = t;
        if (single == 0){
            disgraph[b][a] = d;
            timegraph[b][a] = t;
        }
    }
    // dijkstra distance
    cin >> start >> final;
    int dis[510];
    fill(dis, dis + 510, inf);
    dis[start] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = inf;
        //找到最近的
        for (int k = 0; k < n; k++) {
            if (disvisit[k] == false && dis[k] < min) {
                min = dis[k];
                u = k;
            }
        }
        if (u == -1)
            break;
        disvisit[u] = true;
        for (int v = 0; v < n; v++) {
            if (disvisit[v] == false && disgraph[u][v] != 0) {
                if (dis[u] + disgraph[u][v] < dis[v]){
                    dis[v] = disgraph[u][v] + dis[u]; // 更新权重
                    dispre[v] = u; // v的前继是u
                }
            }
        }
    }
    DisPath(final);
    // dijkstra time
    int time[510];
    fill(time, time + 510, inf);
    time[start] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = inf;
        //找到最近的
        for (int k = 0; k < n; k++) {
            if (timevisit[k] == false && time[k] < min) {
                min = time[k];
                u = k;
            }
        }
        if (u == -1)
            break;
        timevisit[u] = true;
        for (int v = 0; v < n; v++) {
            if (timevisit[v] == false && timegraph[u][v] != 0) {
                if (time[u] + timegraph[u][v] < time[v]){
                    time[v] = timegraph[u][v] + time[u]; // 更新权重
                    timepre[v] = u; // v的前继是u
                }
            }
        }
    }
    TimePath(final);
    if (dispath != timepath) {
        printf("Distance = %d: %d", dis[final], dispath[dispath.size() - 1]);
        for (int i = dispath.size() - 2; i >= 0; i--)
            printf(" -> %d", dispath[i]);
        cout << endl;
        printf("Time = %d: %d", time[final], timepath[timepath.size() - 1]);
        for (int i = timepath.size() - 2; i >= 0; i--)
            printf(" -> %d", timepath[i]);
    } else {
        printf("Distance = %d; Time = %d: %d", dis[final], time[final], dispath[dispath.size() - 1]);
        for (int i = dispath.size() - 2; i >= 0; i--)
            printf(" -> %d", dispath[i]);
    }
    return 0;
}

// // 2019-9-23
// // 思路不清晰 看一下参考答案
// // 参考答案
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// const int inf = 99999999;
// int dis[510], Time[510], e[510][510], w[510][510], dispre[510], Timepre[510], weight[510], NodeNum[510];
// bool visit[510];
// vector<int> dispath, Timepath, temppath;
// int st, fin, minnode = inf;
// // 从后往前找路径
// void dfsdispath(int v) {
//     dispath.push_back(v);
//     if (v == st)
//         return;
//     dfsdispath(dispre[v]);
// }
// void dfsTimepath(int v) {
//     Timepath.push_back(v);
//     if (v == st)
//         return;
//     dfsTimepath(Timepre[v]);
// }
// int main() {
//     fill(dis, dis + 510, inf);
//     fill(Time, Time + 510, inf);
//     fill(weight, weight + 510, inf);
//     fill(e[0], e[0] + 510 * 510, inf);
//     fill(w[0], w[0] + 510 * 510, inf);
//     int n, m;
//     scanf("%d %d", &n, &m);
//     int a, b, flag, len, t;
//     for (int i = 0; i < m; i++) {
//         scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
//         e[a][b] = len;
//         w[a][b] = t;
//         if (flag != 1) {
//             e[b][a] = len;
//             w[b][a] = t;
//         }
//     }
//     scanf("%d %d", &st, &fin);
//     dis[st] = 0;
//     for (int i = 0; i < n; i++)
//         dispre[i] = i;
//     for (int i = 0; i < n; i++) {
//         int u = -1, minn = inf;
//         for (int j = 0; j < n; j++) {
//             if (visit[j] == false && dis[j] < minn) {
//                 u = j;
//                 minn = dis[j];
//             }
//         }
//         if (u == -1)
//             break;
//         visit[u] = true;
//         for (int v = 0; v < n; v++) {
//             if (visit[v] == false && e[u][v] != inf) {
//                 if (e[u][v] + dis[u] < dis[v]) {
//                     dis[v] = e[u][v] + dis[u];
//                     dispre[v] = u;// v的前一个是u
//                     weight[v] = weight[u] + w[u][v];
//                 } else if (e[u][v] + dis[u] == dis[v] && weight[v] > weight[u] + w[u][v]) {
//                     weight[v] = weight[u] + w[u][v];
//                     dispre[v] = u;
//                 }
//             }
//         }
//     }
//     dfsdispath(fin);
//     Time[st] = 0;
//     fill(visit, visit + 510, false);
//     for (int i = 0; i < n; i++) {
//         int u = -1, minn = inf;
//         for (int j = 0; j < n; j++) {
//             if (visit[j] == false && minn > Time[j]) {
//                 u = j;
//                 minn = Time[j];
//             }
//         }
//         if (u == -1)
//             break;
//         visit[u] = true;
//         for (int v = 0; v < n; v++) {
//             if (visit[v] == false && w[u][v] != inf) {
//                 if (w[u][v] + Time[u] < Time[v]) {
//                     Time[v] = w[u][v] + Time[u];
//                     Timepre[v] = (u);
//                     NodeNum[v] = NodeNum[u] + 1;
//                 } else if (w[u][v] + Time[u] == Time[v] && NodeNum[u] + 1 < NodeNum[v]) {
//                     Timepre[v] = (u);
//                     NodeNum[v] = NodeNum[u] + 1;
//                 }
//             }
//         }
//     }
//     dfsTimepath(fin);
//     printf("Distance = %d", dis[fin]);
//     if (dispath == Timepath) {
//         printf("; Time = %d: ", Time[fin]);
//     } else {
//         printf(": ");
//         for (int i = dispath.size() - 1; i >= 0; i--) {
//             printf("%d", dispath[i]);
//             if (i != 0)
//                 printf(" -> ");
//         }
//         printf("\nTime = %d: ", Time[fin]);
//     }
//     for (int i = Timepath.size() - 1; i >= 0; i--) {
//         printf("%d", Timepath[i]);
//         if (i != 0)
//             printf(" -> ");
//     }
//     return 0;
// }
