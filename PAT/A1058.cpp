//2019-3-30
//今天写个简单的 20分的题

#include <iostream>
using namespace std;

int main()
{
    int x1, x2, x3, y1, y2, y3;
    int r1 = 0, r2 = 0, r3 = 0;
    scanf("%d.%d.%d %d.%d.%d", &x1, &x2, &x3, &y1, &y2, &y3);
    r1 = x1 + y1;
    r2 = x2 + y2;
    r3 = x3 + y3;
    if (r3 >= 29)
    {
        r2 += 1;
        r3 -= 29;
    }
    if (r2 >= 17)
    {
        r2 -= 17;
        r1++;
    }
    printf("%d.%d.%d", r1, r2, r3);
    return 0;
}
//这个是有点简单啊 关键是你得知道他的进制转换关系