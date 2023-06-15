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
    int maxLevelSum(TreeNode* root) {
        int ans, lev = 1, mxsum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            int sum = 0;
            int sz = q.size();
            
            while(sz--) {
                TreeNode* tp = q.front();
                q.pop();
                sum += tp->val;
                
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
            }
            
            if(sum > mxsum) {
                ans = lev;
                mxsum = sum;
            }
            lev++;
        }
        
        return ans;
    }
};