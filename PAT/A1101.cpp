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

// 2019-11-6
// 思路：其实这个跟快速排序没有什么关系 就是判断一下自己下标所处的
//       位置跟自己实际值一定要相同 同时还得是保证前面不能有比他大的
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v[100000];
int main() {
    int n, temp, max = 1;
    int cnt = 0;
    cin >> n;
    vector<int> data(n), index(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &temp);
        data[i] = index[i] = temp;
    }
    sort(index.begin(), index.end());
    for (int i = 0; i < n; i++) {
        if (data[i] == index[i] && max <  index[i])
            v[cnt++] = data[i];
        if (data[i] > max)
            max = data[i];
        
    }
    cout << cnt << endl;
    cout << v[0];
    for (int i = 1; i < cnt; i++)
        cout << " " << v[i];
    return 0;
}
// 使用vector<int> res段错误 改用v答案错误
// 因为输入的不一定是按1 2 3 4 5的顺序的
// 部分正确21分
// 可能有并列的？