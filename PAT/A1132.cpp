// 2010-1-4 
// 思路：将数字分为两半 判断数字除以部分的积是不是整数
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        // 这个是局部变量好 还是全局好
        string a, b;
        a = s.substr(0, (int)s.size() / 2);
        b = s.substr(s.size() / 2, (int)s.size() / 2);
        if ((stoi(a) * stoi(b)) == 0) // 避免123000这种情况
            printf("No\n");
        else if (stoi(s) % (stoi(a) * stoi(b)) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
// 满分！！