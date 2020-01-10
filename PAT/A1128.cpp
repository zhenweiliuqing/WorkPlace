// 2020-1-9
// N皇后的判别问题 主要是斜着 每一行应该都得判断所有列
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n ,k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        int t;
        vector<int> q;
        for (int j = 0; j < k; j++) {
            scanf("%d", &t);
            q.push_back(t);
        }
        bool flag = true;
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < k; l++) {
                if (j == l)
                    continue;
                if (q[j] + (l - j) == q[l] || q[j] - (l - j) == q[l]) {
                    flag = false;
                }
            }
            if (!flag) {
                printf("NO\n");
                break;
            }
        }
        if (flag)
            printf("YES\n");
    }
    return 0;
}
// 17分 有一个测试点错误！
