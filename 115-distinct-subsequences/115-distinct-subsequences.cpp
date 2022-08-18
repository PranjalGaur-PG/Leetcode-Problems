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
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return rec(s, t, n-1, m-1, dp);
    }
};