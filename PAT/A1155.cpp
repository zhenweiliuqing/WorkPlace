//2019-7-4
//参考答案
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v;
queue<int> q;
int a[1009], n, isMin = 1, isMax = 1;
void dfs(int index){
    if (index * 2 > n && index * 2 + 1 > n){/// 这两个条件是怎么想出来的
        if (index <= n) { /// 去除掉不是的右子树
            for (int i = 0; i < v.size(); i++)
                printf("%d%s", v[i], i != v.size() - 1 ? " " : "\n");
        }
    } else {
        v.push_back(a[index * 2 + 1]);
        dfs(index * 2 + 1);
        v.pop_back();
        v.push_back(a[index * 2]);
        dfs(index * 2);
        v.pop_back();
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    v.push_back(a[1]);
    dfs(1);
    for (int i = 2; i <= n; i++) {
        if (a[i/2] > a[i])
            isMin = 0;
        if (a[i/2] < a[i])
            isMax = 0;
    }
    if (isMin == 1)
        printf("Min Heap");
    else
        printf("%s", isMax == 1 ? "Max Heap" : "Not Heap");
    return 0;
}
