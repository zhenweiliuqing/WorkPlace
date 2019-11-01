#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node{
    string id;
    int online, mid, fin, grade;
};
bool cmp (node a, node b){
    return a.grade != b.grade ? a.grade > b.grade : a.id < b.id;
}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<string, int> online;
    unordered_map<string, double> mid;
    unordered_map<string, double> fin;
    string id;
    int score;
    for (int i = 0; i < n; i++){
        cin >> id >> score;
        if (score >= 200){
            online[id] = score;
            mid[id] = fin[id] = -1;
        }
    }
    for (int i = 0; i < m; i++){
        cin >> id >> score;
        mid[id] = score;
    }
    for (int i = 0; i < k; i++){
        cin >> id >> score;
        fin[id] = score;
    }
    vector<node> res;
    for (auto it : online){
        res.push_back(node{it.first, online[it.first], (int)mid[it.first], (int)fin[it.first],\
            int(mid[it.first] > fin[it.first] ? (0.4 * mid[it.first] + 0.6 * fin[it.first] + 0.5): fin[it.first])});
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++){
        if (res[i].grade >= 60)
            printf("%s %d %d %d %d\n", res[i].id.c_str(), res[i].online, res[i].mid, res[i].fin, res[i].grade);
    }
    return 0;
}
//少有的一次满分！！！