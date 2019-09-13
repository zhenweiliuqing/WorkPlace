// //2019-6-8
// //今明两天要把没做的东西都给补上来
// #include <iostream>
// #include <vector>
// using namespace std;
// int e[210][210];
// int main(){
//     int nv, ne, m, ta, tb, k;
//     scanf("%d %d", &nv, &ne);
//     for (int i = 0; i < ne; i++){
//         scanf("%d %d", &ta, &tb);
//         e[ta][tb] = e[tb][ta] = 1;
//     }
//     scanf("%d", &m);
//     for (int i = 0; i < m; i++){
//         scanf("%d", &k);
//         vector<int> v(k);
//         int hash[210] = {0}, isclique = 1, ismaximal = 1;
//         for (int j = 0; j < k; j++){
//             scanf("%d",&v[j]);
//             hash[v[j]] = 1;
//         }
//         for (int j = 0; j < k; j++){
//             if (isclique == 0)
//                 break;
//             for (int l = j + 1; l < k; l++){
//                 if (e[v[j]][v[l]] == 0){
//                     isclique = 0;
//                     printf("Not a Clique\n");
//                     break;
//                 }
//             }
//         }
//         if (isclique == 0)
//             continue;
//         for (int j = 1; j <= nv; j++){
//             if (hash[j] == 0){
//                 for (int l = 0; l < k; l++){
//                     if (e[v[l]][j] == 0)
//                         break;
//                     if (l == k - 1)
//                         ismaximal = 0;
//                 }
//             }
//             if (ismaximal == 0){
//                 printf("Not Maximal\n");
//                 break;
//             }
//         }
//         if (ismaximal == 1)
//             printf("Yes\n");
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;
int edge[210][210];
int main(){
    int nv, ne;
    cin >> nv >> ne;
    int v1, v2;
    for (int i = 0; i < ne; i++){
        cin >> v1 >> v2;
        edge[v1][v2] = edge[v2][v1] = 1;
    }
    int m, n;
    bool isClique = true, isMaximal = true;
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++){
            cin >> v[j];
        }
        for (int j = 0; j < n; j++){
            for (int k = j + 1; k < n; k++){
                if (edge[v[j]][v[k]] == 0){//如果不是两两连接
                    isClique = false;
                }
            }
        }
        for (int j = 1; j <= nv; j++){
            for (int k = 0; k < n; k++){
                if (edge[j][v[k]] == 0)
                    break;
                if (k == n - 1)
                    isMaximal = false;
            }
        }
        if (!isClique)
            cout << "Not a Clique" << endl;
        else if (!isMaximal)
            cout << "Not Maximal" << endl;
        else
            cout << "Yes" << endl;
        isClique = isMaximal = true;
    }
    return 0;
}
//我靠 牛逼啊 竟然全对！
//其实这个题思路也很清晰 编程也不难 重置标志位很关键！！！