//2019-1-27
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct stu
{
    string name;
    char gender;
    string ID;
    int grade;
};
bool cmp1(stu a, stu b)
{
    return a.grade < b.grade;
}
bool cmp2(stu a, stu b)
{
    return a.grade > b.grade;
}
int main()
{
    int n;
    cin >> n;
    vector<stu> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].name >> v[i].gender >> v[i].ID >> v[i].grade;
        
        //scanf("%c", &v[i].gender);
        //cin >> v[i].ID;
        //scanf("%d", &v[i].grade);
    }
    vector<stu> boy;
    vector<stu> girl;
    sort(v.begin(), v.end(), cmp1);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].gender == 'M')
        {
            boy.push_back(v[i]);
            break;
        }
    }
    for (int j = v.size() - 1; j >= 0; j--)
    {
        if (v[j].gender == 'F')
        {
            girl.push_back(v[j]);
            break;
        }
    }
    if (girl.size() != 0)
        cout << girl[0].name << " " << girl[0].ID << endl;
    else
        cout << "Absent" << endl;
    if (boy.size() != 0)
        cout << boy[0].name << " " << boy[0].ID << endl;
    else
        cout << "Absent" << endl;
    if (girl.size() != 0 && boy.size() != 0)
        cout << abs(girl[0].grade - boy[0].grade);
    else
        cout << "NA";
}
//答案正确！ 非常吃惊的拿到满分！