//2019-7-18
#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> v;
map<int, int> pos;
int main(){
    int m, n;
    cin >> m >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
        pos[v[i]] = i;
    }
    int a, b;
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        bool flag = false;
        if (pos[a] == 0 && pos[b] == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (pos[a] == 0 || pos[b] == 0)
            printf("ERROR: %d is not found.\n", (pos[a] == 0) ? a : b);
        else {
            int posa = pos[a], posb = pos[b];
            for (int j = 1; j < posa && j < posb; j++){
                if ((v[j] > a && v[j] < b) || (v[j] < a && v[j] > b)){    
                    printf("LCA of %d and %d is %d.\n", a, b, v[j]);
                    flag = true;
                    break;
                }
            }
            if (!flag){
                if (pos[a] < pos[b])
                    printf("%d is an ancestor of %d.\n", a, b);//谁在前面谁就是根
                else 
                    printf("%d is an ancestor of %d.\n", b, a);//谁在前面谁就是根
            }
        }
    }
    return 0;
}
//部分正确 5分
//还是得j <= n 不能 j < pos[a] && j < pos[b] 会超时 都是26分 这个取位置好占用时间啊 一个超过200 一个 15ms
//终于满分了  还是答案考虑的详细周到还简便