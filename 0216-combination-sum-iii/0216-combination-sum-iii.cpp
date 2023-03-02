class Solution {
public:
    void rec(int i, vector<int> temp, vector<vector<int>>& ans, int n, int k) {
        if(i>9) {
            if(!k && !n) {
                ans.push_back(temp);
            }
            return;
        }
        
        rec(i+1, temp, ans, n, k);
        temp.push_back(i);
        rec(i+1, temp, ans, n-i, k-1);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        
        rec(1, temp, ans, n, k);
        return ans;
    }
};