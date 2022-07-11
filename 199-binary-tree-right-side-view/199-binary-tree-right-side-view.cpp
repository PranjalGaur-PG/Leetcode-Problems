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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            int n = q.size();
            int value;
            
            while(n--) {
                TreeNode* temp = q.front();
                q.pop();
                
                value = temp->val;
                if(temp->left != NULL) q.push(temp->left );
                if(temp->right!= NULL) q.push(temp->right);
            }
            
            ans.push_back(value);
        }
        
        return ans;
    }
};