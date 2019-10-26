// 2019-10-26
// 思路：得到E天超过E miles的E的最大值
// 先排序 下标相当于统计的天数 数组里的数就是miles
// 找到第一个下标大于数值 然后取较小值 有问题吗？
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++){
        if (i + 1 > v[i]) {
            printf("%d", min(i + 1, v[i]));
            break;
        }
    }
    return 0;
}
// 部分正确 14分 可能还有一些边界问题不对！！