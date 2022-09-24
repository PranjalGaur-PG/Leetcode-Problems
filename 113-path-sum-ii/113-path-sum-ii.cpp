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
    void solve(TreeNode* root,vector<int> &temp,vector<vector<int>> &ans,int &sum,int target) {
        if(root == NULL) {
            return;
        }
        
        sum += root->val;
        temp.push_back(root->val);
        
        if(!root->left && !root->right) {
            if(sum == target) ans.push_back(temp);
        }
        
        solve(root->left ,temp,ans,sum,target);
        solve(root->right,temp,ans,sum,target);
        
        sum -= root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum =0;
        solve(root,temp,ans,sum,target);
        return ans;
    }
};