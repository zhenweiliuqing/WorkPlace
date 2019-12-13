// 2019-10-22
// 题意：分成两拨 要求个数差别最少 和的差别最大
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// int main() {
//     int n, sum = 0, halfsum = 0;
//     scanf("%d", &n);
//     vector<int> v(n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &v[i]);
//         sum += v[i];
//     }
//     sort(v.begin(), v.end());
//     for (int i = 0; i < n / 2; i++)
//         halfsum += v[i];
//     printf("%d %d", n % 2, sum - 2 * halfsum);
//     return 0;
// }
// // 就这么简单 = =

// 2019-12-4
// 思路：如果是偶数输出0 如果是奇数输出1
// 然后排序 前一半相加 后一半相加 然后后一半减去前一半即可
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int suml = 0, sumr = 0;
    int i, j;
    for (i = 0; i < n / 2; i++)
        suml += v[i];
    for (j = i; j < n; j++)
        sumr += v[j];
    printf("%d %d", n % 2, sumr - suml);
    return 0;
}
// 11分 哪里错了？
// 满分！！！ (i - 1)/2 不满足偶数