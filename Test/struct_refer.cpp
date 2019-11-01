#include <iostream>
using namespace std;
struct node{
    int a, b;
};
node m_node[2];
void func(int a, int b){
    a = 2;
    b = 2;
}
void func_1(node& a)
{
    a.a = 2;
    a.b = 2;
}
int main()
{
    node& node_1 = m_node[0];
    node_1.a = 1;
    node_1.b = 1;
    func(node_1.a, node_1.b);
    func_1(node_1);
    cout << node_1.a << " " << node_1.b;
    return 0;
}