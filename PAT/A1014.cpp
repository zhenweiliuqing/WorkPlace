//2019-2-18
//参考答案
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int poptime, endtime;
    queue<int> q;
};
int main()
{
    int n, m, k, q, index = 1;
    scanf("%d%d%d%d", &n, &m, &k, &q);//n个窗口 队里m个人 k个顾客 q个查询 
    vector<int> time(k + 1), result(k + 1);
    for (int i = 1; i<= k; i++)
    {
        scanf("%d", &time[i]);//每个顾客办理业务所需的时间
    }
    vector<node> window(n + 1);
    vector<bool> sorry(k + 1, false);
    for (int i = 1; i <= m; i++)//每个窗口前有m个人
    {
        for (int j = 1; j <= n; j++)//一共有n个窗口
        {
            if (index <= k)
            {
                window[j].q.push(time[index]);
                if (window[j].endtime >= 540)//先判断是不是超过了下班时间
                    sorry[index] = true;
                window[j].endtime += time[index];//加上endtime
                if (i == 1)//队首的人
                    window[j].poptime = window[j].endtime;//目前窗口的pop时间等于第一个人的完成时间
                result[index] = window[j].endtime;//index的结束时间就是目前窗口的结束时间
                index++;
            }
        }
    }//这是队不满的情况下按着顺序先补满
    while (index <= k)
    {
        int tempmin = window[1].poptime, tempwindow = 1;
        for (int i = 2; i <= n; i++)//找一个最先有空位的队伍
        {
            if (window[i].poptime < tempmin)
            {
                tempwindow = i;
                tempmin = window[i].poptime;
            }
        }
        window[tempwindow].q.pop();//弹出
        window[tempwindow].q.push(time[index]);//压入
        window[tempwindow].poptime += window[tempwindow].q.front();//现在弹出时间修改为再加上队列首元素的时间
        if (window[tempwindow].endtime >= 540)
            sorry[index] = true;
        window[tempwindow].endtime += time[index];
        result[index] = window[tempwindow].endtime;
        index++;
    }
    for (int i = 1; i <= q; i++)//输出结果
    {
        int query, minute;
        scanf("%d", &query);
        minute = result[query];
        if (sorry[query] == true)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", (minute + 480) / 60, (minute + 480) % 60);
    }
    return 0;
}