//2019-9-21
#include <iostream>
#include <vector>
using namespace std;
vector<double> v;
int n;
double sum = 0.0;

int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1, j = n; i <= n, j >= 1; i++, j--) {
        sum += v[i] * i * j;
    }
    printf("%.2f", sum);
    return 0;
}
//满分 float 15分 double 满分！！！