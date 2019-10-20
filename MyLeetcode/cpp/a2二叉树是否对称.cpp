#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {

        queue<TreeNode**> stack;
        TreeNode* p[2] = {root, root};
        TreeNode** pp = p;
        stack.push(pp);
        TreeNode *t[2];
        while (!stack.empty())
        {
            t[0] = stack.front()[0];
            t[1] = stack.front()[1];
            
            stack.pop();
            if ((t[0] != NULL && t[1] == NULL) || (t[0] == NULL && t[1] != NULL))
            {
                return false;
            }
            if (t[0] == NULL && t[1] == NULL)
            {
                continue;
            }
            if (t[0]->val != t[1]->val)
            {
                return false;
            }

            TreeNode* r[2] = {t[0]->left, t[1]->right};
            TreeNode** r2 = r;
            stack.push(r);
            TreeNode *s[2] = {t[0]->right, t[1]->left};
            TreeNode** s2 = s;
            stack.push(s);
        }
        return true;
    }
};

int main()
{
    TreeNode n1;
    TreeNode n2;
    TreeNode n3;
    TreeNode n4;
    TreeNode n5;
    n1.val = 1;
    n2.val = 2;
    n3.val = 2;
    n4.val = 3;
    n5.val = 3;
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.right = &n5;
    Solution sol;
    cout << 1 << endl;
    cout << sol.isSymmetric(&n1) << endl;


    int a = 1;
    int* b = &a;
    int* c[2] = {b,b};
    int** d = c;


    getchar();
    return 0;
}