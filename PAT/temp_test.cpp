//A1010
#include <iostream>
#include <cmath>
using namespace std;
string n1, n2;
int cometen(string n, int radix)
{
    int num = 0;
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] >= '0' && n[i] <= '9')
            num += (n[i] - '0') * pow(radix, n.length() - i - 1);
        else if (n[i] >= 'a' && n[i] <= 'z')
            num += (n[i] - 'a') * pow(radix, n.length() - i - 1);
    }
    return num;
}
bool compare(string n, int a)
{
    int lradix = 2;
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] >= '0' && n[i] <= '9' && (n[i] -'0') > lradix)
            lradix = (n[i] - '0') + 1;
        else if (n[i] >= 'a' && n[i] <= 'z' && (n[i] -'a') > lradix)
            lradix = (n[i] - 'a') + 1;
    }
    for (int i = lradix; i <= 37; i++)
    {
        if (a == cometen(n, lradix))
            return true;
    }
    return false;
}
int main()
{
    int tag, radix;
    int x, y;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 1)
        x = cometen(n1, radix);
    else if (tag == 2)
        y = cometen(n2, radix);
    
}