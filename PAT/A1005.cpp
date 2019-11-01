/***********************
1005. Spell It Right (20)
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every
digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space 
between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five
************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "12345";
    //cin >> s;
    string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int i;
    int num = 0;

    for (i = 0; i < s.length(); i++)
        num += s[i] - '0';

    string num_str = to_string(num);

    for (i = 0; i < num_str.length(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << (str[num_str[i] - '0']);
    }

    return 0;
}