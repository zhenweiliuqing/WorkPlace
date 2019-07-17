//这个题是说什么的啊 
//我铁定是不会做
#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct node {
    int t1, t2;
};

int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<node> v(m);
    for (int i = 0; i < m; i++)
        scanf("%d %d", &v[i].t1, &v[i].t2);
    cin >> k;
    while (k--){
        int a[10009] = {0};//颜色
        bool flag = true;
        set<int> se;
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            se.insert(a[i]);
        }
        for (int i = 0; i < m; i++){
            if (a[v[i].t1] == a[v[i].t2]){
                flag = false;
                break;
            }
        }
        if (flag)
            printf("%d-coloring\n", se.size());
        else
            printf("No\n");
    }
    return 0;
}
//这题就是个纸老虎啊 set就用在统计一下颜色的种类上  
//这题看着看不懂 其实没用到什么算法