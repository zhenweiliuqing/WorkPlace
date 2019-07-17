// //2019-6-24 在6月9号基础上改进
// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;
// int edge[1000][1000];
// int main(){
//     int n, m;
//     map<int, int> mmap;
//     cin >> n >> m;
//     int v1, v2;
//     for (int i = 0; i < m; i++){
//         cin >> v1 >> v2;
//         edge[v1][v2] = 1;
//         mmap[v2]++;
//     }
//     int test_num, v;
//     cin >> test_num;
//     vector<int> res;
    
//     for (int i = 0; i < test_num; i++){
//         map<int, int> temp;
//         temp = mmap;
//         for (int j = 0; j < n; j++){
//             cin >> v;
//             if (temp[v] != 0){
//                 res.push_back(i);
//                 break;
//             }
//             for (int k = 1; k <= n; k++){
//                 if (edge[v][k] == 1)
//                     temp[k]--;
//             }
//         }
//     }
//     cout << res[0];
//     for (int i = 1; i < res.size(); i++){
//         cout << " " << res[i];
//     }
//     return 0;
// }
// 不知道哪里有错

// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     int n, m, flag = 0;
//     cin >> n >> m;
//     vector<int> v[1010];
//     int v1, v2;
//     vector<int> in(1010);
//     for (int i = 0; i < m; i++){
//         cin >> v1 >> v2;
//         v[v1].push_back(v2);
//         in[v2]++;
//     }
//     int test_num;
//     cin >> test_num;
//     for (int i = 0; i < test_num; i++){
//         int temp, judge = 1;
//         vector<int> in_temp = in;
//         for (int j = 0; j < n; j++){
//             cin >> temp;
//             if (in_temp[temp] != 0){
//                 judge = 0;
//             }
//             for (int it : v[temp])
//                 in_temp[it]--;
//         }
//         if (judge == 1)
//             continue;
//         printf("%s%d", flag == 1 ? " " : "", i);
//         flag = 1;
//     }
// }
//这能满分？？

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m, flag = 0;
    cin >> n >> m;
    vector<int> v[1010];
    int v1, v2;
    vector<int> in(1010);
    for (int i = 0; i < m; i++){
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        in[v2]++;
    }
    int test_num;
    cin >> test_num;
    vector<int> res;
    for (int i = 0; i < test_num; i++){
        int temp;
        vector<int> in_temp = in;
        for (int j = 0; j < n; j++){
            cin >> temp;
            if (in_temp[temp] != 0){
                flag = 1;
            }
            for (int it : v[temp])
                in_temp[it]--;
        }
        if (flag == 1)
            res.push_back(i);
        flag = 0;
    }
    cout << res[0];
    for (int i = 1; i < res.size(); i++){
        cout << " " << res[i];
    }
    return 0;
}
//满分 弄明白了 不能跳出循环 还有的数没有读取完毕 那么就会影响后边的数