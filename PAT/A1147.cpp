// //2019-7-1
// //思路：先进行输入，输入完毕之后判断是否每个子节点大于或小于

// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> v;
// void dfs(int root){
//     if (v[root * 2 + 1] > v[root] && v[root *2 + 2] > v[root])
// }
// int main(){
//     int n, m;
//     cin >> n >> m;
//     v.resize(m);
//     while(n--){
//         for (int i = 0; i < m; i++)
//             cin >> v[i];
//         dfs(0);
//     }
// }

//参考答案
#include <iostream>
#include <vector>
using namespace std;
int m, n;
vector<int> v;
void postOrder(int index){
    if (index >= n)
        return;
    postOrder(index * 2 + 1);
    postOrder(index * 2 + 2);
    printf("%d%s", v[index], index == 0 ? "\n" : " ");
}
int main(){
    scanf("%d%d", &m, &n);
    v.resize(n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            scanf("%d", &v[j]);
        int flag = v[0] > v[1] ? 1 : -1;
        for (int j = 0; j <= (n - 1) / 2; j++){
            int left = j * 2 + 1, right = j * 2 + 2;
            if (flag == 1 && (v[j] < v[left] || (right < n && v[j] < v[right])))
                flag = 0;
            if (flag == -1 && (v[j] > v[left] || (right < n && v[j] > v[right])))
                flag = 0;
        }
        if (flag == 0)
            printf("Not Heap\n");
        else
            printf("%s Heap\n", flag == 1 ? "Max" : " Min");
        postOrder(0);
    }
    return 0;
}
