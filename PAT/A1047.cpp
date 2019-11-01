//2019-1-30
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stu
{
    string name;
    vector<int> course;
};
bool cmp(string a, string b)
{
    return a < b;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<stu> v(n);
    vector<string> name[k];
    int m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].name >> m;
        int temp_course;
        for (int j = 0; j < m; j++)
        {
            cin >> temp_course;
            v[i].course.push_back(temp_course);
            name[temp_course - 1].push_back(v[i].name);
        }
    }
    for (int i = 0; i < k; i++)
    {
        sort(name[i].begin(), name[i].end(), cmp);
    }

    for (int i = 0; i < k; i++)
    {
        cout << i + 1 << " " << name[i].size() << endl;
        for (int j = 0; j < name[i].size(); j++)
        {
            cout << name[i][j] << endl;
        }
    }
    return 0;
}
//21分！ 有一个测试点超时！！！

