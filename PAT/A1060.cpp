//2019-4-3
#if 0
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int n;
    double a, b;
    scanf("%d", &n);
    cin >> a >> b;

    /*
    //可以相减比较 得知道这个数是多大 有几位 
    //相减后依次与最高位比较
    int k;//这两个数整数有几位
    float res = abs(a - b);
    //小数部分该怎么处理 没事 可以先相减
    int inta = (int)a;
    string stra = to_string(inta);
    k = stra.size();//整数部分搞定

    if ()
    //感觉要想知道这个数有几位还是比较麻烦 
    */
    int k;
    int inta = (int)a;
    string stra = to_string(inta);
    k = stra.size();//整数部分搞定

    while (n != 0)
    {
        if (fmod(a, pow(10,k - 1)) == fmod(b, pow(10, k - 1)))
        {
            n--;
            k--;
        }
        //感觉到后边越来越麻烦
    }
}
#endif
//参考答案

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, p = 0, q = 0;
    char a[10000], b[10000], A[10000], B[10000];
    scanf("%d%s%s", &n, a, b);
    int cnta = strlen(a), cntb = strlen(b);
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == '.')
        {
            cnta = i;
            break;
        }
    }
    for (int i = 0; i < strlen(b); i++)
    {
        if (b[i] == '.')
        {
            cntb = i;
            break;
        }
    }
    int indexa = 0, indexb = 0;
    while (a[p] == '0' || a[p] == '.')
        p++;
    while (b[q] == '0' || b[q] == '.')
        q++;
    
    if (cnta >= p)
        cnta = cnta - p;
    else
        cnta = cnta - p + 1;
    if (cntb >= q)
        cntb = cntb - q;
    else
        cntb = cntb - q + 1;

    if (p == strlen(a))
        cnta = 0;
    if (q == strlen(b))
        cntb = 0;
    
    while (indexa < n)
    {
        if (a[p] != '.' && p < strlen(a))
            A[indexa++] = a[p];
        else if (p >= strlen(a))
            A[indexa++] = '0';
        p++;
    }

    while (indexb < n)
    {
        if (b[q] != '.' && q < strlen(b))
            B[indexb++] = b[q];
        else if (q >= strlen(b))
            B[indexb++] = '0';
        q++;
    } 

    if (strcmp(A, B) == 0 && cnta == cntb)
        printf("YES 0.%s*10^%d", A, cnta);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d", A, cnta, B, cntb);
    return 0;
}