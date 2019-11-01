//input 2 1 2.4 0 3.2
//      2 2 1.5 1 0.5
//output 
//      3 2 1.5 1 2.9 0 3.2
//难点：怎么让他输入到两个数组里呢?
//怎么让它

//解题思路：设置两个数组 一个是普遍的 一个是有数的 
/*
#include <iostream>

using namespace std;
#define N 101

int main()
{
    float a[N], b[N];
    float x[N];
    int i,j;

    a[0] = b[0] = 2;
    a[1] = 1;
    a[2] = 2.4;
    a[3] = 0;
    a[4] = 3.2;
    b[1] = 2;
    b[2] = 1.5;
    b[3] = 1;
    b[4] = 0.5;
    
    cin >> a[0];//输入个数
    for (i = 1; i <= 2 * a[0]; i++)
    {
        cin >> a[i];
    }

    cin >> b[0]; //输入个数
    for (i = 1; i <= 2 * b[0]; i++)
    {
        cin >> b[i];
    }
    
    x[0] = 0;//这是给标准数组赋初值
    for (i = 1; i < N; i+=2)
    {
        x[i] = (i + 1) / 2 - 1;
        x[i + 1] = 0;
    }

    for (i = 1; i < N; i+=2)//将输入的参数转移到标准数组里 这是一共有N/2个参数
    {
        for (j = 1; j <= a[0]*2; j+=2)//a数组中一共有a[0]个数
        {
            if (a[j] == x[i]) //如果指数相同
            {
                x[i + 1] += a[j + 1];
            }
        }

        for (j = 1; j <= b[0] * 2; j+=2)
        {
            if (b[j] == x[i])
            {
                x[i + 1] += b[j + 1];
            }
        }
    }

    for (i = 2; i < N; i+=2)
    {
        if(x[i] != 0)
            x[0]++;
    }

    cout << x[0] << " ";
    for (i = 1; x[i + 1] != 0; i += 2)
    {
        cout << x[i] << " " << x[i + 1];

        if (x[i + 1] != 0)
            cout << " ";
        else
            break;
        // << " " << x[i + 1];
    }
    return 0;
}
*/

//new idea 2018-8-8 9:57
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    //float input[1001] = {0.0};
    float result[1001] = {0.0};
    int n1, n2;
    int e;
    float c; //指数 系数
    int i;
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d %f", &e, &c);
        result[e] += c;
    }

    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%d %f", &e, &c);
        result[e] += c;
    }

    int cnt = 0;
    for (i = 0; i < 1001; i++)
    {
        if (result[i] > 0.0)
        {
            cnt++;
        }
    }

    printf("%d", cnt);
    for (i = 1000; i >= 0; i--)
    {
        if (result[i] > 0.0)
        {
            printf(" %d %.1f", i, result[i]);
        }
    }
    return 0;
}
//10:11

//!= 0.0 没有bug why?
//result[i] > 0.0 || result[i] < 0.0 OK!!!