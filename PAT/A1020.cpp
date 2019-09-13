//2018-8-11 18：13
#include <iostream>
#include <vector>

using namespace std;

vector<int> post, in, level(100000, -1);
void pre(int root,int start,int end,int index)
{
    if (start > end)
        return;
    int i = start;
    while (i < end && in[i] != post[root])
        i++;
    level[index] = post[root];
    pre(root - 1 + i - end, start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    in.resize(n);
    post.resize(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    pre(n - 1, 0, n - 1, 0);
    for (int i = 0; i < level.size(); i++)
    {
        if (level[i] != -1)
        {
            if (cnt != 0)
                printf(" ");
            printf("%d", level[i]);
            cnt++;
        }
        if (cnt == n)
            break;
    }
    return 0;
}

//2018-8-21 10：11

#include <iostream>
#include <vector>
using namespace std;
//int pre[7] = {0};
//int post[] = {2,3,1,5,7,6,4};
//int in[] = {1,2,3,4,5,6,7};
//int post[] = {7,3,6,9,4,2,1};
//int in[] = {7,3,1,9,6,2,4};
vector<int> in;
vector<int> post;
vector<int> level(10000, -1);

void pref(int root, int start, int end, int index) //root为post中根的位置 start , end为in中查找的位置
{
    if (start > end)
        return;
    int i = start;
    while (in[i] != post[root] && i < end) //找到了中序中的根
    {
        i++;
    }
    level[index] = post[root];
    //pre[index++] = post[root];
    pref(root - (end - i) - 1, start, i - 1, 2 * index + 1); //左子树 根的位置为root - 右子树个数 - 1
    pref(root - 1, i + 1, end, 2 * index + 2);               //右子树
}
int main()
{
    int n, a; //输入数字个数
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        post.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        in.push_back(a);
    }
    pref(n - 1, 0, n - 1, 0);
    int cnt = 0;
    int j = 0;
    while (cnt < n)
    {
        if (level[j] != -1)
        {
            cout << level[j];
            cnt++;
            if (cnt != n)
                cout << " ";
        }
        j++;
    }
    return 0;
}

