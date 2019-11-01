// 2019-10-12
// 终于重拾信心 开始编程
// 先抄一道
// 参考答案
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    int n, cnt = 0;
    char a[50], b[50];
    double temp, sum = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f", temp);
        int flag = 0;
        for (int j = 0; j < strlen(a); j++)
            if (a[j] != b[j])
                flag = 1;
        
    }
}