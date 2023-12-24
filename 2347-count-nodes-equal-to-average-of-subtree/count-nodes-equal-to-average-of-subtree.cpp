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
    int nodeSum(TreeNode*root)
    {  
       if(root)
       {
       return root->val+nodeSum(root->left)+nodeSum(root->right);  
       }
        else
        {
            return 0;
        }
    }
    int nodeCount(TreeNode*root)
    {  
       if(root)
       {
       return 1+nodeCount(root->left)+nodeCount(root->right);  
       }
        else
            return 0;
    }
    int averageOfSubtree(TreeNode* root) {
        if(root)
        {
        int leftSum=nodeSum(root->left);
        int rightSum=nodeSum(root->right);
        int leftCount=nodeCount(root->left);
        int rightCount=nodeCount(root->right);
        int average=(leftSum+rightSum+root->val)/(1+leftCount+rightCount);
        int countThis=0;
        countThis=(average==root->val);
        return countThis+averageOfSubtree(root->left)+averageOfSubtree(root->right);
        }
        else
        {
        return 0;
        }
    }
};