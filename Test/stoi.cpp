// 2019-9-28
#include <iostream>
using namespace std;
int main() {
    string temp = "2234.234";
    int x = stoi(temp);
    cout << x << endl;
    int sub1 = stoi(temp.substr(0, 4));
    int sub2 = stoi(temp.substr(5, 3));
    cout << sub1 << " " << sub2 << endl;
}