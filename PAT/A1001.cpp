//Time:2018-8-1

#include <iostream>

using namespace std;

int main()
{
    int a, b;
    //cin >> a >> b;
    a = -140030;
    b = -3;
    string s = to_string(a + b);//将 a + b 转换成字符
    int len = s.length();//计算出字符串的长度

    for (int i = 0 ;i < len; i++)
    {
        cout << s[i];
        if (s[i] == '-')
            continue;
        //if ((i + 1) % 3 == len % 3 && i != len - 1)//前面 && 最后一位不加逗号
        //248,425,350,213  
        if ( (len - 1 - i) % 3 == 0 && (len - 1 - i) != 0 )  
            cout << ",";
    }
    
    return 0;
}
