//函数指针测试
#include <iostream>
using namespace std;
int add(int x, int y) {
    return x + y;
}
int sub(int x, int y) {
    return x - y;
}
int (*fun)(int x, int y);
typedef int (*FUN)(int x, int y);

int main() {
    fun = add;
    cout << fun(1, 2) << " " << (*fun)(1, 2);
    FUN fun1 = &sub;
    cout << fun1(5, 3) << " " << (*fun1)(5, 3);
    return 0;
}
