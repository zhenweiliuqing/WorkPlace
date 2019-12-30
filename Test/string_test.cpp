// 2019-9-28
#include <iostream>
#include <string>
using namespace std;
int main() {
    // stoi 不转化小数点后的数字
    // string temp = "2234.234";
    // int x = stoi(temp);
    // cout << x << endl;
    // int sub1 = stoi(temp.substr(0, 4));
    // int sub2 = stoi(temp.substr(5, 3));
    // cout << sub1 << " " << sub2 << endl;

    // 测试一下to_string 只能把数字转化成string
    int x = 13213;
    const char *c = "123123";
    double f = 1.2344;
    string s;
    s = to_string(x);
    s.insert(3, "d878"); // 不能是char''
    s = c;
    // s = to_wstring(c);
    s = to_string(f);

     wstring ss = to_wstring(x); // 只是在前面加个L 宽字符串 可以输出汉字的那种
}