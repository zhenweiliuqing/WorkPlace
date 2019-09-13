//2019-1-25
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct student
{
    int id, grade;
    string name;
};
int cmp1(student a, student b)
{
    return a.id < b.id;
}
int cmp2(student a, student b)
{
    return a.name != b.name ? (a.name < b.name) : (a.id < b.id);
}
int cmp3(student a, student b)
{
    return a.grade != b.grade ? (a.grade < b.grade) : (a.id < b.id);
}
int main()
{
    int n, flag;
    scanf("%d %d", &n, &flag);
    vector<student> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i].id);
        cin >> v[i].name;
        scanf("%d", &v[i].grade);
    }
    if (flag == 1)
        sort(v.begin(), v.end(), cmp1);
    else if (flag == 2)
        sort(v.begin(), v.end(), cmp2);
    else if (flag == 3)
        sort(v.begin(), v.end(), cmp3);

    for (int i = 0; i < n; i++)
        printf("%06d %s %d\n", v[i].id, v[i].name.c_str(), v[i].grade);
    return 0;
}
//满分！ 可以啊！
