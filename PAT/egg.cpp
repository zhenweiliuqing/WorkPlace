//动态规划扔鸡蛋
//M层楼 N个鸡蛋
#include <iostream>
using namespace std;
int m, n, x;
int ans = 26;

void func(int m, int n, int x){
    if (x <= ans)//没有碎
        func(m - x)
}
int main(){
    cin >> m >> n;
    func(m, n, x);
}