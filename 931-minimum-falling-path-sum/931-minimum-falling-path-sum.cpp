class Solution {
public:
    int rec(vector<vector<int>>& mat, vector<vector<int>>& dp, int c, int r, int n) {
        if(r == n-1) return mat[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        
        int left = INT_MAX, right;
        if(c>0) left = rec(mat, dp, c-1, r+1, n);
        int down = rec(mat, dp, c  , r+1, n);
        if(c<n-1) right = rec(mat, dp, c+1, r+1, n);
        
        int mn = min(down, min(left, right));
        return dp[r][c] = (mat[r][c] + mn);
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int ans = INT_MAX;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==0) dp[i][j] = mat[i][j];
                else {
                    int u = dp[i-1][j];
                    int l = INT_MAX, r = INT_MAX;
                    if(j>0) l = dp[i-1][j-1];
                    if(j<n-1) r=dp[i-1][j+1];
                    
                    dp[i][j] = min(u, min(l, r)) + mat[i][j];
                }
                
                if(i==n-1) ans = min(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};