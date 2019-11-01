//2019-1-22
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct 
{
    int hour, min, sec;
    int time;
} customer;

int cmp(customer a, customer b)
{
    if (a.hour != b.hour)
        return a.hour < b.hour;
    else if (a.min != b.min)
        return a.min < b.min;
    else
        return a.sec < b.sec;
}

int main()
{
    int n, k;//顾客 窗口
    cin >> n >> k;
    vector<customer> Cus(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d", &Cus[i].hour, &Cus[i].min, &Cus[i].sec, &Cus[i].time);
    }
    sort(Cus.begin(), Cus.end(), cmp);
    //不知道该怎么处理后续的谁先谁后问题
}

*/
//参考答案
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node 
{
    int come, time;
} tempcustomer;
bool cmp1(node a, node b)
{
    return a.come < b.come;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<node> custom;
    for (int i = 0; i < n; i++)
    {
        int hh, mm, ss, time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        int cometime = hh * 3600 + mm * 60 + ss;
        if (cometime > 61200)//17点
            continue;
        tempcustomer = {cometime, time * 60};
        custom.push_back(tempcustomer);
    }
    sort(custom.begin(), custom.end(), cmp1);
    vector<int> window(k, 28800);
    double result = 0.0;
    for (int i = 0; i < custom.size(); i++)//一个一个处理
    {
        int tempindex = 0, minfinish = window[0];
        for (int j = 1; j < k; j++)//选择一个最快结束的
        {
            if (minfinish > window[j])
            {
                minfinish = window[j];
                tempindex = j;
            }
        }
        if (window[tempindex] <= custom[i].come)//中间有空闲的时间 
        {
            window[tempindex] = custom[i].come + custom[i].time;
        }
        else 
        {
            result += (window[tempindex] - custom[i].come);
            window[tempindex] += custom[i].time;
        }
    }
    if (custom.size() == 0)
        printf("0.0");
    else
        printf("%.1f", result / 60.0 / custom.size());
    return 0;
}
