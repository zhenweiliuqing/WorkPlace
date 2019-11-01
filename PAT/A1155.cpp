// //2019-7-4
// //参考答案
// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> v;
// int a[1009], n, isMin = 1, isMax = 1;
// void dfs(int index){
//     if (index * 2 > n && index * 2 + 1 > n){/// 这两个条件是怎么想出来的
//         if (index <= n) { /// 去除掉不是的右子树
//             for (int i = 0; i < v.size(); i++)
//                 printf("%d%s", v[i], i != v.size() - 1 ? " " : "\n");
//         }
//     } else {
//         v.push_back(a[index * 2 + 1]);
//         dfs(index * 2 + 1);
//         v.pop_back();
//         v.push_back(a[index * 2]);
//         dfs(index * 2);
//         v.pop_back();
//     }
// }
// int main(){
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         scanf("%d", &a[i]);
//     v.push_back(a[1]);
//     dfs(1);
//     for (int i = 2; i <= n; i++) {
//         if (a[i/2] > a[i])
//             isMin = 0;
//         if (a[i/2] < a[i])
//             isMax = 0;
//     }
//     if (isMin == 1)
//         printf("Min Heap");
//     else
//         printf("%s", isMax == 1 ? "Max Heap" : "Not Heap");
//     return 0;
// }


//2019-7-7
//思路：先进行输入 
// 然后进行节点的提取  从根节点开始先往右 再往左边 进了右边还能往左边嘛？ 
// 递归的思路怎么整理
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v;
int n;
vector<int> temp;
void dfs(int index){
    if (index <= n)
        temp.push_back(v[index]);
    else
        return;
    if (index * 2  + 1 <= n || index * 2 <= n)//如果这个节点有右孩子
    {    
        dfs(index * 2 + 1);
        dfs(index * 2);
    }
    else {
        cout << temp[0];
        for (int i = 1; i < temp.size(); i++)
            cout << " " << temp[i];
        cout << endl;
    }
    temp.pop_back();
}
int main(){
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    dfs(1);
    bool isMin = true, isMax = true;
    for (int i = 1; i <= n / 2; i++){
        if (i * 2 + 1 <= n && v[i * 2 + 1] >= v[i])
            isMax = false;
        if (i * 2 <= n && v[i * 2] >= v[i])
            isMax = false;
        if (i * 2 + 1 <= n && v[i * 2 + 1] <= v[i])
            isMin = false;
        if (i * 2 <= n && v[i * 2] <= v[i])
            isMin = false;
    }
    if (isMin && !isMax)
        cout << "Min Heap";
    else if (isMax && !isMin)
        cout << "Max Heap";
    else    
        cout << "Not Heap";
    return 0;
}
//修改了一下 少一个参数