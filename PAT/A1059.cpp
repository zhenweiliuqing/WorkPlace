//2019-3-31
//一个数可以由质数与1相乘得到
//判断这个数是不是质数
#include <iostream>
#include <map>
using namespace std;
long long n;
map<int, int> m;

void isPrime(long long n)
{
    int i = 2;
    //int index = i;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            m[i]++;
            n /= i;
            i--;
        }
        i++;
    }
    m[n]++;
}

int main()
{
    scanf("%ld", &n);
    printf("%ld=", n);
    isPrime(n);
    map<int, int>::iterator iter;
    iter = m.begin();
    if (iter->second > 1)
        printf("%d^%d", iter->first, iter->second);
    else
        printf("%d", iter->first);
    iter++;
    for (; iter != m.end(); iter++)
    {
        if (iter->second > 1)
            printf("*%d^%d", iter->first, iter->second);
        else
            printf("*%d", iter->first);
    }
    return 0;
}
//非常开心拿了满分！！！