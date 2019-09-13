// //2019-7-2
// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
// 感觉不知道怎么建成一棵树啊    
// }

// 参考答案
#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, bool> mp;
int main(){
    int m, n, u, v, a;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    for (int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        for (int j = 0; j < n; j++){
            a = pre[j];
            if ((a >= u && a <= v) || (a >= v && a <= u))//找到一个夹在中间的
                break;
        }/// 这对吗 找到一个夹在中间的就行了？ 这么简单？？？能确保是最小祖先吗？
        if (mp[u] == false && mp[v] == false)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (mp[u] == false || mp[v] == false)
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}