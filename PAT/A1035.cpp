//2018-8-20 14：51

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int num;     //输入个数
    int cnt = 0; //记录修改的个数
    bool FLAG = false;
    cin >> num;
    bool *Y = new bool[num];
    string *s1 = new string[num];
    string *s2 = new string[num];

    for (int i = 0; i < num; i++)
    {
        cin >> s1[i] >> s2[i];
        Y[i] = false;
        for (int j = 0; j < s2[i].length(); j++)
        {
            if (s2[i][j] == '0' || s2[i][j] == 'O' || s2[i][j] == '1' || s2[i][j] == 'l')
            {
                FLAG = true;
                if (s2[i][j] == '0')
                    s2[i][j] = '%';
                else if (s2[i][j] == 'O')
                    s2[i][j] = 'o';
                else if (s2[i][j] == '1')
                    s2[i][j] = '@';
                else if (s2[i][j] == 'l')
                    s2[i][j] = 'L';
            }
        }
        if (FLAG)
        {
            cnt++; //如果作过修改 记录下来修改过的个数
            Y[i] = true;
            FLAG = false;
        }
    }

    if (cnt == 0) //没有修改
    {
        if (num == 1)
            cout << "There is 1 account and no account is modified";
        else
            cout << "There are " << num << " accounts and no account is modified";
    }
    else
    {
        cout << cnt;
        for (int i = 0; i < num; i++)
        {
            if (Y[i])
            {
                cout << endl;
                cout << s1[i] << " " << s2[i];
            }
        }
    }

    delete[] Y;
    delete[] s1;
    delete[] s2;
    return 0;
}
//15：59 20 points!