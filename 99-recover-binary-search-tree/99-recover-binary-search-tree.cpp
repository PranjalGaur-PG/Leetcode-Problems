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
    TreeNode* f = 0;
    TreeNode* s = 0;
    TreeNode* pre = new TreeNode(INT_MIN);
    
    void fun(TreeNode* root) {
        if(!root) return;
        
        fun(root->left);
        if(root->val < pre->val && f==NULL) f = pre; 
        if(root->val < pre->val && f!=NULL) s = root;
        
        pre = root;
        fun(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        
        fun(root);
        swap(f->val, s->val);
    }
};