//2018-8-19 10：58
/*
#include <iostream>
using namespace std;
int main()
{
    
    return 0;
}
*/
//参考答案
//2019-1-22
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
long long convert(string n, long long radix)//转化为10进制
{
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.begin(); it != n.end(); it++)
    {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;//a-z 10-35 
        sum += temp * pow(radix, index++);
    }
    return sum;
}

long long find_radix(string n, long long num)//找到合适的进制进行匹配 第一个参数不知道进制 第二个是十进制 
{
    char it = *max_element(n.begin(), n.end());//找到最大数 进制大于这个数
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;//low 最低这个进制
    long long high = max(num, low);//最高是那个数字的进制
    while (low <= high)
    {
        long long mid = (low + high) / 2;//二分法转化进制
        long long t = convert(n, mid);
        if (t < 0 || t > num)
            high = mid - 1;
        else if (t == num)
            return mid;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1)
    {
        printf("%lld", result_radix);
    }
    else 
    {
        printf("Impossible");
    }
    return 0;
}