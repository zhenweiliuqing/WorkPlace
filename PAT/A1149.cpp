#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    map<int, vector<int>> log;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        log[a].push_back(b);
        log[b].push_back(a);
    }
    int k;
    
    for (int i = 0; i < m; i++){
        bool res = true;
        cin >> k;
        vector<int> v(k);
        int flag[100000] = {0};
        for (int j = 0; j < k; j++){
            scanf("%d", &v[j]);
            flag[v[j]] = 1;
        }
        for (int j = 0; j < k; j++){
            for (int w = 0; w < log[v[j]].size(); w++){
                if (flag[log[v[j]][w]] == 1){
                    res = false;
                    break;
                }
            }
            if (!res)
                break;
        }
        printf(res ? "Yes\n" : "No\n");
    }
}
//思路是对的 第一次把bool res = true;放到循环外边 就只能输出No了