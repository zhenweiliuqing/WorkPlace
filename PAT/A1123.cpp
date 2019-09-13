// //just copy
// //2018-8-10 22:56

// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;
// struct node
// {
//     int val;
//     struct node *left, *right;
// };

// node* leftRotate(node *tree)
// {
//     node *temp = tree->right;
//     tree->right = temp->left;
//     temp->left = tree;
//     return temp;
// }

// node* rightRotate(node *tree)
// {
//     node *temp = tree->left;
//     tree->left = temp->right;
//     temp->right = tree;
//     return temp;
// }

// node* leftRightRotate(node *tree)
// {
//     tree->left = leftRotate(tree->left);
//     return rightRotate(tree);
// }

// node* rightLeftRotate(node *tree)
// {
//     tree->right = rightRotate(tree->right);
//     return leftRotate(tree);
// }

// int getHeight(node *tree)
// {
//     if (tree == NULL)
//         return 0;
//     int l = getHeight(tree->left);
//     int r = getHeight(tree->right);
//     return max(l, r) + 1;
// }

// node* insert(node *tree,int val)
// {
//     if (tree == NULL)
//     {
//         tree = new node();//??? 不加括号应该也没事
//         tree->val = val;
//     }
//     else if (tree->val > val)
//     {
//         tree->left = insert(tree->left, val);
//         int l = getHeight(tree->left), r = getHeight(tree->right);
//         if (l - r >= 2)
//         {
//             if (val < tree->left->val)
//                 tree = rightRotate(tree);
//             else
//                 tree = leftRightRotate(tree);
//         }
//     }
//     else
//     {
//         tree->right = insert(tree->right, val);
//         int l = getHeight(tree->left), r = getHeight(tree->right);
//         if (r - l >= 2)
//         {
//             if (val > tree->right->val)
//                 tree = leftRotate(tree);//直接操作的地址 回来地址都被改了 不管父母也行啊
//             else
//                 tree = rightLeftRotate(tree);
//         }
//     }

//     return tree;
// }

// int isComplete = 1, after = 0;
// vector<int> levelOrder(node *tree)
// {
//     vector<int> v;
//     queue<node *> queue;
//     queue.push(tree);
//     while (!queue.empty())
//     {
//         node *temp = queue.front();
//         queue.pop();
//         v.push_back(temp->val);

//         if (temp->left != NULL)
//         {
//             if (after == 1)
//                 isComplete = 0;
//             queue.push(temp->left);
//         }
//         else 
//         {
//             after = 1;
//         }

//         if (temp->right != NULL)
//         {
//             if (after == 1)
//                 isComplete = 0;
//             queue.push(temp->right);
//         }
//         else 
//         {
//             after = 1;
//         }
//     }

//     return v;
// }

// int main()
// {
//     int n, temp;
//     scanf("%d", &n);
//     node *tree = NULL;//因为初始化了 所以必须使用返回值重新赋值
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &temp);
//         tree = insert(tree, temp);//这个tree一直是头节点嘛？
//     }

//     vector<int> v = levelOrder(tree);
//     for (int i = 0; i < v.size(); i++)
//     {
//         if (i != 0)
//             printf(" ");
//         printf("%d", v[i]);
//     }
//     printf("\n%s", isComplete ? "YES" : "NO");
    
//     return 0;
// }
// //学会如何构建一棵树

//2019-9-2
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    
}