#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <map>
using namespace std;
class TreeNode{
   public:
   int val;
   TreeNode *left = NULL;
   TreeNode *right = NULL;
};
// struct TreeNode
// {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
public:
   int s = -9999999999999;
   void fun(TreeNode *node)
   {
      if (node == NULL)
      {
         return;
      }
      fun(node->left);
      fun(node->right);      
      if(node->left && node->right){
         this->s = max(this->s, max(node->left->val, 0) + max(node->right->val,0) + node->val);
         node->val += max(max(node->left->val, node->right->val), 0);
      }
      else if (node->left)
      {
         this->s = max(this->s, max(node->left->val,0) + node->val);
         node->val += max(node->left->val, 0);
      }
      else if (node->right)
      {
         this->s = max(this->s, max(node->right->val,0) + node->val);
         node->val += max(node->right->val, 0);
      }
      else{
         this->s = max(this->s, node->val);
      }
      return;
   }
   int maxPathSum(TreeNode *root)
   {
      fun(root);
      return s;
   }
};

int main(void)
{
   TreeNode n0,n1,n2;
   n0.val = 1;
   n1.val = 2;
   n2.val = 3;
   n0.left = &n1;
   n0.right = &n2;
   Solution sol;

   cout<< sol.s<<endl;
   cout<< sol.maxPathSum(&n0)<<endl;


   getchar();
}
