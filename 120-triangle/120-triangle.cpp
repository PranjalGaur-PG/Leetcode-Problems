class Solution {
public:
    int fun(vector<vector<int>>& tri, int i, int j, int n, vector<vector<int>>& dp) {
        if(i == n-1) return tri[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = fun(tri, i+1, j, n, dp);
        int b = fun(tri, i+1, j+1, n, dp);
        
        return dp[i][j] = tri[i][j] + min(a, b);
    }
    
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(tri, 0, 0, n, dp);
    }
};