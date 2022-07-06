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
    void fun(TreeNode* root, vector<string>& s, string tm) {
        if(root == NULL) return;
        if(root->right == NULL && root->left == NULL) {
            string temp = tm;
            temp.push_back(char(root->val + 97));
            reverse(temp.begin(), temp.end());
            s.push_back(temp);
            return;
        }
        
        tm += (char(root->val + 97));
        fun(root->left, s, tm);
        fun(root->right,s, tm);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> s;
        
        fun(root, s, "");
        sort(s.begin(), s.end());
        // if(s[0].size()==1 and s.size()>1) return s[1]; 
        for(auto it : s) cout<<it<<" ";
        return s[0];
    }
};