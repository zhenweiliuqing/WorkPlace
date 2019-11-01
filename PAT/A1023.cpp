/*******************************
1023. Have Fun with Numbers (20)
Notice that the number 123456789 is a 9-digit number consisting exactly 
the numbers from 1 to 9, with no duplication. Double it we will obtain 
246913578, which happens to be another 9-digit number consisting exactly
the numbers from 1 to 9, only in a different permutation. Check to see 
the result if we double it again!
Now you are suppose to check if there are more numbers with this property.
That is, double a given number with k digits, you are to tell if the 
resulting number consists of only a permutation of the digits in the 
original number.
Input Specification:
Each input file contains one test case. Each case contains one positive 
integer with no more than 20 digits.
Output Specification:
For each test case, first print in a line "Yes" if doubling the input 
number gives a number that consists of only a permutation of the digits 
in the original number, or "No" if not. Then in the next line, print the
doubled number.
Sample Input:
1234567899
Sample Output:
Yes
2469135798
********************************/

#include <iostream>
#include <string>

using namespace std;
/*
int main()
{
    long long num = 73824141289482132423;
  //  = 12345678998765432;
    //cin >> num;
    long long double_num = num * 2;

    string s1 = to_string(num);
    string s2 = to_string(double_num);
    int i;
    int flag = 0;
    int flag1[10] = {0};
    int flag2[10] = {0};

    if (s1.length() != s2.length())
    {
        cout << "No" << endl;
    }
    else
    {
        for (i = 0; i < s1.length(); i++)
        {
            flag1[s1[i] - '0']++;
            flag2[s2[i] - '0']++;
        }

        for (i = 0; i < s1.length(); i++)
        {
            if (flag1[i] != flag2[i])
            {
                cout << "No" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "Yes" << endl;
    }

    cout << double_num << endl;
    return 0;
}*/
//2018-8-4 8:50
int main()
{
    string s;
    //cin >> s;
    s = "1234567899";
    string s2 = "";
    int i;
    int flag1[10] = {0};
    int flag2[10] = {0};
    char add = 0;//进位标志位
    int yes = 1;

    for (i = s.length() - 1; i >= 0; i--)
    {
        flag1[s[i]- '0']++;//这个相减是int型？
        char a = 0;
        a = (s[i] - '0') * 2;//char 能强制转化为 int 吗 char的字符型 强制转化为 char 的数值型会怎么样？？？
        a += add;
        if (a >= 10)
        {
            a -= 10;
            add = 1;
        }
        else
        {
            add = 0;
        }
        flag2[int(a)]++;//去掉强制转换有警告
        s2 = char(a + '0') + s2;
    }
    if (add == 1)
    {
        s2 = '1' + s2;
        flag2[1]++;
        add = 0;
    }

    for (i = 0; i < s.length();i++)
    {
        if (flag1[i] != flag2[i])
        {
            cout << "No" << endl;
            yes = 0;
            break;
        }
    }

    if (yes == 1)
        cout << "Yes" << endl;

    cout << s2 << endl;
    return 0;
}
