//2019-1-26
#if 0
#include <iostream>
using namespace std;

int main()
{
    int cmax, dis, davg, num;
    cin >> cmax >> dis >> davg >> num;
    for (int i = 0; i < num; i++)
    {

    }
}
#endif

//参考答案
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999;
struct station
{
    double price, dis;
};
bool cmp1(station a, station b)
{
    return a.dis < b.dis;
}
int main()
{
    double cmax, d, davg;
    int n;
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    vector<station> sta(n + 1);
    sta[0] = {0.0, d};
    for (int i = 1; i <= n;i++)
    {
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    }
    sort(sta.begin(), sta.end(), cmp1);
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;
    
    if (sta[0].dis != 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    else 
    {
        nowprice = sta[0].price;
    }

    while (nowdis < d)
    {
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = inf;
        int flag = 0;
        for (int i = 1; i <= n && sta[i].dis <= maxdis; i++)
        {
            if (sta[i].dis <= nowdis)//如果已经过了或到达了这一站
                continue;
            if (sta[i].price < nowprice)//下一站的油比这一站便宜
            {
                totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;
                leftdis = 0.0;//所以我在这一站就不存油了
                nowprice = sta[i].price;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            if (sta[i].price < minPrice)
            {
                minPrice = sta[i].price;
                minPriceDis = sta[i].dis;
            }
        }
        if (flag == 0 && minPrice != inf)//在下站没有找到更便宜的油
        {
            totalPrice += (nowprice * (cmax - leftdis / davg));//现在的油价×油箱容量-油箱内剩余的油
            leftdis = cmax * davg - (minPriceDis - nowdis);//最大行程600 - (行程内最便宜油站的位置-现在的位置)
            nowprice = minPrice;
            nowdis = minPriceDis;
        }
        if (flag == 0 && minPrice == inf)
        {
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}


//A1033 应该得用动态规划
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct station
{
    double price;
    int dis;
};
bool cmp(station a, station b)
{
    return a.dis < b.dis;
}
int main()
{
    int cmax, des, dav, n;
    cin >> cmax >> des >> dav >> n;
    vector<station> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].price >> v[i].dis;
    }
    v[n].dis = des;
    v[n].price = 0.00;
    sort(v.begin(), v.end(), cmp);
    int resdis = cmax * dav;//油箱中剩余的油能够行驶的距离
    int nowstation = 0;
    int nowpos = 0;//现在汽车的里程位置
    int sum = 0;
    while (nowpos < des)//没有到达终点的时候
    {
        if (v[nowstation + 1].price < v[nowstation].price)
        {
            resdis = 0;//不存油
            nowpos = v[nowstation + 1].dis;
            sum += (nowpos - v[nowstation].dis) * v[nowstation].price;
            nowstation++;
        }
        else//油价如果不便宜 
        {
            int cheapest = nowstation + 1;
            for (int i = nowstation + 2; v[i].dis <= nowpos + resdis; i++)
            {
                if (v[i].price < v[cheapest].price)//有更便宜的油站
                {
                    cheapest = i;
                    //下一步该怎么处理啊 ！
                }

            }
        }
    }
} 