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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        
        while(q.size()) {
            int n=q.size();
            vector<int> temp;
            while(n--) {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left  != NULL) q.push(t->left );
                if(t->right != NULL) q.push(t->right);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};