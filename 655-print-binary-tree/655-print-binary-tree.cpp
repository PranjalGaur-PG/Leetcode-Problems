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
    int high(TreeNode* root) {
        if(!root) return 0;
        
        return 1 + max(high(root->left), high(root->right));
    }
    
    void fill(vector<vector<string>>& ans, TreeNode* root, int r, int c, int h){
        if(!root) return;
        
        ans[r][c] = to_string(root->val);
        
        fill(ans, root->left, r + 1, c - pow(2, h - r - 1), h);
        fill(ans, root->right, r + 1, c + pow(2, h - r - 1), h);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int n = high(root);
        int m = pow(2,n)-1;
        
        vector<vector<string>> ans(n, vector<string> (m, ""));
        fill(ans, root, 0, (m-1)/2, n-1);
        
        return ans;
    }
};