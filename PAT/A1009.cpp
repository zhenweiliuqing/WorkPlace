//2018-8-6 9：05
/*
#include <iostream>//如何输出一位小数？
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int A, B;
    int i,j;
    cin >> A;
    vector<int> ex_a(A);//指数
    vector<float> co_a(A);//系数
    for (i = 0; i < A; i++)
    {
        cin >> ex_a[i];
        cin >> co_a[i];
    }

    cin >> B;
    vector<int> ex_b(B);
    vector<float> co_b(B);
    for (i = 0; i < B; i++)
    {
        cin >> ex_b[i];
        cin >> co_b[i];
    }

    int S = A * B;//结果个数
    int cnt = 0;//S的下标
    vector<int> ex_s(S);
    vector<float> co_s(S);
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < B; j++)
        {
            ex_s[cnt] = ex_a[i] + ex_b[j];//指数相加
            co_s[cnt++] = co_a[i] * co_b[j];//系数相乘
        }
    }//没有问题 9：46

    
    for (i = 0; i < S; i++)
    {
        for (j = i + 1; j < S; j++)
        {
            if (ex_s[i] == ex_s[j] && ex_s[i] != -1 && ex_s[j] != -1)
            {
                co_s[i] += co_s[j];//系数相加
                ex_s[j] = co_s[j] = -1;
            }
        }
    }

    //冒泡法
    int ex;
    float co;
    for (i = 0; i < S; i++)
    {
        for (j = 0; j < S - i - 1; j++)
        {
            if (ex_s[j] < ex_s[j + 1])
            {
                ex = ex_s[j];
                ex_s[j] = ex_s[j + 1];
                ex_s[j + 1] = ex;

                co = co_s[j];
                co_s[j] = co_s[j + 1];
                co_s[j + 1] = co;
            }
        }
    }

    int count = 0;
    for (i = 0; i < S; i++)
    {
        if (ex_s[i] != -1)
            count++;
    }
    printf("%d ", count);
    for (i = 0; i < count; i++)
    {
        printf("%d %.f", ex_s[i], co_s[i]);
        if (ex_s[i + 1]!= -1)
            printf(" ");
    }
    
    return 0;
}
*/

//reference answer
//2018-8-7 9：30
//2018-8-7 9：30
#include <cstdio>
using namespace std;
int main()
{
    int n1, n2, e, cnt = 0; //只有cnt自己初始化为0
    int i, j;
    float c; //系数
    float arr[1001] = {0.0};
    float ans[2001] = {0.0};
    //cin >> n1; //第一组数列的个数
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d %f", &e, &c);
        //cin >> e >> c;
        arr[e] = c; //对号入座
    }
    scanf("%d", &n2);
    //cin >> n2; //第二组
    for (i = 0; i < n2; i++)
    {
        scanf("%d %f", &e, &c);
        //cin >> e >> c;
        for (j = 0; j < 1001; j++)
        {
            if (arr[j] != 0.0)
            {
                ans[j + e] += c * arr[j];
            }
        }
    }

    for (i = 0; i < 2001; i++)
    {
        if (ans[i] != 0.0)
            cnt++;
    }
    //cout << cnt;
    printf("%d", cnt);
    for (i = 2000; i >= 0; i--)
    {
        if (ans[i] != 0.0)
        {
            //cout << " " << i << " ";
            printf(" %d %.1f",i, ans[i]);
        }
    }
    return 0;
}
//2018-8-7 9:43