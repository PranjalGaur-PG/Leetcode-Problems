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
    static bool srt(pair<int, int> p1, pair<int, int> p2) {
        if(p1.second != p2.second) return p1.second < p2.second;
        return p1.first < p2.first;
    }
        
    map<int, vector<pair<int, int>>> mp;
    
    void rec(TreeNode* root, int dis, int depth) {
        if(!root) return ;
        
        mp[dis].push_back({root->val, depth});
        
        rec(root->left , dis-1, depth+1);
        rec(root->right, dis+1, depth+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        rec(root, 0, 0);
        
        for(auto it : mp) {
            
            sort(it.second.begin(), it.second.end(), srt);
            
            vector<int> temp;
            for(auto it2 : it.second) temp.push_back(it2.first);
            ans.push_back(temp);
        }
        
        return ans;
    }
};