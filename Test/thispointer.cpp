#include <iostream>
using namespace std;
class myClass {
public:
    int pubvar;
    void pubfun(int x);
    static int pubstatic;
    static void pubstaticfun(int x);

protected:
    int provar;
    void profun(int x);
    static int prostatic;
    static void prostaticfun(int x);

private:
    int privar;
    void prifun(int x);
    static int pristatic;
    static void pristaticfun(int x);
};
// myClass:: 只能调用public
int myClass::pubstatic = 0;
int myClass::pristatic = 0;

// this用于非静态成员函数中
void myClass::pubfun(int x){
    pubvar = x;//这一句加不加this没什么用
    this->provar = x + 1;// 如果不用this会有什么影响
    cout << "this is = " << endl;
}

void myClass::pubstaticfun(int x) {
    int e = mine.pubfun(x);
}

int main() {
    myClass my;
    // 实例化的对象只能调用public的函数和变量
    my.pubfun(5);
    cout << "my is = " << &my << endl;
    cout << "my pubvar = " << my.pubvar << endl;
    
    myClass mine;
    mine.pubfun(6);
    cout << "mine is = " << &mine << endl;
    cout << "mine pubvar = " << mine.pubvar << endl;

    myClass::pubstaticfun(5);
}
