// 2019-12-13
// Ideas: 确定输入位数和检查的位数
// 依次判断是不是质数

#include <iostream>
#include <string>
using namespace std;
bool isPrime(int x) {
    if (x <= 1)
        return false;
    if (x == 2 || x == 3)
        return true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    string s, temp;
    cin >> s;
    for (int i = 0; i <= n - m; i++) {
        temp = s.substr(i, m);
        if (isPrime(stoi(temp))) {
            cout << temp;
            return 0;
        }
    }
    cout << "404";
    return 0;
}
// 满分！！