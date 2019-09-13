//2019-1-28
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m;
    cin >> m;
    //int order[54] = {36, 52, 37, 38, 3, 39, 40, 53, 54, 41, 11, 12, 13, 42, 43, 44, 2, 4, 23, 24, 25, 26, 27, 6, 7, 8, 48, 49, 50, 51, 9, 10, 14, 15, 16, 5, 17, 18, 19, 1, 20, 21, 22, 28, 29, 30, 31, 32, 33, 34, 35, 45, 46, 47};
    int order[54];
    for (int i = 0; i < 54; i++)
    {
        scanf("%d", &order[i]);
    }
    string s[54] = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
                    "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
                    "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
                    "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
                    "J1", "J2"};
    string temp[54];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 54; j++)
        {
            temp[order[j] - 1] = s[j];
        }
        for (int k = 0; k < 54; k++)
        {
            s[k] = temp[k];
        }
    }
    cout << temp[0];
    for (int i = 1; i < 54; i++)
    {
        cout << " " << temp[i];
    }
    return 0;
}

//非常开心的拿了满分！！！