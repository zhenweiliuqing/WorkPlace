// //2017-5-26
// #include <iostream>
// #include <map>
// #include <set>
// using namespace std;
// int main(){
//     int n;
//     string str;
//     cin >> n;
//     cin >> str;
//     map<char, bool> mmap;
//     mmap[str[0]] = false;
//     set<char> res;
//     for (int i = 0; i <= str.size() - n; i++){
//         char temp = str[i];
//         for (int j = 1; j < n; j++){
//             if (mmap[str[i]])
//                 break;
//             if (str[i + j] != temp){
//                 mmap[temp] = false;
//                 break;
//             } else if (j == n - 1){
//                 mmap[temp] = true;
//                 res.insert(temp);
//             }
//         }
//     }
//     for (auto it = res.begin(); it != res.end(); it++)
//     {
//         cout << *it;
//     }
//     cout << endl;
//     for (int i = 0; i < str.size(); i++){
//         if (mmap[str[i]] == false)
//             cout << str[i];
//         else {
//             cout << str[i];
//             i = i + n;
//         }
//     }
// }

//2019-5-27
//参考答案
// #include <iostream>
// #include <map>
// #include <cstdio>
// #include <set>
// using namespace std;
// bool sureNoBroken[256];
// int main(){
//     int k, cnt = 1;
//     scanf("%d", &k);
//     string s;
//     cin >> s;
//     map<char, bool> m;
//     set<char> printed;
//     char pre = '#';
//     s = s + '#';
//     for (int i = 0; i < s.length(); i++){
//         if (s[i] == pre){
//             cnt++;
//         } else {
//             if (cnt % k != 0)
//                 sureNoBroken[pre] = true;//确定没有坏
//             cnt = 1;
//         }
//         if (i != s.length() - 1)
//             m[s[i]] = (cnt % k == 0);//这可能是坏了
//         pre = s[i];
//     }
//     for (int i = 0; i < s.length() - 1; i++){
//         if (sureNoBroken[s[i]] == true)//如果没有人帮他一把 他就是真的坏了
//             m[s[i]] = false;
//     }
//     for (int i = 0; i < s.length() - 1; i++){
//         if (m[s[i]] && printed.find(s[i]) == printed.end()){
//             printf("%c", s[i]);
//             printed.insert(s[i]);
//         }
//     }
//     printf("\n");
//     for (int i = 0; i < s.length() - 1; i++){
//         printf("%c", s[i]);
//         if (m[s[i]])
//             i = i + k - 1;
//     }
//     return 0;
// }



#include <iostream>
#include <map>
#include <set>
using namespace std;
set<int> sset;
int main(){
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]){
            i += 2;
            sset.insert(s[i]);
        }
    }
    set<int> fset;
    for (auto it = sset.begin(); it != sset.end(); it++) {
        for (int i = 0; i < s.size() - 2; i++) {
           if (*it == s[i]) {
               if (*it == s[i + 1] && *it == s[i + 2])
                   fset.insert(s[i]);
           }
        }    
    }
    for (auto it = fset.begin(); it != fset.end(); it++)
        cout << *it;
    return 0;
}
