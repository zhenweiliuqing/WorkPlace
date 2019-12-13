// 2019-10-24
// 得会求质数 
// #include <iostream>
// #include <set>
// #include <cmath>
// using namespace std;
// int ran[10000];
// bool isprime(int a) {
//     if (a <= 1)
//         return false;
//     int Sqrt = sqrt((double)a);
//     for (int i = 2; i <= Sqrt; i++) {
//         if (a % i == 0)
//             return false;
//     }
//     return true;
// }
// int main() {
//     int n, k;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         int id;
//         scanf("%d", &id);
//         ran[id] = i + 1;
//     }
//     scanf("%d", &k);
//     set<int> ss;
//     for (int i = 0; i < k; i++) {
//         int id;
//         scanf("%d", &id);
//         printf("%04d: ", id);
//         if (ran[id] == 0) {
//             printf("Are you kidding?\n");
//             continue;
//         }
//         if (ss.find(id) == ss.end()) {
//             ss.insert(id);
//         } else {
//             printf("Checked\n");
//             continue;
//         }
//         if (ran[id] == 1) {
//             printf("Mystery Award\n");
//         } else if (isprime(ran[id])) {
//             printf("Minion\n");
//         } else {
//             printf("Chocolate\n");
//         }
//     }
//     return 0;
// }

// 2019-12-7
// 思路：先求判断质数
// 用一个map<id, rank> 判断一次之后设为-1 若为-1则为checked
// 如果没有就是0 输出are you kidding?
#include <iostream>
#include <cmath>
#include <map>
using namespace std;
map<int, int> mmap;
bool isprime(int n) {
    if (n == 1 || n == 0) 
        return false;
    if (n == 2 || n == 3)
        return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main() {
    int n, temp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        mmap[temp] = i;
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> temp;
        if (mmap[temp] == 1) {
            printf("%04d: Mystery Award\n", temp);
            mmap[temp] = -1;       
        } else if (mmap[temp] == 0) {
            printf("%04d: Are you kidding?\n", temp);
        } else if (mmap[temp] == -1) {
            printf("%04d: Checked\n", temp); 
        } else if (isprime(mmap[temp]) && mmap[temp] != -1) {
            printf("%04d: Minion\n", temp);
            mmap[temp] = -1;
        } else {
            printf("%04d: Chocolate\n", temp);
        }
    }
    return 0;
}
// 17分 有一个错误点
