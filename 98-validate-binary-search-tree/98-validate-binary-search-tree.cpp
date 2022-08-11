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
    void inOrder(TreeNode* root,vector<int> & arr) {
        if(!root) return;
        
        inOrder(root->left,arr);
        arr.push_back(root->val);
        inOrder(root->right,arr);
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        vector<int> arr;
        inOrder(root,arr);
        
        for(int i=1;i<arr.size();i++) {
            if(arr[i]<=arr[i-1]) return false;
        }
        return true;
    }
};