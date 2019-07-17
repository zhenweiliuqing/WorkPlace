//2019-5-9
#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct node{
    int c1, c2;
};
int guest[100010];
int main()
{
    int n, m;
    cin >> n;
    vector<node> v(n);
    for (int i = 0; i < n ; i++){
        scanf("%d %d", &v[i].c1, &v[i].c2);
        guest[v[i].c1] = guest[v[i].c2] = 1;
    }
    cin >> m;
    int temp;
    set<int> s;
    for (int i = 0; i < m; i++){
        scanf("%d", &temp);
        if (guest[temp] == 0)
            s.insert(temp);
        else if (guest[temp] == 1)
            guest[temp] = 2;
    }

    for (int i = 0; i < n; i++){
        if (guest[v[i].c1] == 1 && guest[v[i].c2] == 2)
            s.insert(v[i].c2);
        else if (guest[v[i].c1] == 2 && guest[v[i].c2] == 1)
            s.insert(v[i].c1);
    }
    if (s.size() == 0)
        printf("%d", 0);
    else {
        printf("%d\n%05d", s.size(), *s.begin());
        for (auto it = s.begin(); it != s.end(); it++){
            if (it != s.begin())
                printf(" %05d", *it);
        }
    }
    return 0;
}
//19分 错了两个测试点 是答案错误 不是超时 而且格式没有错误
//走了一遍流程 怎么会有错误呢
//23分了 还有一个小的测试点不通 
//如果没有结果的话 输出0 即可 这就得到了满分