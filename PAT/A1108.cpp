// // 2019-9-28
// // 这一周编程都没有进展 写一道简单的找找感觉
// #include <iostream>
// using namespace std;
// int main() {
//     int n, cnt = 0;
//     double sum;
//     bool flag = true;
//     cin >> n;
//     string temp;
//     for (int i = 0; i < n; i++) {
//         cin >> temp;
//         int point = 0;
//         for (int j = 0; j < temp.size(); j++) {
//             if (isdigit(temp[j]))
//                 continue;
//             else if (temp[0] != '.' && temp[j] == '.' && point == 0)
//                 point = j;
//             else {
//                 flag = false;
//                 break;
//             }
//         }
//         if (stoi(temp.substr(0, point)) <= 999)
//         if (!flag)
//             printf("ERROR: %s is not a legal number", temp.c_str());
//     }
// }


// 2019-9-30
// 参考答案
// 2019-10-12
// 终于重拾信心 开始编程
// 先抄一道
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
        sprintf(b, "%.2lf", temp);
        int flag = 0;
        for (int j = 0; j < strlen(a); j++) {
            if (a[j] != b[j])
                flag = 1;
        }
        if (flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if (cnt == 1) {
        printf("The average of 1 number is %.2lf", sum);
    } else if (cnt > 1) {
        printf("The average of %d number is %.2lf", cnt, sum / cnt);
    } else {
        printf("The average of 0 number is Undefined");
    }
    return 0;
}
