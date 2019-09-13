//对于A1135的疑问 我不是传的是指针吗？
#include <iostream>
struct node {
    int v;
    struct node *left, *right;
};
using namespace std;
node* build(node* root) {
    if (root == NULL){
        root = new node;
        root->left = root->right = NULL;
        root->v = 2;
    }else {
        root->left = root->right = NULL;
        root->v = 2;
    }
    return root;
}
void ref_build(node& root) {
    root.left = root.right = NULL;
    root.v = 5;
}
int main() {
    node *root = NULL;
    build(root);
    //node root = {2,NULL,NULL};
    //ref_build(root);
    return 0;
}
//node *root= {};相当于 *root = NULL
//如果不对root进行初始化就是野指针 这样就可以改变了 
//因为进行初始化了 所以得进行赋值 否则在主函数里还是NULL 没有得到调用函数的变化

//要是引用会如何
//引用可以啊 直接就可以改变 只需要在函数里的形参加个&就可以了
//现在是进行初始化了 不进行初始化也没什么事
