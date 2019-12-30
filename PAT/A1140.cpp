// // 2019-12-20
// // 思路：下一个数字就是数上一个数字的个数 挨个数
// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     string s;
//     int n;
//     cin >> s >> n;
//     s += '#';
//     for (int i = 1; i < n; i++) {
//         string next = "";
//         int cnt = 1;
//         for (int j = 0; j < s.length() - 1; j++) {
//             // string temp = to_string(digit);
//             if (s[j] == s[j + 1]) 
//                 cnt++;
//             else {
//                 next += s[j]; // next加n个s[j];
//                 next += to_string(cnt);
//                 cnt = 1;
//             }
//         }
//         if (i != n - 1)
//             s = next + '#';
//         else
//             s = next;
//     }
//     cout << s;
//     return 0;
// }
// // 19分 差一个测试点！！

// 参考答案
#include <iostream>
using namespace std;
int main() {
    string s;
    int n, j;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; cnt++) {
        string t;
        for (int i = 0; i < s.length(); i = j) {
            for (j = i; j < s.length() && s[j] == s[i]; j++);
            t += s[i] + to_string(j - i);
        }
        s = t;
    }
    cout << s;
    return 0;
}
// 豁然开朗 妙啊！！