/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Time:O(min(n,m)), Space:O(min(n,m))
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if((p!=0)^(q!=0))
      {
          return 0;
      }
    if(p)
    {
        return p->val==q->val and isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }
    else return 1;
        
    }
};