class Solution {
public:
    int rec(string& s, string& t, int n, int m, vector<vector<int>>& dp) {
        if(m == -1) return 1;
        if(n == -1) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n]==t[m]) return dp[n][m] = ( rec(s, t, n-1, m-1, dp) + rec(s, t, n-1, m, dp));
        
        return dp[n][m] = rec(s, t, n-1, m, dp);
    }
        
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int> (m+1, 0));
        
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
                else if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][m];
    }
};