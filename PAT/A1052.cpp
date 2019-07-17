//2019-4-1
//回过头来看这道题

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    int address, num, next;
    bool flag;
};

int address[10010];

int main()
{
    int n, head;
    int cnt = 0;
    cin >> n >> head;
    vector<node> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].address >> v[i].num >> v[i].next;
        address[v[i].address] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i].next == -1)//是尾节点
            v[i].flag = true;
        else if (address[v[i].next] == 1)//说明这个节点后继有人
            v[i].flag = true;
    }
}

//得到21分是比较容易的 因为有两个测试点需要考虑到不在这个链表中的情况
//就比较麻烦了 

//看了答案 其实挺简单的 怎么自己就没有想出来呢 一直没有思考                                            