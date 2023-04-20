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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        unsigned long long ans = 1;
        q.push({root, 1});
        
        while(q.size()) {
            int sz = q.size();
            unsigned long long mx = q.front().second;
            unsigned long long mn = mx;
            while(sz--) {
                TreeNode* temp = q.front().first;
                unsigned long long val = q.front().second;
                
                q.pop();
                mx = max(mx, val);
                mn = min(mn, val);
                
                ans = max(mx-mn+1, ans);
                // cout<<ans<<" ";
                
                if(temp->left ) q.push({temp->left, 2*val});
                if(temp->right) q.push({temp->right,2*val+1});
            }
        }
        
        return ans;
    }
};