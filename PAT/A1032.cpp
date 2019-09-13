//2019-1-26
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
    int st, end;
    char a;
};
int cmp(node a, node b)
{
    return a.end > b.end;
}
int main()
{
    int s1, s2, n;
    cin >> s1 >> s2 >> n;
    vector<node> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &v[i].st, &v[i].a, &v[i].end);
    }
    sort(v.begin(), v.end(), cmp);
    vector<node>::iterator it;
    it = adjacent_find(v.begin(), v.end());
    return 0;
}

//2019-1-26
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
    int st, end;
    char a;
};
int cmp(node a, node b)
{
    return a.end > b.end;
}
int main()
{
    int s1, s2, n;
    cin >> s1 >> s2 >> n;
    vector<node> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %d", &v[i].st, &v[i].a, &v[i].end);
    }
    sort(v.begin(), v.end(), cmp);
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].end == v[i-1].end)
		{
			printf("%05d", v[i].end);
			return 0;
		}
	}
	printf("-1");
    return 0;
}
//22分 ！ 部分正确！！！
#endif

//参考答案
#include <cstdio>
using namespace std;
struct NODE
{
    char key;
    int next;
    bool flag;
} node[100000];
int main()
{
    int s1, s2, n, a, b;
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    for (int i = s1; i < n; i++)
    {
        scanf("%d %c %d", &a, &data, &b);
        node[a] = {data, b, false};
    }
    for (int i = s1; i != -1; i = node[i].next)
    {
        node[i].flag = true;
    }
    for (int i = s2; i != -1; i = node[i].next)
    {
        if (node[i].flag == true)
        {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}