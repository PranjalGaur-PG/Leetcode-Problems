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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            int n = q.size();
            int sz = n;
            double sum = 0.0;
            while(n--) {
                TreeNode* f = q.front();
                q.pop();
                sum += f->val;
                
                if(f->left != NULL) q.push(f->left );
                if(f->right!= NULL) q.push(f->right);
                
            }
            ans.push_back(sum/sz);
        }
        return ans;
    }
};