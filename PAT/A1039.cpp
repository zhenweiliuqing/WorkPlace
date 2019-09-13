//2018-8-11 18:57

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int stu_num, cou_num;
    cin >> stu_num >> cou_num;
    //vector<string> cou(cou_num);//定义课程数目  定义5个string?
    vector<vector<string>> content(cou_num);
    string *stu = new string[stu_num];//学生姓名输出
    vector<vector<int>> ans(stu_num);//学生选课输出
    int i,j;
    int cou_index, sel_num;
    string stu_name;
    for (i = 0; i < cou_num; i++)
    {
        cin >> cou_index >> sel_num;//课程下标 选课人数
        for (j = 0; j < sel_num; j++)
        {
            cin >> stu_name;
            content[cou_index - 1].push_back(stu_name);
        }
    }

    for (i = 0; i < stu_num; i++)
    {
        cin >> stu[i];
        for (j = 0; j < cou_num; j++)
        {
            for (k = 0; k < content[j].size(); k++)
                if (stu[i] == content[j][k])//选这门课的所有学生姓名如果有你
                    ans[i].push_back(j + 1);//这门课的编号push进去
        }
    }

    for (i = 0; i < stu_num; i++)
    {
        cout << stu[i] << " " << ans[i].size();
        for (j = 0; j < ans[i].size(); j++)
        {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    
    delete[] stu;
    return 0;
}
//19:51 
//自己完成 23分 只有一个测试点错误 运行超时！