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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool rev = false;
        
        if(!root) return ans;
        q.push(root);
        
        while(q.size()) {
            vector<int> temp;
            int sz = q.size();
            
            while(sz--) {
                TreeNode* t = q.front();
                q.pop();
                
                temp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            
            if(rev) reverse(temp.begin(), temp.end());
            rev = !rev;
            ans.push_back(temp);
        }
        
        return ans;
    }
};