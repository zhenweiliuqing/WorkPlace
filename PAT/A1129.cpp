
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
// }
// //需要计数 需要排序 取排名前三

//参考答案
#include <iostream>
#include <set>
using namespace std;
int book[50001];
struct node{
    int value, cnt;
    bool operator < (const node &a) const{
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
int main()
{
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> s;
    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        if (i != 0){
            printf("%d:", num);
            int tempCnt = 0;
            for (auto it = s.begin(); tempCnt < k && it != s.end(); it++){
                printf(" %d", it->value);
                tempCnt++;
            }
            printf("\n");
        }
        auto it = s.find(node{num, book[num]});
        if (it != s.end())
            s.erase(it);
        book[num]++;
        s.insert(node{num, book[num]});
    }
    return 0;
}