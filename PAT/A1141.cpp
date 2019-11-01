// //2019-5-22
// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>
// #include <algorithm>
// using namespace std;
// struct node{
//     string school;
//     int order;
// };
// int main()
// {
//     int n;
//     cin >> n;
//     string name, school;
//     int score;
//     map<string, int> m_score;
//     map<string, int> m_num;
//     for (int i = 0; i < n; i++){
//         cin >> name >> score >> school;
//         string sch_low;
//         for (int j = 0; j < school.size(); j++)
//             sch_low[j] = tolower(school[j]);
//         m_num[sch_low]++;
//         if (name[0] == 'T')
//             m_score[sch_low] += score * 1.5;
//         else if (name[0] == 'A')
//             m_score[sch_low] += score;
//         else if (name[0] == 'B')
//             m_score[sch_low] += score / 1.5;
//     }
//     vector<node> ans(m_num.size());
//     for (auto it : m_num){
//         ans.push_back({it.first, it.second});
//     }
// }

//参考答案
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// struct node{
//     string school;
//     int tws, ns;
// };
// bool cmp(node a, node b){
//     if (a.tws != b.tws)
//         return a.tws > b.tws;
//     else if (a.ns != b.ns)
//         return a.ns < b.ns;
//     else
//         return a.school < b.school;
// }

// int main(){
//     int n;
//     scanf("%d", &n);
//     unordered_map<string, int> cnt;
//     unordered_map<string, double> sum;
//     for (int i = 0; i < n; i++){
//         string id, school;
//         cin >> id;
//         double score;
//         scanf("%lf", &score);
//         cin >> school;
//         for (int j = 0; j < school.length(); j++)
//             school[j] = tolower(school[j]);
//         if (id[0] == 'B')
//             score = score / 1.5;
//         else if (id[0] == 'T')
//             score = score * 1.5;
//         sum[school] += score;
//         cnt[school]++;
//     }
//     vector<node> ans;
//     // for (auto it = cnt.begin(); it != cnt.end(); it++)
//     for (auto it : cnt)
//     {
//         ans.push_back(node{it.first, (int)sum[it.first], cnt[it.first]});
//     }
// }

//2019-5-30
//设计思路：识别到学校的名称 记录这个学校的考生 及 总分
//还不是很清晰
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
struct node{
    string s;
    int score, cnt;
};
bool cmp(node a, node b){
    if (a.score != b.score)
        return a.score > b.score;
    else if (a.cnt != b.cnt)
        return a.cnt < b.cnt;
    else
        return a.s < b.s;
}
int main(){
    int n;
    cin >> n;
    double score;
    string id, school;
    unordered_map<string, double> sum_score;
    unordered_map<string, int> sum_stu;
    for (int i = 0; i < n; i++){
        cin >> id >> score >> school;
        for (int j = 0; j < school.size(); j++){
            school[j] = tolower(school[j]);
        }
        if (id[0] == 'A')
            sum_score[school] += score;
        else if (id[0] == 'B')
            sum_score[school] += score / 1.5;
        else
            sum_score[school] += score * 1.5;
        sum_stu[school]++;
    }
    vector<node> v;
    for (auto it : sum_score){
        v.push_back({it.first, (int)sum_score[it.first], sum_stu[it.first]});
    }
    sort(v.begin(), v.end(), cmp);
    int rank = 1;
    printf("%d\n", v.size());
    printf("%d %s %d %d\n",rank, v[0].s.c_str(), v[0].score, v[0].cnt);
    int lastrank = 1;
    for (int i = 1; i < v.size(); i++){
        rank++;
        if (v[i].score == v[i - 1].score){
            printf("%d %s %d %d\n",lastrank, v[i].s.c_str(), v[i].score, v[i].cnt);
        }
        else {
            printf("%d %s %d %d\n",rank, v[i].s.c_str(), v[i].score, v[i].cnt);
            lastrank = rank;
        }
    }
    return 0;
}
//可以 25分 lastrank 比较关键！！