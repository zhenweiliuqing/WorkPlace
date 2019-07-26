//2019-7-24
//测试一下struct内部使用结构名
#include <iostream>
using namespace std;
typedef struct node {
    int a, b;
    node(){
        a = 1;
        b = 1;
    }
} Node;
struct node x;
int main() {
    
    cout << x.a << " " << x.b << endl;
}
//总结：
//1. Node必须加typedef才能用。
//2. node(){} 起到初始化的功能 不能 struct node(){}.
//3. 使用初始化时node, Node, struct node均可。
//4. 在外边初始化时为0 在里边为随机数， 除非在里边初始化。