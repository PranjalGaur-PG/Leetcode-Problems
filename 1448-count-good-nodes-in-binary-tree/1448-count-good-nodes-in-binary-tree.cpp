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
    int goodNodes(TreeNode* root, int pre = -1e5) {
        if(!root) return 0;
        int value = root->val;
        
        if(value >= pre) return (1 + goodNodes(root->left, value) + goodNodes(root->right, value));
        
        return (goodNodes(root->left, pre) + goodNodes(root->right, pre));
    }
};