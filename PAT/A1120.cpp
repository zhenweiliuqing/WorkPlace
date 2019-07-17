//2019-5-10
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    int n;
    string temp;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        int num = 0;
        for (int j = 0; j < temp.size(); j++){
            num += temp[j] - '0';
        }
        s.insert(num);
    }
    cout << s.size() << endl << *s.begin();
    for (auto it = s.begin(); it != s.end(); it++){
        if (it != s.begin())
            printf(" %d", *it);
    }
    return 0;
}
//easy!