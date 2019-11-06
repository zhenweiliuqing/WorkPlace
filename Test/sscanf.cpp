#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    char b[50];
    double temp;
    char a[] = "1s2345";
    // scanf("%s", a);
    sscanf(a, "%lf", &temp);
    sprintf(b, "%.2f", temp);
    cout << temp << endl;
    cout << b << endl;
}