//2018-8-21 8:45
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n; //输入数字何进制
    vector<int> v;
    if (m == 0)
    {
        cout << "Yes" << endl;
        cout << m;
        return 0;
    }
    while (m != 0)
    {
        v.push_back(m % n);
        m /= n;
    }
    int i, j;
    for (i = 0, j = v.size() - 1; i < v.size(), j >= 0; i++, j--)
    {
        if (v[i] != v[j])
        {
            cout << "No" << endl;
            break;
        }
        else if (i == j)
        {
            cout << "Yes" << endl;
            break;
        }
    }

    for (i = v.size() - 1; i >= 0; i--) //得反着输出
    {
        cout << v[i];
        if (i != 0)
            cout << " ";
    }
    return 0;
}

//9：10 满分！