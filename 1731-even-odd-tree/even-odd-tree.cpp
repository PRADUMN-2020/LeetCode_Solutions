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
    bool isEvenOddTree(TreeNode* root) {
        //Time:O(n), Space:O(n)
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int nodes=1;
        while(q.size())
        {
            int prev=level%2?INT_MAX:0;
            int cur=0;
            for(int i=0;i<nodes;i++)
            {
            TreeNode*curr=q.front();
            q.pop();
            cur=curr->val;
            if(level%2==0)
            {
               if(cur%2==0 or cur<=prev)
               {
                   return 0;
               }
               
            }
            else
            {
                if(cur%2 or cur>=prev)
                {
                    return 0;
                }
            }
                prev=cur;
                           
            
            if(curr->left)
                q.push(curr->left);
             if(curr->right)
                q.push(curr->right);
            
            }
            level++;
            nodes=q.size();
        }
        return true;
        
    }
};