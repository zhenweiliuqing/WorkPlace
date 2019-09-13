// //2019-5-28
// #include <iostream>
// #include <map>
// using namespace std;

// string earth_mars(int x){
//     string res = "";
//     while(x != 0){
//         res = to_string(x % 13) + res; 
//         x = x / 13;
//     }
//     return res;
// }

// map<string, int> m2e1;
// map<string, int> m2e2;
// map<int, string> e2m1;
// map<int, string> e2m2;

// int main(){
//     int n;
//     string s;
//     m2e1["jan"] = 1;
//     m2e1["feb"] = 2;
//     m2e1["mar"] = 3;
//     m2e1["apr"] = 4;
//     m2e1["may"] = 5;
//     m2e1["jun"] = 6;
//     m2e1["jly"] = 7;
//     m2e1["aug"] = 8;
//     m2e1["sep"] = 9;
//     m2e1["oct"] = 10;
//     m2e1["nov"] = 11;
//     m2e1["dec"] = 12;
//     m2e1["tret"] = 0;
//     m2e2["tam"] = 1;
//     m2e2["hel"] = 2;
//     m2e2["maa"] = 3;
//     m2e2["huh"] = 4;
//     m2e2["tou"] = 5;
//     m2e2["kes"] = 6;
//     m2e2["hei"] = 7;
//     m2e2["elo"] = 8;
//     m2e2["syy"] = 9;
//     m2e2["lok"] = 10;
//     m2e2["mer"] = 11;
//     m2e2["jou"] = 12;
//     e2m1[0] = "tret";
//     e2m1[1] = "jan";
//     e2m1[2] = "feb";
//     e2m1[3] = "mar";
//     e2m1[1] = "jan";

//     cin >> n;
//     while(n--){
//         cin >> s;
//         if (isdigit(s[0])){
//             string mars = earth_mars(stoi(s));
//             for (int i = 0; i < mars.size(); i++){
//                 if (i == 0)
//                     cout << mars[i] << " ";
//             }
//         }
//         else {

//         }
//     }
// }

//参考答案
#include <iostream>
#include <string>
using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string s;
int len;
void func1(int t){
    if (t / 13)
        cout << b[t / 13];
    if ((t / 13) && (t % 13))
        cout << " ";
    if (t % 13 || t == 0)
        cout << a[t % 13];
}
void func2(){
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3),s2;
    if (len > 4)
        s2 = s.substr(4, 3);
    for (int j = 1; j <= 12; j++){
        if (s1 == a[j] || s2 == a[j])
            t2 = j;
        if (s1 == b[j])
            t1 = j;
    }
    cout << t1 * 13 + t2;
}

int main(){
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++){
        getline(cin, s);
        len = s.length();
        if (s[0] >= '0' && s[0] <= '9')
            func1(stoi(s));
        else
            func2();
        cout << endl;
    }
    return 0;
}