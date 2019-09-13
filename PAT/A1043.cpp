//2019-1-29
#if 0
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> pre_order(n);
    vector<int> pre_order_mi(n);
    pre_order[0] = pre_order_mi[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > )
    }
}
#endif

//参考答案
#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail)
{
    if (root > tail)//这是最底层
        return;
    int i = root + 1, j = tail;
    //核心代码 是在 先序遍历中递归找到左分支 然后把最左的压入  
    if (!isMirror)//不是镜像
    {
        while (i <= tail && pre[root] > pre[i])//找到左分支 根节点大于左分支 节点数小于尾节点
            i++;
        while (j > root && pre[root] <= pre[j])//反之亦然
            j--;
    }
    else //是镜像！
    {
        while (i <= tail && pre[root] <= pre[i])
            i++;
        while (j > root && pre[root] > pre[j])
            j--;
    }
    if (i - j != 1)//？？？这个有什么用？ 正常情况下 i从前往后加到比根大 j从后往前减到比根小
        return;
    getpost(root + 1, j);//j是左分支的结束
    getpost(i, tail);//i是右分支的开始
    post.push_back(pre[root]);
}//先序变后序

int main()
{
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }
    getpost(0, n - 1);
    if (post.size() != n)
    {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if (post.size() == n)
    {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; i++)
        {
            printf(" %d", post[i]);
        }
    }
    else
    {
        printf("NO");
    }

    return 0;
}