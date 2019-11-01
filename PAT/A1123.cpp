//2019-9-4
//思路：建立一棵树 有几个关键的函数今天先写好
//insert left/rightrotate  getHeight

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int data;
    struct node *left, *right;
};

node* rightRotate(node* tree) {
    node *temptree = tree->left;
    tree->left = temptree->right;
    temptree->right = tree;
    return temptree;
}

node* leftRotate(node* tree) {
    node *temptree = tree->right;
    tree->right = temptree->left;
    temptree->left = tree;
    return temptree;
}

node* leftrightRotate(node* tree) {
    tree->left = leftRotate(tree->left);
    return rightRotate(tree);
}

node* rightleftRotate(node* tree) {
    tree->right = rightRotate(tree->right);
    return leftRotate(tree);
}

int getHeight(node* tree) {
    if (tree == NULL)
        return 0;
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    return max(l, r) + 1;
}

node* insert(node *tree, int data) {
    if (tree == NULL) {
        tree = new node();
        tree->data = data;
        tree->left = tree->right = NULL;
    } else if (data <= tree->data) {
        tree->left = insert(tree->left, data);
    } else if (data > tree->data) {
        tree->right = insert(tree->right, data);
    }
    
    int left = getHeight(tree->left);
    int right = getHeight(tree->right);
    if (left - right >= 2) {
        if (data <= tree->left->data)//一顺
            tree = rightRotate(tree);
        else if (data > tree->left->data)//一拐
            tree = leftrightRotate(tree);
    }
    else if (right - left >= 2) {
        if (data > tree->right->data)
            tree = leftRotate(tree);
        else if (data <= tree->right->data)
            tree = rightleftRotate(tree);
    }
    return tree;
}

int main(){
    int n, temp;
    cin >> n;
    node *Tree = NULL;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        Tree = insert(Tree, temp);
    }
    //接下来就判断是否是完全二叉树和输出就完了
    //2019-9-7
    bool isComplete = false;
    int cnt = 0;
    queue<node*> q;
    q.push(Tree);
    printf("%d", Tree->data);
    while (!q.empty()) {
        node *temp = q.front();
        q.pop();
        cnt++;
        if (temp->left == NULL || temp->right == NULL){
            if ((cnt + q.size()) == n)
                isComplete = true;
            cnt = 0;
        }
        if (temp->left != NULL) {
            q.push(temp->left);
            printf(" %d", temp->left->data);
        }
        if (temp->right !=  NULL) {
            q.push(temp->right);
            printf(" %d", temp->right->data);
        }
    }
    if (isComplete)
        cout << "\nYES";
    else
        cout << "\nNO";
    return 0;
}
//部分正确 26分 答案错误一个测试点 是什么边缘情况？