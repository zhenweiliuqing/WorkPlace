//2019-9-4
#include <iostream>
using namespace std;
#define DECLARE_HANDLE(name) struct name##_{int t;}; typedef struct name##_ *name
DECLARE_HANDLE(TEST);
TEST test = nullptr;
typedef struct node{
    int x;
} * Node;
int main(){
    //花里胡哨的声明
    test = new TEST_();
    test->t = 5;
    cout << "dd" << endl;
    //typedef将node 变成 Node指针
    Node temp = NULL;
    temp = new node;
    temp->x = 5;
    cout << temp->x << endl;
    //node指针声明
    node *tt = nullptr;
    tt = new node();
    tt->x = 6;
    cout << tt->x << endl;
    return 0;
}