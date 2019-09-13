//2018-8-19 13：43
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    string s = "";
    while (c != 0)
    {
        s = to_string(c % 13) + s;
        c /= 13;
    }
    while (b != 0)
    {
        s = to_string(b % 13) + s;
        b /= 13;
    }
    while (a != 0)
    {
        s = to_string(a % 13) + s;
        a /= 13;
    }

    s = '#' + s;
    cout << s;
    return 0;
}*/

#include <iostream>
using namespace std;
int main()
{
    char a[14] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D'};
    //char a[15] = {"0123456789ABCD"};
    int num;
    cout << "#";
    for (int i = 0; i < 3; i++)
    {
        cin >> num;
        cout << a[num / 13] << a[num % 13];
    }
    return 0;
}