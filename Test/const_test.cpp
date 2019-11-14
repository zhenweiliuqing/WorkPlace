#include <iostream>
using namespace std;
int main() {
    int i = 1;
    const int *j = &i; // 指向的内容不可修改
    int *const k = &i; // 指针的地址不可修改
    int *p = new int;
    *p = 5;
    *k = 2; // 可以通过*k修改内容 但是k的地址不能动
    j = p; // 地址可以修改 但不能通过*j进行赋值
    delete p;

    int a = 10;
    const int &b = a; // b不能被赋值 不能通过b修改指向的那个变量的值 不能通过b来修改a
    a = 6;

    //没有const就会错
    int m = 2;
    const double &n = m; // 类型不同 但可以转化
    const int &x = 2;
    const int &y = x * 2;
    // cosnt引用会额外创建一个临时变量 并绑定上去 反正也不能通过引用赋值 干脆就支持这种做法把！
}