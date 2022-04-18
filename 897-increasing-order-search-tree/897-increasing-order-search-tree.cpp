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
    void fun(TreeNode* root, vector<int> &a) {
        if(root == NULL) return;
        
        fun(root->left, a);
        a.push_back(root->val);
        fun(root->right, a);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> a;
        fun(root, a);
        
        TreeNode* temp = new TreeNode();
        TreeNode* temp1= temp;
        for(auto it : a) {
            TreeNode* t1 = new TreeNode(it);
            temp1->right = t1;
            temp1 = temp1->right;
        }
        return temp->right;
        
    }
};