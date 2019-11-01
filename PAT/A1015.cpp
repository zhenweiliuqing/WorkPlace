//2018-8-8 8：37
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

bool isPrime(int);
int ConverNum(int a, int b);

int main()
{
    int N, D; //整数 进制
    int reverse;
    scanf("%d", &N);
    while (N > 0)
    {
        scanf("%d", &D);
        if (N == 1)
        {
            printf("No\n");
            scanf("%d", &N);
            continue;
        }
        bool flag = false;
        flag = isPrime(N);
        if (!flag) //不是质数
        {
            printf("No\n");
            scanf("%d", &N);
            continue;
        }
        else
        {
            reverse = ConverNum(N, D);
            if (reverse == 1)
            {
                printf("No\n");
            }
            else
            {
                flag = isPrime(reverse);
                if (flag)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
            scanf("%d", &N);
            //scanf("%d", &D);
        }
    }

    return 0;
}

bool isPrime(int a)
{
    int b = a / 2;
    int i;
    for (i = 2; i <= b; i++)
    {
        if (a % i == 0) //能够整除
            return false;
    }
    if (i == b + 1)
        return true;
}

int ConverNum(int a, int b)
{
    int x[100] = {-1}; //只有第一个是-1 后边的不是-1
    int cnt = 0;
    int i;
    while (a != 0)
    {
        x[cnt++] = a % b;
        a /= b;
    }
    for (i = 0; i < cnt; i++)
    {
        a += x[i] * pow((float)b, cnt - 1 - i);
    }
    return a;
}
//9:15

//success ! 9:53