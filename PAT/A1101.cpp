// // 2019-9-21
// // 刚分完手，没心思思考，抄一下代码看一下思路吧
// // 参考答案
// #include <iostream>
// #include <algorithm>
// #include <vector>
// int v[100000];
// using namespace std;
// int main() {
//     int n, max = 0, cnt = 0;
//     scanf("%d", &n);
//     vector<int> a(n), b(n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//         b[i] = a[i];
//     }
//     sort(a.begin(), a.end());
//     for (int i = 0; i < n; i++) {
//         if (a[i] == b[i] && b[i] > max) //这种思路可真是个小机灵鬼 666
//             v[cnt++] = b[i];
//         if (b[i] > max)// 避免那种位置对 但是顺序不对的情况 但是这样就可以吗 
//             max = b[i];// 可以 保证它前面没有比它更大的了
//     }
//     printf("%d\n", cnt);
//     for (int i = 0; i < cnt; i++) {
//         if (i != 0)
//             printf(" ");
//         printf("%d", v[i]);
//     }
//     printf("\n");
//     return 0;     
// }
