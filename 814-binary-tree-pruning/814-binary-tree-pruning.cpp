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
    pair<TreeNode* , bool>  Solve(TreeNode * root)
    {
        if(!root)
            return {NULL , false};
        
        pair<TreeNode* , bool> left = Solve(root->left);
        pair<TreeNode* , bool> right = Solve(root->right);
        
        root->left = left.first;
        root->right = right.first;
        
        if(!left.second && !right.second)
        {
            if(root->val == 0)
            return {NULL, false}; 
        }
        return {root, true};
        
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        
       pair<TreeNode* , bool> ans  = Solve(root);
        return ans.first;
        
		
		// Pls Upvote IF You Like It
    }
};