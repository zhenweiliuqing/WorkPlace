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


// // 2019-9-30
// // 参考答案
// // 2019-10-12
// // 终于重拾信心 开始编程
// // 先抄一道
// #include <iostream>
// #include <cstdio>
// #include <string.h>
// using namespace std;
// int main() {
//     int n, cnt = 0;
//     char a[50], b[50];
//     double temp, sum = 0.0;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         scanf("%s", a);
//         sscanf(a, "%lf", &temp);
//         sprintf(b, "%.2lf", temp);
//         int flag = 0;
//         for (int j = 0; j < strlen(a); j++) {
//             if (a[j] != b[j])
//                 flag = 1;
//         }
//         if (flag || temp < -1000 || temp > 1000) {
//             printf("ERROR: %s is not a legal number\n", a);
//             continue;
//         } else {
//             sum += temp;
//             cnt++;
//         }
//     }
//     if (cnt == 1) {
//         printf("The average of 1 number is %.2lf", sum);
//     } else if (cnt > 1) {
//         printf("The average of %d number is %.2lf", cnt, sum / cnt);
//     } else {
//         printf("The average of 0 number is Undefined");
//     }
//     return 0;
// }

//2019-11-7
//思路: 核心就是判断输入的数据是不是[-1000, 1000]里的不超过两位小数的数
//      sscanf(a, "%lf", &temp); 将字符串a转换为lf类型的temp
//      sprintf(b, "%.2f", temp); 将temp转为两位小数赋给b

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <cstdlib>
using namespace std;
int main() {
    int n, cnt = 0;
    char input[50], convert[50]; // 如果用指针会如何？
    // char *point;
    // point = ".00";
    double temp, sum = 0.0;
    vector<double> res;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", &input);
        sscanf(input, "%lf", &temp);
        sprintf(convert, "%.2f", temp);
        // strcat(input, point);
        // string sinput = input, sconvert = convert;
        bool equal = true;
        for (int j = 0; input[j] != '\0'; j++) {
            if (input[j] != convert[j]) {
                equal = false;
                break;
            } 
        }

        if (equal && temp <= 1000 && temp >= -1000){
            cnt++;
            sum += temp;
        }
       else
            printf("ERROR: %s is not a legal number\n", input);
    }
    if (cnt == 0)
        printf("The average of 0 numbers is Undefined");
    else if (cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else 
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    return 0;
}
// 这可怎么办 转化了一下 小数位数变了 怎么判断小数位数相等
// 部分正确 13分！ 不想写了
// 满分了！！！ 输出有点问题 没有考虑周到！！