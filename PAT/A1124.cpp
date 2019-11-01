// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <string>
// using namespace std;
// int main(){
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<string> v(n);
//     unordered_map<string, int> mm;
//     string temp;
//     for (int i = 0; i < n; i++){
//         cin >> temp;
//         v.push_back(temp);
//         mm[temp]++;
//     }
// }

// #include <iostream>
// #include <map>
// using namespace std;
// int main(){
//     int m, n, s;
//     scanf("%d%d%d", &m, &n, &s);
//     string str;
//     map<string, int> mapp;
//     bool flag = false;
//     for (int i = 1; i <= m; i++){
//         cin >> str;
//         if (mapp[str] == 1)
//             s = s + 1;
//         if (i == s && mapp[str] == 0){
//             mapp[str] = 1;
//             cout << str << endl;
//             flag = true;
//             s = s + n;
//         }
//     }
//     if (flag = false)
//         cout << "Keep going...";
//     return 0;
// }

//2019-6-1
#include <iostream>
#include <map>
using namespace std;
int main(){
    int n, k, st;
    scanf("%d%d%d", &n, &k, &st);
    string str;
    map<string, int> mmap;
    int i = 1;
    bool flag = false;
    // while (n--){
    //     cin >> str;
    //     if (i % k == st){
    //         mmap[str]++;
    //         if (mmap[str] == 1)
    //             printf("%s\n", str.c_str());
    //         else
    //             i--;
    //     }
    //     i++;
    // }

    while (n--){
        cin >> str;
        if (mmap[str] == 1)
            st++;
        if (i == st && mmap[str] == 0){
            cout << str <<endl;
            mmap[str] = 1;
            flag = true;
            st = st + k;
        }
        i++;
    }
    if (!flag)
        printf("Keep going...");
    return 0;
}
//12分 还差两个测试点！
//为什么这就对了 用取余的方法就是不行呢？
