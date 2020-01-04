// 2020-1-4 这个题不是很简单嘛
// 思路：就是尽量让最短的绳子多折
// 为什么当时不会还抄答案了呢？
// 有时候题目就是一个纸老虎 没那么难 有时候是你知识水平不到位 觉得他很难
// 所以还是努力提升自己的基础能力吧
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    double ans = v[0];
    for (int i = 1; i < n; i++)
        ans = (v[i] + ans) / 2;
    printf("%d", (int)ans);
    return 0;
}
// 满分！

// // 参考答案
// // 2019-10-29
// // 今天出差 回来再看看
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// int main() {
//     int n;
//     scanf("%d", &n);
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &v[i]);
//     sort(v.begin(), v.end());
//     int result = v[0];
//     for (int i = 1; i < n; i++)
//         result = (result + v[i]) / 2;
//     printf("%d", result);
//     return 0;
// }   