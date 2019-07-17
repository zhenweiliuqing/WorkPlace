//DP 最大子序列和
#include <iostream>
using namespace std;
int DP[10010];//存储目前子列和的最大值
int x[10010];
int main()
{
    int n;
    int sum = 0;
    int max = 0;
    int st = 0, end = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x[i];
        if ((sum + x[i]) > 0){
            sum += x[i];
        }
        else {
            sum = 0;
        }
        DP[i] = sum;
        if (sum > max){
            max = sum;
            end = i;
        }
    }
    //想到一个办法 从后往前推
    for (int i = end;;i--){
        if (DP[i] == 0){
            st = i + 1;
            break;
        }
    }
    if (max == 0)
        printf("%d %d %d", 0, x[0], x[n - 1]);
    else
        printf("%d %d %d", max, x[st], x[end]);
    return 0;
}
//第一次只对了一个测试点 
//应该是输出内容 不是下标 修改了一下 并加上了全是0 的情况 第二次 22分

//参考答案

#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n, flag = 0, sum = -1, temp = 0, left = 0, right = 0, tempindex = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if(v[i] >= 0)
            flag = 1;
        temp = temp + v[i];
        if(temp > sum) {
            sum = temp;
            left = tempindex;
            right = i;
        } else if(temp < 0) {
            temp = 0;
            tempindex = i + 1;
        }
    }
    if(flag == 0)
        printf("0 %d %d", v[0], v[n - 1]);
    else
        printf("%d %d %d", sum, v[left], v[right]);
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        temp = temp + v[i];
        if (temp < 0) {
            temp = 0;
            tempindex = i + 1;
        } else if (temp > sum) {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if (sum < 0) sum = 0;
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}