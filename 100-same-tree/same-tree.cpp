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
    void pre(TreeNode* root,vector<int>&preorder)
    {
        
        if(root)
        {
            preorder.push_back(root->val);
            pre(root->left,preorder);
            pre(root->right,preorder);
        }
        else
        {
           preorder.push_back(-1);         
        }
    }
    
    
    void in(TreeNode* root,vector<int>&inorder)
    {
        if(root)
        {
            in(root->left,inorder);
            inorder.push_back(root->val);
            in(root->right,inorder);
        }
        else
        {
            inorder.push_back(-1);
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Time:O(n+m), Space:O(n+m)
        vector<int>inorder1;
        vector<int>preorder1;
        vector<int>inorder2;
        vector<int>preorder2;
        pre(p,preorder1);
         pre(q,preorder2);
        in(p,inorder1);
        in(q,inorder2);
        return inorder1==inorder2 and preorder1==preorder2;
        
    }
};