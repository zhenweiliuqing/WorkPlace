//2019-6-14
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int edge[200][200];
int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        edge[a][b] = edge[b][a] = 1;
    }
    int t;
    cin >> t;
    int k;
    
    for (int i = 0; i < t; i++){
        cin >> k;
        set<int> cnt;
        bool flag = true;
        vector<int> temp(k);
        for (int j = 0; j < k; j++){
            cin >> temp[j];
            cnt.insert(temp[j]);
        }
        for (int j = 1; j < k; j++)
            if (edge[temp[j - 1]][temp[j]] == 0){
                flag = false;
                break;
            }
                
        if (flag && cnt.size() == n && k == n + 1 && temp[0] == temp[k - 1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
//调试没问题 但是有两个测试点不对 19分！
//判断连通性那点错了一个 set要放在循环里。