// 2019-12-26
// 思路：1000位数字感觉得用string
// 主要是怎么进位

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string in;
    cin >> in;
    string s = in;
    reverse(s.begin(), s.end());
    if (in == s) {
        cout << in << " is a palindromic number.";
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        
        string s = in;
        reverse(s.begin(), s.end());
        cout << in << " + " << s;

        // string s(in.rbegin(), in.rend());
        // cout << s;

        // for (int j = in.length() - 1; j >= 0; j--)
        //     cout << in[j];
            
        int flag = 0;
        string temp;   
        int l = in.length() - 1;
        for (int j = 0; j <= l; j++) {
            int m = flag + in[j] + in[l - j] - 96;
            if (m >= 10)
                flag = 1;
            else
                flag = 0;
            temp = to_string((m % 10)) + temp;
        }
        if (flag == 1)
            temp = '1' + temp;
        in = temp;

        cout << " = " << in << endl;
        int l2 = in.length() - 1;
        for (int j = 0; j <= l2; j++) {
            if (in[j] != in[l2 - j])
                break;
            if (j == l2) {
                cout << in << " is a palindromic number.";
                return 0;
            }
        }
    }
    cout << "Not found in 10 iterations.";
    return 0;
}
// 16分 有3个测试点错误！
// 如果直接就是回文数 那就不用后边的了！20分！

// // 参考答案
// #include <iostream>
// #include <algorithm>
// using namespace std;
// string rev(string s) {
//     reverse(s.begin(), s.end());
//     return s;
// }
// string add(string s1, string s2) {
//     string s = s1;
//     int carry = 0;
//     for (int i = s1.size() - 1; i >= 0; i--) {
//         s[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
//         carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
//     }
//     if (carry > 0)
//         s = "1" + s;
//     return s;
// }
// int main() {
//     string s, sum;
//     int n = 10;
//     cin >> s;
//     if (s == rev(s)) {
//         cout << s << " is a palindromic number.\n";
//         return 0;
//     }
//     while (n--) {
//         sum = add(s, rev(s));
//         cout << s << " + " << rev(s) << " = " << sum << endl;
//         if (sum == rev(sum)) {
//             cout << sum << " is a palindromic number.\n";
//             return 0;
//         }
//         s = sum;
//     }
//     cout << "Not found in 10 iterations.\n";
//     return 0;
// }