//2019-1-24
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node 
{
    long long id;
    int score, loc;
    int loc_rank, all_rank;
};
int cmp(node a, node b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.id < b.id;
}
void make_order(vector<node>::iterator beg, vector<node>::iterator end)//rank.begin()形参怎么写
{
    beg->loc_rank = 1;
    beg++;
    for (int i = 1; beg != end; i++)
    {
        if (beg->score == (beg-1)->score)//分数相同
            beg->loc_rank = (beg - 1)->loc_rank;
        else 
            beg->loc_rank = i + 1;
        beg++;
    }
}
void make_order_all(vector<node>::iterator beg, vector<node>::iterator end)//rank.begin()形参怎么写
{
    beg->all_rank = 1;
    beg++;
    for (int i = 1; beg != end; i++)
    {
        if (beg->score == (beg-1)->score)//分数相同
            beg->all_rank = (beg - 1)->all_rank;
        else 
            beg->all_rank = i + 1;
        beg++;
    }
}
int main()
{
    int n;//区域数
    scanf("%d", &n);
    vector<int> v(n);
    vector<node> rank;
    node temp;
    long long id;
    int score;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        for (int j = 0; j < v[i]; j++)
        {
            cin >> id >> score;
            temp.id = id;
            temp.score = score;
            temp.loc = i + 1;
            rank.push_back(temp);
        }
        if (i == 0)
        {
            sort(rank.begin(), rank.end(), cmp);
            make_order(rank.begin(), rank.end());
        }
        else
        {
            num += v[i - 1];
            sort(rank.begin() + num, rank.end(), cmp);
            make_order(rank.begin() + num, rank.end());
        } 
    }
    sort(rank.begin(), rank.end(), cmp);
    make_order_all(rank.begin(), rank.end());
    cout << rank.size() << endl;
    for (int i = 0; i < rank.size(); i++)
    {
        cout << rank[i].id << " " << rank[i].all_rank << " " << rank[i].loc << " " << rank[i].loc_rank;
        if (i < rank.size() - 1)
            printf("\n");
    }
}

//感动！！！ 独立自主完成的 22分！ 最后一个测试点错了
#endif

//参考答案
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct student
{
    long long int no;
    int score, finarank, loca, locarank;
};
bool cmp1(student a, student b)
{
    return a.score != b.score ? a.score > b.score : a.no < b.no;
}
int main()
{
    int n,m;
    scanf("%d", &n);
    vector<student> fin;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        vector<student> v(m);
        for (int j = 0; j < m; j++)
        {
            scanf("%lld %d", &v[j].no, &v[j].score);
            v[j].loca = i;
        }
        sort(v.begin(), v.end(), cmp1);
        v[0].locarank = 1;
        fin.push_back(v[0]);
        for (int j = 1; j < m; j++)
        {
            v[j].locarank = (v[j].score == v[j - 1].score) ? (v[j - 1].locarank) : (j + 1);
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(), fin.end(), cmp1);
    fin[0].finarank = 1;
    for (int j = 1; j < fin.size(); j++)
    {
        fin[j].finarank = (fin[j].score == fin[j - 1].score) ? (fin[j - 1].finarank) : (j + 1);
    }
    printf("%d\n", fin.size());
    for (int i = 0; i < fin.size();i++)
        printf("%013lld %d %d %d\n", fin[i].no, fin[i].finarank, fin[i].loca, fin[i].locarank);
    return 0;
}